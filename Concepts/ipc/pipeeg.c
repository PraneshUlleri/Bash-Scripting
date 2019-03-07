#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define BUFFERSIZE 25
#define READEND 0
#define WRITEEND 1
int main()
{
char writemsg[BUFFERSIZE] = "Greetings";
char readmsg[BUFFERSIZE];
int fd[2];
pid_t pid;
/* create the pipe */
if (pipe(fd) == -1) {
fprintf(stderr,"Pipe failed");
return 1;
}
/* fork a child process */
pid = fork();
if (pid < 0) { /* error occurred */
fprintf(stderr, "Fork Failed");
return 1;
}
if (pid > 0) { /* parent process */
/* close the unused end of the pipe */
close(fd[READEND]);
printf("p1\n");
/* write to the pipe */
write(fd[WRITEEND], writemsg, strlen(writemsg)+1);

printf("p2\n");
/* close the WRITEEND of the pipe */
close(fd[WRITEEND]);

printf("p3\n");
}
else { /* child process */
/* close the unused end of the pipe */
close(fd[WRITEEND]);

printf("c1\n");
/* read from the pipe */
read(fd[READEND], readmsg, BUFFERSIZE);
printf("read %s",readmsg);

printf("c2\n");

/* close the WRITEEND of the pipe */
close(fd[READEND]);

printf("c3\n");
}
return 0;
}
