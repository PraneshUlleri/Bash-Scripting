#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
int main()
{
	int shmid=shmget(IPC_PRIVATE,1024,IPC_CREAT|0666);//for array
	int shmid1=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0666);//for sum from child 1
	int shmid2=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0666);//for n from child 2
	printf("Parent: \n");
	printf("Enter numbers untill, a special character is entered: \n");
	int i=0;
	int *arr=(int*)shmat(shmid,0,0);
	i=0;
	while(1)
	{
		char temp[10];
		scanf("%s",&temp);
		if(isdigit(temp[0]))
		{
			int no=atoi(temp);
			no=no*no;
			*(arr+i)=no;
			i++;
		}
		else
		{
			arr[i]=INT_MIN;
			break;
		}
	}
	pid_t pid1=fork();//child 1
	if(pid1==0)
	{
		int sum=0;
		i=0;
		arr=(int*)shmat(shmid,0,0);
		while(arr[i] != INT_MIN)
		{	
			sum+=arr[i];
			i++;
		}
		int *s=(int*)shmat(shmid1,0,0);
		*s=sum;
		shmdt(s);
	}
	else
	{
		wait(NULL);
		printf("Child 1 terminated,Sum calculated \n");
		pid_t pid2=fork();//child 2
		if(pid2==0)
		{
			int i=0;
			arr=(int*)shmat(shmid,0,0);
			while(arr[i] != INT_MIN)
				i++;
			int *siz= (int*) shmat(shmid2,0,0);
			*siz=i;
			shmdt(siz);
		}
		else
		{
			wait(NULL);
			printf("Child 2 terminated, Size calculated \n");
			int *sum=shmat(shmid1,0,0);
			int *siz=shmat(shmid2,0,0);	
			float avg=(float)*sum / *siz;
			printf("Sum : %d\n",*sum);
			printf("N: %d\n",*siz);
			printf("Mean Square Average: %0.2f",avg);
		}
	}
	//shmdt(arr);
	exit(0);
}
