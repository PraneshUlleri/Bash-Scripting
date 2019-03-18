#include<stdio.h>
#define size 1024

main(){
        char* p="hello this is string p";
	int nread;
	int pfd[2];
int pid;
pipe(pfd);
pid=fork();
if (fork==0)
{close(pfd[0]);

write(pfd[1],p,strlen(p)+1);
close(pfd[1]);
}
else
{
close(pfd[1]);
printf("parent reads : %s",p);
close(pfd[0]);
}
                }

