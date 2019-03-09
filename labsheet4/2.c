#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>
#include <unistd.h>
#define BUFFERSIZE 25
#define READEND 0
#define WRITEEND 1
int main()
{
char buffer[1024];
int fd[2];
pid_t pid;
if (pipe(fd) == -1) 
{
	printf("Pipe failed"); 
}
pid=fork();
if(pid==0)
{
	printf("Child:\n");
	printf("Enter String: ");
	scanf("%s",&buffer);
	close(fd[0]);
	write(fd[1],buffer,strlen(buffer)+1);
	close(fd[1]);
}
else
{
	wait(NULL);
	close(fd[1]);
	read(fd[0],buffer,sizeof(buffer));
	int i=0;
	while(buffer[i] !='\0')
		{
			buffer[i]=toupper(buffer[i]);
			i++;
		}
	close(fd[0]);
	printf("Parent:\nFinal String: %s",buffer);
	
}
return 0;
}
