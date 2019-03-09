#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	char *str;
	key_t key = ("shmfile",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	if(fork()==0)
	{
		str = (char*)shmat(shmid,(void*)0,0);
		printf("Enter a string: ");
		scanf("%s",str);
	}
	else{
		wait(NULL);
		str = (char*)shmat(shmid,(void*)0,0);
		int i=0;
		while(str[i]!='\0')
		{
			str[i]=toupper(str[i]);
			i++;
		}
		printf("The resultant string: %s",str);
	}
 	exit(0);
			
}
