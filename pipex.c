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
int main (int ac, char **av, char **env)
{
	//(void) ac;
	(void) av;

	if (ac > 4)
	{
		ft_infile();
		while (ac != 1)
		{
			if (ac == 2)
				ft_outfile();
			else
				do_pipe();
			ac--;
		}
	}
	else
		prinft(2, "Not Enough arguments");
	//char *argv[] = {"ls", "-l", NULL};


	//if (execve("/bin/ls", argv, env) == -1) {
    //    perror("execve failed");
    //}

	//char **path;
	
	
	//path = get_path(env);
	//if (path)
	//{
	//int i = -1;
	//while(path[++i])
	//	ft_printf(1, "%s\n", path[i]);
	//ft_free(path);
	//}
	//else
	//	ft_printf(1, "%s\n", path);


    //char    **str;
    //int i;
	//char **args;

	//args = av;
	//args++;
	//execve("/bin/ls", args, NULL);

 	//if (access("infile", R_OK) == 0)
    //    ft_printf(1, "infile is accessible in reading mode\n");
    //if (access("outfile", W_OK) == 0)
    //    ft_printf(1, "ourfile is accessible in writing mode\n");
    //if (access("outfile", X_OK) == 0)
    //    ft_printf(1, "outfile is accessible in execution mode\n");
    //if (access("outfile", R_OK|W_OK) == 0)
    //    ft_printf(1, "outfile is accessible in writing and reading mode\n");
    //if (ac > 3)
    //{
    //    av++;
    //    while (*av)
    //    {
    //        str = ft_split(*av, ' ');
    //        av++;
    //    }
	//	i = -1;
	//	while(str[++i])
	//		ft_printf(1, "%s\n", str[i]);
	//	ft_free(str);
    //}
        // int fd = 0;
        // int fd2;
        // fd2 = open("Makefile", O_WRONLY | O_CREAT, 0644);
        // ft_printf(1, "%d\n", fd2);
        // //close(fd2);
        // dup2(fd2, fd);
        // ft_printf(0, "%d\n", fd2);
        // //dup2(fd2, 0);
        // write(1, "af", 2);
        // pipe --> fork 0 dub2(fd_open, in_fd_cmd) --> 
        // execve()
        // dub2(STDOUT_FILENO, STDIN_FILENO)
		
		// while (str[++i])  for later use
        //    {
        //        ft_printf(1, "%s\n", str[i]);
        //        join = ft_strjoin(join, str[i], ac);
		//		ac--;
        //    }
    return 0;
}