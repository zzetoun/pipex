/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:36:56 by zzetoun           #+#    #+#             */
/*   Updated: 2025/01/11 19:36:56 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include "ft_printf.h"
# include "str_uti.h"

# define EARGS "error: invalid arguments"
# define EUNKN "error: unknown error"
# define ECFND "error: command not found"
# define ENOENT "error: no such file or directory"

typedef struct s_pipex
{
	int		infd;
	int		outfd;
	int		here_doc;
	int		invalid_input;
	int		urandom;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
}	t_pipex;

void	ft_init_pipex(t_pipex *pipex);
void do_fork();
char **get_path(char **env);
void pipe_file(char *av, int i);

#endif