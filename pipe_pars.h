/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pars.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:37:26 by zzetoun           #+#    #+#             */
/*   Updated: 2025/01/27 13:37:26 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_PARS_H
# define PIPE_PARS_H

# include "s_pipex.h"

void	pipe_here_doc(t_pipex *pipex, char **av);
void	read_here_doc(t_pipex *pipex, char **av, int *fd);
void	pipe_infile(t_pipex *pipex, char **av);
void	pipe_outfile(t_pipex *pipex, char **av, int ac);

int		ft_parse(t_pipex *pipex, int ac, char **av);
int		parse_cmd_paths(t_pipex *pipex, int ac, char **av, char **env);
int		parse_cmd_args(t_pipex *pipex, int ac, char **av);

char 	*find_path(char *cmd, char **env);
char	**get_path(char **env);
char	*get_env(char *c, char **env);
int		ft_error(char *error);

#endif