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

int main (int ac, char **av, char **env)
{
	//int	fd[2];
	(void) env;
	int	i;

	i = 1;
	if (ac > 4)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0 && ac < 6)
		{
			ft_printf(STDERR_FILENO, "Arguments Error: here_docs needs 5 args\n");
			exit(EXIT_SUCCESS);
		}
		while (i < ac)
		{
			if (i == 1 || i == ac - 1)
				pipe_file(av[i], i);
			//else
			//	do_pipe(av[i], env);
			i++;
		}
	}
	else
	{
		ft_printf(STDERR_FILENO, "Arguments Error: pipex needs 4 args\n");
		exit(EXIT_SUCCESS);
	}
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
        // dup2(STDOUT_FILENO, STDIN_FILENO)
		
		// while (str[++i])  for later use
        //    {
        //        ft_printf(1, "%s\n", str[i]);
        //        join = ft_strjoin(join, str[i], ac);
		//		ac--;
        //    }
    return 0;
}