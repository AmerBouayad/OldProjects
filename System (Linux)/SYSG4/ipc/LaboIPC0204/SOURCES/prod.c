/*
NOM    	: prod.c
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
{	int queue, vide,plein,shm;
	unsigned char * t;
	unsigned char b;
	queue = 0;
	if ((shm = shmget(11,TAILLE,0777|IPC_CREAT)) < 0){perror ("shmget"); exit (201); }
	t=shmat(shm,0,0777);
	if ((plein=semget(21,1,0666|IPC_CREAT))< 0) {perror ("semget plein"); exit(202); }
	if ((vide=semget(31,1,0666|IPC_CREAT)) < 0) {perror ("semget plein"); exit(203); }
        if (semctl(plein,0,SETVAL,0)<0) {perror("semctl plein"); exit(204); }
        if (semctl(vide,0,SETVAL,5)<0) {perror("semctl vide"); exit(205); }
	// produire ce qu'on lit sur stdin
	while (read (0, &b,1) > 0)
	{	
	   opsem(vide,-1); // down vide
	   t[queue]=b;
	   queue = (queue + 1) % TAILLE;
	   opsem(plein,+1);// up  plein
	}
        semctl(plein,0,IPC_RMID,0);
        semctl(vide,0,IPC_RMID,0);
	shmdt(t); // explicite
        shmctl(shm,IPC_RMID,0); 
	exit(0);
}
