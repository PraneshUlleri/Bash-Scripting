#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int s=atoi(argv[1]);
	int pid=atoi(argv[2]);
	if(getppid()!=pid)
	  {
		printf("I'm an orphan process,as wait is not called, init is the parent : %d \n",getppid());
	  }
	else
	  {
		printf("I'm not an orphan process\n");
	  }
	printf("from Square,My id is %d \n",getpid());
	printf("from Square,My parent id is %d \n",getppid());
	printf("Area: %d\n",s*s);
	printf("Perimeter: %d\n",4*s);
	return 0;
}
