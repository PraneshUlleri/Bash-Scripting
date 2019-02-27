#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>   
#include<sys/wait.h>
     
int main(int argc,char *argv[])
{
	printf("Parent ID   Self ID\n");
	printf("  %d       %d\n",getppid(),getpid());
	pid_t p2=fork();
	if(p2!=0)
		{	
			wait(NULL);
			pid_t p3=fork();
			if(p3!=0)
			{
				wait(NULL);				
				pid_t p4=fork();
				if(p4==0)
				{
					printf("  %d       %d\n",getppid(),getpid());
					pid_t p7=fork();
					if(p7==0)
					{
						printf("  %d       %d\n",getppid(),getpid());
						pid_t p8=fork();
						if(p8!=0)
						{	
							wait(NULL);
							pid_t p9=fork();
							if(p9==0)
								printf("  %d       %d\n",getppid(),getpid());
							else
							  {
								wait(NULL);
							  }
						}
						else
						{
							printf("  %d       %d\n",getppid(),getpid());
						}
					}
					else
					{
						wait(NULL);
					}
				}
				
				else
				  {
					wait(NULL);
				  }
			}
			else
			{
				printf("  %d       %d\n",getppid(),getpid());
				pid_t p5=fork();
				if(p5!=0)
					{	
						wait(NULL);
						pid_t p6=fork();
						if(p6==0)
						{
							printf("  %d       %d\n",getppid(),getpid());
						}
						else
						{
							wait(NULL);
						}
					}
				else
					{
						printf("  %d       %d\n",getppid(),getpid());
					}
			}
			
		}
	else
	{
		printf("  %d       %d\n",getppid(),getpid());
	}
	exit(0);
	return 0;
}
