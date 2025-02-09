/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:41:45 by zzetoun           #+#    #+#             */
/*   Updated: 2025/02/09 18:11:42 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		ft_close_fd(fd);
		perror("here_doc: fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		read_here_doc(pipex, av, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		wait(NULL);
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
		if (access(av[1], F_OK | R_OK) == -1)
		{
			perror("pipex in file");
			pipex->in_invalid = -1;
		}
		else
			pipex->infd = open(av[1], O_RDONLY);
	}
}

void	pipe_outfile(t_pipex *pipex, char **av, int ac)
{
	int	flags;

	if (pipex->here_doc == 1)
		flags = O_RDWR | O_CREAT | O_APPEND;
	else
		flags = O_RDWR | O_CREAT | O_TRUNC;
	pipex->outfd = open(av[ac - 1], flags, 0644);
	if (pipex->outfd == -1)
	{
		perror("pipex out file");
		pipex->out_invalid = -1;
	}
}
