/*
NOM    	: prod.c
CLASSE 	: IPC - LaboIPC 02-04
#OBJET  : réservé au makefile
AUTEUR  : MBA 11/2017            
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
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
