#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char* buf[4];
    buf[0] = "ls";
    buf[1] = "-a";
    buf[2] = NULL;
    char* command = "ls";

      pid_t pid;

      int status;

     if ((pid = fork()) < 0) {     
          printf("*** ERROR: forking child process failed\n");
          exit(1);
     }
     else if (pid == 0) {          
          if (execvp(command, buf) < 0) {     
               printf("*** ERROR: exec failed\n");
               exit(1);
          }
     }
     else                                  
          while (wait(&status) != pid );



         printf(">");






    return 0;
}
