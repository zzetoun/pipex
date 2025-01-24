/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_uti_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:41:50 by zzetoun           #+#    #+#             */
/*   Updated: 2025/01/23 17:42:31 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void do_fork()
{
	pid_t   cpid;
	int		fd[2];

	cpid = fork();
	if (cpid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
	{
		close(fd[0]);
		write(1,"1\n",2);
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
    } 
    else
    {
		wait(NULL);
		exit(EXIT_SUCCESS);
     }
}

static char **get_path(char **env)
{
	if (env && *env)
	{
		while(*env && ft_strncmp(*env, "PATH=", 5) != 0)
			env++;
		if(*env)
			return ft_split(*env + 5, ':');
	}
	return NULL;
}

int	check_file(char **av)
{
	return 3;
}
int	check_cmd(char **av)
{
	return 2;
}

int	ft_validate(char **av, int ac)
{
	int	status;
	
	if(!av)
		return 0;
	while(av)
	{
		status = check_file(av);
		status += check_cmd(av);
	}
	return status;
}
void ft_outfile(void)
{

}

void ft_infile(void)
{

}
void do_pipe(void)
{

}