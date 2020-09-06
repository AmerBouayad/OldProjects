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
#define __USE_POSIX
#define __USE_POSIX199309
#include <signal.h>
#define TAILLE 5
static struct sigaction act;
int opsem(int sem, int r)
{	int n; struct sembuf op[1];
	op[0].sem_num = 0; // un seul sémaphore dans l'ensemble
	op[0].sem_op = r;
	op[0].sem_flg = 0;
	if ((n=semop(sem,op,1))==-1)
	{	fprintf(stderr,"opsem : err semop\n");
		exit(1);
	}
	return(n);
}
static unsigned boucle = 1;
void fin (int s) {
	boucle = 0;
}

int main(void)
{	int tete, vide,plein,shm;
	int cpt=0;
	unsigned char * t;
	tete =0;
	act.sa_handler = fin;
	sigaction (SIGINT, &act,NULL);
	if ((shm = shmget(11,TAILLE,0777|IPC_CREAT)) < 0){perror ("shmget"); exit (201); }
	t=shmat(shm,0,0777);
	if ((plein=semget(21,1,0666|IPC_CREAT))< 0) {perror ("semget plein"); exit(202); }
	if ((vide=semget(31,1,0666|IPC_CREAT)) < 0) {perror ("semget plein"); exit(203); }
	// afficher sur stdout
	{	while (boucle)
		{	
			opsem(plein,-1); // down
			write (1, t+tete,1);
			tete = (tete+1) % TAILLE;
			opsem(vide,+1);// up 
			cpt++;
		}
	}
	shmdt(t);
	shmctl(shm,IPC_RMID,0);
 	semctl(plein,0,IPC_RMID,0);
 	semctl(vide,0,IPC_RMID,0);
	exit(0);
}
