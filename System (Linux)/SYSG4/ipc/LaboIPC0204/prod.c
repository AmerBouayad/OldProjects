/*
NOM    	: ProdCons.c
CLASSE 	: IPC - LaboIPC 02-04
#OBJET  : réservé au makefile
AUTEUR	: J.C. Jaumain, 07/2011
      	: MBA 04/2017            
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#define TAILLE 5
int opsem(int sem, int r)
{	int n; struct sembuf op[1];
	op[0].sem_num = 0; // un seul sémaphore dans l'ensemble
	op[0].sem_op = r;
	op[0].sem_flg = 0;
	if ((n=semop(sem,op,1)) < 0)
	{	fprintf(stderr,"opsem : err semop\n");
		exit(1);
	}
	return(n);
}
int main(void)
{	int queue, vide,plein,shm;
	int cpt=0;
	unsigned char * t;
	unsigned char b;
	queue = 0;
	if ((shm = shmget(11,TAILLE,0777|IPC_CREAT)) < 0){perror ("shmget"); exit (201); }
	t=shmat(shm,0,0777);
	if ((plein=semget(21,1,0666|IPC_CREAT))< 0) {perror ("semget plein"); exit(202); }
	if ((vide=semget(31,1,0666|IPC_CREAT)) < 0) {perror ("semget plein"); exit(203); }
	// produire ce qu'on lit sur stdin
	while (read (0, &b,1) > 0)
	{	
	   opsem(vide,-1); // down
	   t[queue]=b;
	   queue = (queue + 1) % TAILLE;
	   opsem(plein,+1);// up 
	   cpt++;
	}
	shmdt(t); // explicite
	exit(0);
}
