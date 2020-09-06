/*
NOM    	: Zombie.c
CLASSE 	: Process - LaboProcess 02-02
#OBJET  : réservé au Makefile
AUTEUR	: J.C. Jaumain, 07/2011
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main(int argc, char * argv [])
{ int r ;
printf ("Je␣suis␣le␣processus␣père␣%d\n",getpid());

if ( (r=fork()) == 0){
	usleep(1);
	printf ("Je suis le processus %d du père %d\n",getpid(), getppid());
	while(1);
}

printf("\njui mort\n");
exit (0);
}

