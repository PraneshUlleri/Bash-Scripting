#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void circle(float radius)
{
		float perimeter,area;
		float pi=3.14;
		perimeter=2*pi*radius;		
		area=pi*radius*radius;
		printf("circumference of circle: %f\n",perimeter);
		printf("area of circle : %f\n",area); 
		
}

void square(float side)
{
		float perimeter,area;
		perimeter=4*side; 
		area=side*side;
		printf("perimeter of square: %f\n",perimeter); 
		printf("area of square: %f\n",area);
		 
}       
    
int  main()
{
     float s;
     printf("Enter: ");
     scanf("%f",&s);
     pid_t pid;
     pid=fork();

     if(pid==0)
	{
	     square(s);
	}

     else
	{
	     pid_t pid2=fork();
	     if(pid2==0)
	        circle(s);
	}
     exit(0);
}


