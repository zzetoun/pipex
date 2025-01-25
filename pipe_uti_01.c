/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_uti_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:41:50 by zzetoun           #+#    #+#             */
/*   Updated: 2025/01/25 16:09:47 by zzetoun          ###   ########.fr       */
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

char **get_path(char **env)
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

//int	check_cmd(char **av)
//{
//	return 2;
//}

//int	ft_validate(char **av, int ac)
//{
//	int	status;
	
//	if(!av)
//		return 0;
//	while(av)
//	{
//		status = check_file(av);
//		status += check_cmd(av);
//	}
//	return status;
//}
void pipe_file(char *av, int i)
{
	if (i == 1 && ft_strncmp(av, "here_doc", 8) == 0)
		ft_printf(STDOUT_FILENO, "I am here_doc\n");
	else if (access(av, F_OK) == -1 && i == 1)
		ft_printf(STDERR_FILENO, "zsh: no such file or directory: %s\n", av);
	else if (access(av, R_OK) == -1 && i == 1)
		ft_printf(STDERR_FILENO, "zsh: permission denied: %s\n", av);
	else if (access(av, F_OK) == -1 && i > 1)
			open(av, O_WRONLY | O_CREAT, 0644);
	else if (access(av, W_OK) == -1 && i > 1)
	{
		ft_printf(STDERR_FILENO, "zsh: permission denied: %s\n", av);
		exit(EXIT_FAILURE);
	}
}
//void do_pipe(char *av, char **env)
//{

//}