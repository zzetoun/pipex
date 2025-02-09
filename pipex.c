/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:33:45 by zzetoun           #+#    #+#             */
/*   Updated: 2025/01/11 19:33:45 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	int		i;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (ft_freedom(pipex, 1), EXIT_FAILURE);
	setup_pipex(pipex);
	if (!ft_parse(pipex, ac, av))
		return (ft_freedom(pipex, 1), EXIT_FAILURE);
	if (!parse_cmd_paths(pipex, ac, av, env))
		return (ft_freedom(pipex, 1), ft_error(EARGS));
	if (!parse_cmd_args(pipex, ac, av))
		return (ft_freedom(pipex, 1), ft_error(EARGS));
	i = -1;
	while (++i < pipex->cmd_num)
		if (!ft_child(pipex, env, i))
			return (ft_freedom(pipex, 1), ft_error(EUNKN));
	i = -1;
	while (++i < pipex->cmd_num)
		wait(NULL);
	ft_freedom(pipex, 1);
	return (0);
}
