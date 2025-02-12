/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:36:28 by zzetoun           #+#    #+#             */
/*   Updated: 2025/02/12 11:41:18 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_cmd_paths(t_pipex *pipex, int ac, char **av, char **envp)
{
	int		i;
	char	**cmd;

	pipex->cmd_paths = malloc((ac - 2 - pipex->here_doc) * sizeof(char *));
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
		pipex->cmd_paths[i - 2 - pipex->here_doc] = find_path(cmd[0], envp);
		ft_free_array(cmd, -1);
	}
	return (1);
}

int	parse_cmd_args(t_pipex *pipex, int ac, char **av)
{
	int		i;

	pipex->cmd_args = malloc(sizeof(char **) * (ac - 2 - pipex->here_doc));
	if (!pipex->cmd_args)
		return (0);
	i = 1 + pipex->here_doc;
	while (++i < ac - 1)
	{
		pipex->cmd_args[i - 2 - pipex->here_doc] = ft_split(av[i], ' ');
		if (!pipex->cmd_args[i - 2 - pipex->here_doc])
		{
			ft_free_2d_array(pipex->cmd_args, pipex->cmd_num);
			pipex->cmd_args = NULL;
			return (0);
		}
	}
	return (1);
}

int	ft_parse(t_pipex *pipex, int ac, char **av)
{
	if (av[1] && ft_strncmp(av[1], "here_doc", 8) == 0
		&& ft_strlen(av[1]) == 8)
		pipex->here_doc = 1;
	if (ac < 5 + pipex->here_doc)
	{
		ft_printf(2, "pipex: error: invalid arguments Number\n");
		return (0);
	}
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
