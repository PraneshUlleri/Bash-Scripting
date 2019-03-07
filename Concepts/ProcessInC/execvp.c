#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(){

char *args[]={"./exec",NULL};
execvp(args[0],args);

printf("END");

return 0;
}
