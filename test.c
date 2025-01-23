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

 int main(int argc, char **argv)
 {
     int     pipefd[2];
     char    buf;
     pid_t   cpid;
    
     if (argc != 2)
     {
         fprintf(stderr, "Usage: %s <string>\n", argv[0]);
         exit(EXIT_FAILURE);
     }
     if (pipe(pipefd) == -1)
     {
         perror("pipe");
         exit(EXIT_FAILURE);
     }
     cpid = fork();
     if (cpid == -1)
     {
         perror("fork");
         exit(EXIT_FAILURE);
     }
     if (cpid == 0)  /* Child reads from pipe */
     {    
     close(pipefd[1]);          /* Close unused write end */
     while (read(pipefd[0], &buf, 1) > 0)
	 {
         write(STDOUT_FILENO, &buf, 1);
		 write(1,"1\n",2);
	 }
     write(STDOUT_FILENO, "\n", 1);
     close(pipefd[0]);
     exit(EXIT_SUCCESS);
     } 
     else             /* Parent writes argv[1] to pipe */
     {
         close(pipefd[0]);             /* Close unused read end */
		 write(pipefd[1], argv[1], strlen(argv[1]));
         close(pipefd[1]);             /* Reader will see EOF */
         wait(NULL);  /* Wait for child */
         exit(EXIT_SUCCESS);
     }
 }