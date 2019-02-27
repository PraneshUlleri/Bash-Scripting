#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>   
#include<sys/wait.h>     

int  main()
{
    int a;
    printf("enter num: ");
    scanf("%d",&a);
    pid_t r=getpid();
    char arg[100];
    char arg1[100];
    sprintf(arg1,"%d",r);
    sprintf(arg, "%d", a); 
    pid_t  pid;
    pid = fork();
	if(pid==0)
	 {
		char *args[]={"./square",arg,arg1,NULL}; 
         	execvp(args[0],args); 
	 }
	 else
	 {
		wait(NULL);
		pid_t pid2=fork();
		if(pid2==0)
			{
			     char *args[]={"./circle",arg,arg1,NULL}; 
			     execvp(args[0],args); 
			}
		wait(NULL);
	 }
    exit(0);
}


