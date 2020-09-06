/*
NOM    	: AlloueShm.c
CLASSE 	: IPC - LaboIPC 01-01
#OBJET  : réservé au makefile
AUTEUR	: J.C. Jaumain, 07/2011
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
int main(int argc, char * argv[])
{	int shm1,shm2;
	char * c;
	int * i;
	shm1 = shmget(123,1,0777|IPC_CREAT);
	shm2 = shmget(321,4,0777|IPC_CREAT);
        printf ("shm1=%d, shm2=%d\n", shm1,shm2);
	printf ("shm1=%p, shm2=%p\n", shm1,shm2);
	c=shmat(shm1,0,0777);
	i=shmat(shm2,0,0777);
	*c='a';
	*i=1234;
	shmdt(c);
	shmdt(i);
	exit(0); 
}
		
