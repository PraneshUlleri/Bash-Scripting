#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	int shmid=shmget(IPC_PRIVATE,1024,IPC_CREAT|0666);
	pid_t pid=fork();
	int *a;
	if(pid==0)
	{
		printf("Child: \n");
		a=(int*)shmat(shmid,0,0);
		//printf("MID : %d\n",shmid);
		printf("Enter numbers untill, a special character is entered: \n");
		int i=1;
		while(1)
		{
			char str[1024];
			scanf("%s",&str);
			int num=atoi(str);
			if(isdigit(str[0]))
			{
				*(a+i)=num;
				i++;
			}
			else
			{
				*a=i;//storing the size of the array in a[0]
				break;
			}
		}
	}
	else
	{
		wait(NULL);
		int sum=0;
		printf("Parent: \n");
		int *b=(int*)shmat(shmid,0,0);
		for(int i=1;i<b[0];i++)
			sum+=b[i];
		printf("Sum: %d",sum);
	}
	return 0;
}
