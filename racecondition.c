#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/shm.h>
#include<stdlib.h>
int main()
{
    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT);
    int shmid1 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT);
    int shmid2 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT);
    int *sh = (int*)shmat(shmid, 0, 0);
    int i = 0,x = 0, y, z;
    //*sh = num;
    pid_t pid1, pid2;
    pid1 = fork();
    if(pid1 == 0) {
        sh = (int*)shmat(shmid, 0, 0);
        while(i != 10) {
            y = x++;
            i++;
        }
       printf("X in p1 %d", x);
        int *p1 = (int*)shmat(shmid1, 0, 0);
        *p1 = y;
        shmdt(p1);
       
    } else {
        i = 0;
        wait(NULL);
        pid2 = fork();
        if(pid2 == 0) {
            sh = (int*)shmat(shmid, 0, 0);
            while(i != 10) {
            z = x--;
            i++;
        }
	printf("X in p1 %d", x);
        int *p2 = (int*)shmat(shmid2, 0, 0);
        *p2 = z;
        shmdt(p2);
        } else {
            wait(NULL);
            sh = (int*)(shmid, 0, 0);
            int *p1 = (int*)shmat(shmid1, 0, 0);
            int *p2 = (int*)shmat(shmid2, 0, 0);
            printf("The final value of x is: %d\n", p2);
        }
    }
   
}
