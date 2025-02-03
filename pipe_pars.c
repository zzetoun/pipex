/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:36:28 by zzetoun           #+#    #+#             */
/*   Updated: 2025/02/02 20:12:31 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_cmd_paths(t_pipex *pipex, int ac, char **av, char **env)
{
	int		i;
	char	**cmd;

	pipex->cmd_paths = malloc(sizeof(char *) * (ac - 2 - pipex->here_doc));
	if (!pipex->cmd_paths)
		return (0);
	i = 1 + pipex->here_doc;
	while (++i < ac - 1)
	{
		cmd = ft_split(av[i], ' ');
		if (!cmd)
		{
			ft_free_array(pipex->cmd_paths, i - 2 - pipex->here_doc);
			pipex->cmd_paths = NULL;
			return (0);
		}
		pipex->cmd_paths[i - 2 - pipex->here_doc] = find_path(cmd[0], env);
		ft_free_array(cmd, -1);
	}
	return (1);
}

int	parse_cmd_args(t_pipex *pipex, int argc, char **argv)
{
	int		i;
	char	**cmd;

	pipex->cmd_args = malloc(sizeof(char **) * (argc - 2 - pipex->here_doc));
	if (!pipex->cmd_args)
		return (0);
	i = 1 + pipex->here_doc;
	while (++i < argc - 1)
	{
		cmd = ft_split(argv[i], ' ');
		if (!cmd)
		{
			ft_free_2d_array(pipex->cmd_args, pipex->cmd_num);
			pipex->cmd_args = NULL;
			return (0);
		}
		pipex->cmd_args[i - 2 - pipex->here_doc] = cmd;
	}
	return (1);
}

void	pipe_here_doc(t_pipex *pipex, char **av)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		perror("here_doc: pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("here_doc: fork");
		exit(EXIT_FAILURE);
	}
	if (!pid)
		read_here_doc(pipex, av, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		wait(NULL);
	}
}

void	read_here_doc(t_pipex *pipex, char **av, int *fd)
{
	char	*doc;

	free(pipex);
	close(fd[0]);
	ft_printf(1, "here_doc >: ");
	while (1)
	{
		doc = get_next_line(STDIN_FILENO);
		if (!doc || ft_strncmp(doc, av[2], ft_strlen(doc) - 1) == 0)
		{
			if (doc)
			{
				free(doc);
				get_next_line(-1);
			}
			close(fd[1]);
			exit(EXIT_SUCCESS);
		}
		ft_printf(fd[1], "%s", doc);
		free(doc);
	}
}

void	pipe_infile(t_pipex *pipex, char **av)
{
	if (pipex->here_doc)
	{
		pipe_here_doc(pipex, av);
		pipex->infd = STDIN_FILENO;
	}
	else
	{
		if (access(av[1], F_OK) == -1)
		{
			perror("invalid access");
			pipex->invalid_input = 1;
		}
			pipex->infd = open(av[1], O_RDONLY);
	}
}

void	pipe_outfile(t_pipex *pipex, char **av, int ac)
{
	if (pipex->here_doc)
		pipex->outfd = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		pipex->outfd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
}

int	ft_parse(t_pipex *pipex, int ac, char **av)
{
	if (av[1] && ft_strncmp(av[1], "here_doc", 8) == 0
		&& ft_strlen(av[1]) == 8)
	pipex->here_doc = 1;
	if (ac < 5 + pipex->here_doc)
		return (0);
	pipe_infile(pipex, av);
	pipe_outfile(pipex, av, ac);
	pipex->cmd_num = ac - 3 - pipex->here_doc;
	return (1);
}
int	ft_error(char *error)
{
	ft_printf(2, "pipex: %s\n", error);
	exit(EXIT_FAILURE);
	return (1);
}