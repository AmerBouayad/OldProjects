/*
NOM    	: AffContinu.c
CLASSE 	: IPC - LaboIPC 02-02
#OBJET  : réservé au makefile
AUTEUR	: J.C. Jaumain, 07/2011
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int opsem(int sem, int i)
{	int n; struct sembuf op[1];
	op[0].sem_num = 0; // premier et unique sémaphore
	op[0].sem_op = i;
	op[0].sem_flg = SEM_UNDO;
	if ((n=semop(sem,op,1))==-1)
	{	perror ("semop");
		exit(1);
	}
	return(n);
}

int main ( int argc, char * argv[])
{	int n,sem,r;
	int shm;
	char t[2];
	char *c;
	if (( sem=semget(123,1,0666|IPC_CREAT))==-1)
	{ 	perror ("semget");
	       	exit(-1);
	}
 	if (semctl(sem,0,SETVAL,0)==-1) // 0 ressources (feu rouge au début)
	{       perror ("semctl");
	        exit(1);
	}
	if ((shm = shmget (IPC_PRIVATE, 1, 0666|IPC_CREAT)) == -1)
	{ 	perror ("shmget");
	       	exit(-1);
	}
	c = shmat (shm, NULL, 0666);
	if (c == NULL){
                perror ("shmat"); exit (3);
        }
	if ((r=fork())==0) //fils
	{	opsem (sem, -1); // down - feu rouge ?
		while (*c != 'q') {write(1,c,1);usleep(10000);}	
		shmdt (c);
		exit(0);
	}
	n=0;
	do 
	{	read(0,t,2);
		*c=t[0];
		if (n==0) opsem (sem, +1); // up
		n=1;
	} while (t[0] != 'q');
	wait(0);
	shmdt (c);
 	if (semctl(sem,0,IPC_RMID,0)!=0)
	{	perror ("semctl");
	        exit(1);
	}
	exit(0); 
}

