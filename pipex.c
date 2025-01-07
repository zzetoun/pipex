#include "pipex.h"

int main (int ac, char **av)
{
    char    **str;
    char    *join;
    int i;

    if (ac > 1)
    {
        av++;
        while (*av)
        {
            i = -1;
            str = ft_split(*av, ' ');
            while (str[++i])
            {
                ft_printf(1, "%s\n", str[i]);
                join = ft_strjoin(join, str[i]);
            }
            ft_free(str);
            av++;
        }
        ft_printf(1, "%s\n", join);
        free(join);
    }
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
    return 0;
}

// int main(int argc, char **argv)
// {
//     int     pipefd[2];
//     char    buf;
//     pid_t   cpid;
    
//     if (argc != 2)
//     {
//         fprintf(stderr, "Usage: %s <string>\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }
//     if (pipe(pipefd) == -1)
//     {
//         perror("pipe");
//         exit(EXIT_FAILURE);
//     }
//     cpid = fork();
//     if (cpid == -1) 
//     {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }
//     if (cpid == 0)  /* Child reads from pipe */
//     {    
//     close(pipefd[1]);          /* Close unused write end */
//     while (read(pipefd[0], &buf, 1) > 0)
//         write(STDOUT_FILENO, &buf, 1);
//     write(STDOUT_FILENO, "\n", 1);
//     close(pipefd[0]);
//     exit(EXIT_SUCCESS);
//     } 
//     else             /* Parent writes argv[1] to pipe */
//     {
//         close(pipefd[0]);             /* Close unused read end */
//         write(pipefd[1], argv[1], ft_strlen(argv[1]));
//         close(pipefd[1]);             /* Reader will see EOF */
//         wait(NULL);  /* Wait for child */
//         exit(EXIT_SUCCESS);
//     }
// }