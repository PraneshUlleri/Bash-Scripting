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
	int evenc=0,oddc=0;
	while(1)
	{
		if (*odx== -1) 
		{ 
			printf("buffer is empty\n"); 
			sleep(5);
		}
		else
		{ 
			int data = arr[*odx]; 
			printf("Consumed %d\n",data);
			arr[*odx] = -1; 
			if (*odx == *idx) 
			{ 
				*odx = -1; 
				*idx = -1; 
			}	 
			else
			{
				*odx=(*odx+1)%(*siz);
			} 
			if(data%2==0)
				evenc++;
			else
				oddc++;
			if(evenc > oddc)
			{
				printf("Permission Denied\n");
				sleep(5);
			}
		}
	}
	return 0;
}
