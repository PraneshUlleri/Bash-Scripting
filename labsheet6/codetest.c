#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
void sem_lock(struct sembuf sem_op, int sem_id)
{
	sem_op.sem_num = 0;
	sem_op.sem_op = -1;
	sem_op.sem_flg = 0;
	semop(sem_id, &sem_op, 1);
}
void sem_unlock(struct sembuf sem_op, int sem_id)
{
	sem_op.sem_num = 0;
	sem_op.sem_op = 1;
	sem_op.sem_flg = 0;
	semop(sem_id, &sem_op, 1);
}
int main()
{
	int shmid = shmget(IPC_PRIVATE, 5 * sizeof(int), 0777 | IPC_CREAT);
	int sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT | 0777);

	if (sem_id == -1)
	{
		printf("Errr");
	}
	semctl(sem_id, 0, SETVAL, 1);
	int *a, *b;
	int pid = fork();
	if (pid == 0)
	{
		while (1)
		{
			struct sembuf sem_op;
			sem_lock(sem_op, sem_id);
			a = shmat(shmid, 0, 0);
			printf("Enter a no");
			int c;
			scanf("%d", &c);
			a[0] = c;
			sem_unlock(sem_op, sem_id);
		}
	}
	else
	{
		sleep(1);
		while (1)
		{
			struct sembuf sem_op;
			sem_lock(sem_op, sem_id);
			b = shmat(shmid, 0, 0);
			int c = b[0];
			int flag = 1;
			for (int i = 2; i <= c / 2; i++)
			{
				if (c % i == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				printf("\nPrime no\n");
			}
			else
			{
				printf("\nNot prime\n");
			}
			sem_unlock(sem_op, sem_id);
		}
	}
	return 0;
}
