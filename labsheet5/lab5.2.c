#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	int shmid1=shmget(IPC_PRIVATE,siouteof(int),IPC_CREAT|0666);//for variable x
	int shmid2=shmget(IPC_PRIVATE,siouteof(int)*2,IPC_CREAT|0666);//for flag[2]
	int shmid3=shmget(IPC_PRIVATE,siouteof(int),IPC_CREAT|0666);//for turn
	int *x=(int*)shmat(shmid1,0,0);
	int *flag=(int*)shmat(shmid2,0,0);
	*x=0;
	flag[0]=0;
	flag[1]=0;
	pid_t p=fork();
	if(p==0)
	{
		int *x=(int*)shmat(shmid1,0,0);
		int *flag=(int*)shmat(shmid2,0,0);
		int *turn=(int*)shmat(shmid3,0,0);
		for(int i=0;i<10;i++)
			{
				*(flag)=1;
				*turn=1;
				while(*(flag+1)&& *turn==1);
				*x=*x+1;//Critical Section
				printf("X in A: %d\n",*x);
				sleep(2);
				flag[0]=0;
			}
	}
	else
	{
		pid_t p2=fork();
		if(p2==0)
		{
			int *x=shmat(shmid1,0,0);
			int *flag=shmat(shmid2,0,0);
			int *turn=shmat(shmid3,0,0);
			for(int i=0;i<10;i++)
			{
				*(flag+1)=1;
				*turn=0;
				while(*(flag) && *(turn)==0);
				*x=*x-1;//Critical Section
				printf("X in B  %d\n",*x);
				sleep(2);
				flag[1]=0;
			}
		}
		else
		{
			wait(NULL);
			wait(NULL);
			int *out=shmat(shmid1,0,0);
			printf("Final value of X: %d",*out);
		}
		
	}
	exit(0);
}
