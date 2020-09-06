/*
NOM    	: Conf.c
CLASSE 	: FS - LaboFS 03-02
#OBJET  : réservé au Makefile
AUTEUR	: J.C. Jaumain, 07/2011
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main ()
{	printf ("User %d runs as user %d\n", getuid(), geteuid());
	execlp("cat","cat","Confidentiel",0);
	exit(0);
}
