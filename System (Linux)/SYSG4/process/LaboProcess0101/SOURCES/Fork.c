/*
NOM    	: Fork.c
CLASSE 	: Process - LaboProcess 01-01
#OBJET  : réservé au Makefile
AUTEUR	: J.C. Jaumain, 07/2011
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main ( )
{	int var,r;
	var=6;
	printf("Avant le fork, pour le père %d, l'adresse %p contient %d\n", getpid(),(void*)&var,var);
	if ((r=fork())==0){
		printf ("Voici %d, fils de %d\n", getpid(), getppid());
		printf("pour le fils %d, l'adresse %p contient %d\n", getpid(),(void*)&var,var);
		var=19;
		//sleep(3);
		printf("pour le fils %d du père %d, l'adresse %p contient %d\n", getpid(), getppid(),(void*)&var,var);
		exit(0);
	}
	printf("Après le fork, pour le père %d, l'adresse %p contient %d\n", getpid(),(void*)&var,var);
	var=13;
	//sleep(3);
	printf("Après le fork, pour le père %d, l'adresse %p contient %d\n", getpid(),(void*)&var,var);
	//wait(0);
	exit(0);
}

