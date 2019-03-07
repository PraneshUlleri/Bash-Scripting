#include <sys/types.h>      /* needed to use pid_t, etc. */
#include <sys/wait.h>       /* needed to use wait() */  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>         /* LINUX constants and functions (fork(), etc.) */

int main()
{
 pid_t pid;

 pid = fork();
  
 if (pid < 0)
  {
   printf("A fork error has occurred.\n");
   exit(-1);
  }
 else 
  if (pid == 0) /* We are in the child. */
   {
    printf("I am the child, about to call ps using execlp.\n");
    execlp("/bin/ls","ls",(char *) 0);
   /*  If execlp() is successful, we should not reach this next line. */
    printf("The call to execlp() was not successful.\n");
    exit(127);
   }
  else  /* We are in the parent. */
   {
    wait(0);               /* Wait for the child to terminate. */
    printf("I am the parent.  The child just ended.  I will now exit.\n");
    exit(0);
   }

 return(0);  
}  
