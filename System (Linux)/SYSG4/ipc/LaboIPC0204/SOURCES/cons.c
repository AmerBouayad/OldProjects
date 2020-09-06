/*
NOM    	: cons.c
CLASSE 	: IPC - LaboIPC 02-04
#OBJET  : réservé au makefile
AUTEUR	: MBA 11/2017            
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#include "prodcons.h"
int main(void)
{	int tete, vides,pleines,shm;
	unsigned char * t; // tableau partagé

	tete = 0;
	if ((shm = shmget(11,TAILLE,0777|IPC_CREAT)) < 0){perror ("shmget"); exit (201); }
	t=shmat(shm,0,0777);
	if ((pleines=semget(21,1,0666|IPC_CREAT))< 0) {perror ("semget pleines"); exit(202); }
	if ((vides=semget(31,1,0666|IPC_CREAT)) < 0) {perror ("semget pleines"); exit(203); }
	if (semctl(pleines,0,SETVAL,0)<0) {perror("semctl pleines"); exit(204); }
	if (semctl(vides,0,SETVAL,5)<0) {perror("semctl vides"); exit(205); }

	int status = 0;
	while (status != -1) // suppression du sémaphore ?
	{	
		if ((status = opsem(pleines,-1)) != -1) { // down pleines
			
			write (1, t+tete, 1); // Afficher le caractère en tête
			tete = (tete + 1) % TAILLE; // chaise musicale
			status = opsem(vides,+1); // up vides, une nouvelle case vide
		}
	}
	shmdt(t); 
	exit(0);
}
