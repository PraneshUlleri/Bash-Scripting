#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void  ChildProcess(void)
{	
	float side,perimeter,area;
	printf("enter side: ");
	scanf("%f",&side);
	perimeter=4*side;	
	area=side*side;
	printf("Perimeter of square: %f",perimeter);
	printf("\nArea of square: %f\n",area);
}

void  ParentProcess(void)
{	
	float radius,perimeter,area;
	float pi=3.14; 
	printf("enter radius: ");
	scanf("%f",&radius);
	perimeter=2*pi*radius;
	area=pi*radius*radius; 
	printf("circumference of circle: %f",perimeter);
	printf("\narea of circle : %f\n",area);		
}
           
int  main()
{
     pid_t pid;
     pid=fork();
     if (pid==0)
     {   	 wait(NULL);

      	     ChildProcess();
     } else 
	{
 //		 wait(NULL);
          ParentProcess();
	}
      exit(0);
}

