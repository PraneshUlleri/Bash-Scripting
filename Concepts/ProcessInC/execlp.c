#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
char *args={"./exec",NULL};
execlp(args[0],args);
printf("will i work? probably not....");
return 0;
}
