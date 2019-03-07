#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
char *arg[]={"./exec",NULL};
execv(arg[0],arg);
printf("vd");
return 0;

}
