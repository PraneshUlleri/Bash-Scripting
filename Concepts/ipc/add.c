#include <stdio.h>
#include <sys/shm.h> 

main()
{
 int shmid, status;
 int *a;
 int i;
 shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT|0666); 
 if (fork() == 0)
 { 
   a = (int *) shmat(shmid, 0, 0);
  sleep(5);
  printf("\t\t\t Child reads: %d\n", *a);
  *a=*a * *a;
  printf("\t\t\t Child compute suare as : %d\n", *a);
 shmdt(a);
 }
 else { 
 a = (int *) shmat(shmid, 0, 0);
 printf("Parent--->Enter the No. to be squared");
 scanf("%d",&i);
 *a=i;
 printf("Parent writes: %d\n", *a);
 sleep (5);
  printf("Parent reads square as : %d\n", *a);
 wait(&status); 
 shmdt(a);
 shmctl(shmid, IPC_RMID, 0);
 }
} 
