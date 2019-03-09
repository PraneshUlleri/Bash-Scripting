#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#define siz 30
int main(int argc,char *argv[])
{
	int shmid1=shmget(IPC_PRIVATE,siz*sizeof(int),IPC_CREAT|0666);
	int shmid2=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0666);
	int shmid3=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0666);
	int shmid4=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0666);
	int *arr=(int*)shmat(shmid1,0,0);
	int *idx=(int*)shmat(shmid2,0,0);
	int *odx=(int*)shmat(shmid3,0,0);
	int *s=(int*)shmat(shmid4,0,0);
	memset(arr,0,siz*sizeof(int));
	*idx=-1;
	*odx=-1;
	*s=30;
	pid_t pid=fork();
	if(pid==0)
	{
		char arg1[25],arg2[25],arg3[25],arg4[25];
		sprintf(arg1,"%d",shmid1);
		sprintf(arg2,"%d",shmid2);
		sprintf(arg3,"%d",shmid3);
		sprintf(arg4,"%d",shmid4);
		char *args[]={"./consumer",arg1,arg2,arg3,arg4,NULL};
		execv(args[0],args);
	}
	else
	{
		char arg1[25],arg2[25],arg3[25],arg4[25];
		sprintf(arg1,"%d",shmid1);
		sprintf(arg2,"%d",shmid2);
		sprintf(arg3,"%d",shmid3);
		sprintf(arg4,"%d",shmid4);
		char *args[]={"./producer",arg1,arg2,arg3,arg4,NULL};
		execv(args[0],args);
	}
	return 0;
}

