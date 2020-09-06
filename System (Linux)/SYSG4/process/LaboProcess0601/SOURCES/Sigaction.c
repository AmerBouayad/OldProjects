/*
NOM    	: Sigaction.c
CLASSE 	: Process - LaboProcess 06-01
#OBJET  : réservé au Makefile
AUTEUR	: M. Bastreghi 11/2017
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define __USE_POSIX
#define __USE_POSIX199309
#define __USE_UNIX98

#include <signal.h>

void trapc();
static int cpt;
static char lettre;
static struct sigaction act;


int main (int argc, char * argv[])
{	
	act.sa_handler = trapc;
	sigaction (SIGINT,&act,NULL);

	for (cpt=0;cpt>=0;cpt++)
	{	lettre='A'+(cpt%26);
		write(1,&lettre,1);
		sleep(1);
	}
	exit(0);
}

void trapc()
{	printf("    Fini\n");
	exit(0);
}
