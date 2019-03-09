#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int shmid1=atoi(argv[1]);
	int shmid2=atoi(argv[2]);
	int shmid3=atoi(argv[3]);
	int shmid4=atoi(argv[4]);
	int *arr=(int*)shmat(shmid1,0,0);
	int *idx=(int*)shmat(shmid2,0,0);
	int *odx=(int*)shmat(shmid3,0,0);
	int *siz=(int*)shmat(shmid4,0,0);
	printf("Producer: \n");
	while(1)
	{
		if((*odx == 0 && *idx == *siz-1) || (*idx == (*odx-1)%(*siz-1)))
		{
			printf("buffer is full\n");
			for(int i=0;i<*siz;i++)
					printf("%d ",arr[i]);
			printf("Going to sleep...\n");
			sleep(10);
		}
		if(*idx==-1)
			*idx=*odx=0;
		arr[*idx]=rand()%1000;
		printf("Produced: %d\n",arr[*idx]);
		*idx=(*idx+1)%(*siz);
	}
	return 0;
}
