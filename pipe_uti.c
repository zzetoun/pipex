/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_uti.c                                      	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:41:50 by zzetoun           #+#    #+#             */
/*   Updated: 2025/01/29 18:10:53 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_pipex(t_pipex *pipex)
{
	pipex->infd = -1;
	pipex->outfd = -1;
	pipex->here_doc = 0;
	pipex->invalid_input = 0;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_num = 0;
}

char **get_path(char **env)
{
	char	*path;

	path = get_env("PATH", env);
	if (!path)
		return (NULL);
	return (ft_split(path, ':'));
}

char	*get_env(char *c, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (ft_strncmp(c, env[i], ft_strlen(c)) == 0
			&& env[i][ft_strlen(c)] == '=')
			return (ft_strchr(env[i], '=') + 1);
	return (NULL);
}

char *find_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*path;
	char	*full_path;

	if (access(cmd, F_OK) == 0)
		return (ft_substr(cmd, 0, ft_strlen(cmd)));
	paths = get_path(env);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/", 0);
		if (!path)
			return (ft_free_array(paths, -1), NULL);
		full_path = ft_strjoin(path, cmd, 0);
		if (!full_path)
			return (ft_free_array(paths, -1), NULL);
		if (access(full_path, F_OK) == 0)
			return (ft_free_array(paths, -1), full_path);
		free(full_path);
	}
	return (ft_free_array(paths, -1), NULL);
}

int	ft_fork_pipe(t_pipex *pipex, int fd[2], pid_t *pid, int idx)
{
	if (pipe(fd) == -1)
		return (0);
	*pid = fork();
	if (*pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (0);
	}
	if (*pid == 0)
	{
		if (idx == 0)
			dup2(pipex->infd, STDIN_FILENO);
		if (idx == pipex->cmd_num - 1)
			dup2(pipex->outfd, STDOUT_FILENO);
		else
			dup2(fd[1], STDOUT_FILENO);
	}
	else
		dup2(fd[0], STDIN_FILENO);
	return (1);
}

int	ft_child(t_pipex *pipex, char **envp, int idx)
{
	pid_t	pid;
	int		fd[2];

	if (!ft_fork_pipe(pipex, fd, &pid, idx))
		return (0);
	if (pid == 0)
	{
		if (pipex->cmd_paths[idx])
			execve(pipex->cmd_paths[idx], pipex->cmd_args[idx], envp);
		else
			ft_printf(2, "pipex: %s: command not found\n",
				pipex->cmd_args[idx][0]);
		ft_freedom(pipex, 1);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(fd[1]);
		close(fd[0]);
	}
	return (1);
}