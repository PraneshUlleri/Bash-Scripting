#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>   
#include<sys/wait.h>     

int  main()
{
    int r;
    printf("enter num: ");
    scanf("%d",&r);
    char arg[100];
    char arg2[100];
    pid_t pid,root,pid1;
    root=getpid();
    sprintf(arg,"%d",r);
    sprintf(arg2,"%d",root);
    printf("parent id: %d\n",root);
    pid=fork();
    if(pid==0)
	 {
		  char *args[]={"./square",arg,arg2,NULL}; 
          	  execvp(args[0],args);
	 }
	 else
	 {
		 printf("waiting for child to stop\n");
		 pid1=wait(NULL);
		 printf("child with id: %d is stopped\n",pid1);
		 pid_t pid2=fork();
		 if(pid2==0)
			{   
				char *args[]={"./circle",arg,arg2,NULL}; 
				execvp(args[0],args); 
			}
		  pid_t pid3=wait(NULL);
		  printf("waiting for child to stop\n");
		  printf("child with id: %d is stopped\n",pid3);
		  printf("parent continuous execution\n");
		  exit(0);
	 }
}

