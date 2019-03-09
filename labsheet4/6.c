#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include <string.h>
#define RD 0
#define WR 1
int main()
{
	int fp1[2];
	int fp2[2];
	int sum,n;
	int buffer[1024];
	if(pipe(fp1) ==-1)
	{
		printf("Pipe1 Failed");
		return 0;
	}
	if(pipe(fp2)==-1)
	{
		printf("Pipe2 Failed");
		return 0;
	}
	printf("Parent: \n");
	printf("Enter numbers untill, a special character is entered: \n");
	int i=0;
	while(1)
	{
		char temp[10];
		scanf("%s",&temp);
		if(isdigit(temp[0]))
		{
			int no=atoi(temp);
			no=no*no;
			buffer[i]=no;
			i++;
		}
		else
		{
			buffer[i]=INT_MIN;
			break;
		}
	}
	write(fp1[WR],buffer,sizeof(buffer));
	write(fp2[WR],buffer,sizeof(buffer));
	pid_t pid=fork();
	if(pid==0)
	{
		int s=0,i=0;
		read(fp1[RD],buffer,sizeof(buffer));
		while(buffer[i]!=INT_MIN)
		{
			s+=buffer[i];
			i++;
		}
		memset(buffer,0,sizeof(buffer));
		buffer[0]=s;
		write(fp1[WR],buffer,sizeof(buffer));
		close(fp1[WR]);
	}
	else
	{
		wait(NULL);
		printf("Child 1 terminated, sum calculated\n");
		read(fp1[RD],buffer,sizeof(buffer));
		sum=buffer[0];
		close(fp1[RD]);
		pid_t pid1=fork();
		if(pid1==0)
		{
			int n=0;
			read(fp2[RD],buffer,sizeof(buffer));
			while(buffer[n]!=INT_MIN)
				n++;
			close(fp2[RD]);
			memset(buffer,0,sizeof(buffer));
			buffer[0]=n;
			write(fp2[WR],buffer,sizeof(buffer));
			close(fp2[WR]);
		}
		else
		{
			wait(NULL);
			printf("Child 2 terminated, n calculated\n");
			read(fp2[RD],buffer,sizeof(buffer));
			n=buffer[0];
			float avg=(float)sum /n;
			printf("Sum : %d\n",sum);
			printf("N: %d\n",n);
			printf("Mean Square Average: %0.2f",avg);
		}
	}
	exit(0);
}
