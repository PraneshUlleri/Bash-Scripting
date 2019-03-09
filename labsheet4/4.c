#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>
#define RD 0
#define WR 1
int main()
{
	int fp[2];
	int buffer[1024];
	if(pipe(fp) == -1)
	{
		printf("Pipe Failed");
		return 0;
	}
	pid_t pid=fork();
	if(pid == 0)
	{
		char temp[1024];
		printf("Enter numbers untill, a special character is entered: \n");
		int i=1;
		while(1)
		{
			scanf("%s",&temp);
			if(isdigit(temp[0]))
			{
				buffer[i]=atoi(temp);
				i++;
			}
			else
			{
				buffer[0]=i;
				break;
			}
		}
		close(fp[RD]);
		write(fp[WR],buffer,sizeof(buffer));
		close(fp[WR]);
	}
	else
	{
		wait(NULL);
		printf("Parent: \n");
		close(fp[WR]);
		read(fp[RD],buffer,sizeof(buffer));
		int sum=0;
		for(int i=1;i<buffer[0];i++)
			sum+=buffer[i];
		printf("Sum: %d",sum);
		close(fp[RD]);
	}
	exit(0);
}
