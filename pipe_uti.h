/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_uti.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:12:07 by zzetoun           #+#    #+#             */
/*   Updated: 2025/02/02 18:38:24 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_UTI_H
# define PIPE_UTI_H

# include "pipex.h"

void	setup_pipex(t_pipex *pipex);
int		ft_fork_pipe(t_pipex *pipex, int fd[2], pid_t *pid, int idx);
int		ft_child(t_pipex *pipex, char **envp, int idx);

#endif
