/*
NOM    	: TestMake2.c
CLASSE 	: intro - LaboIntro  01-02
#OBJET  : réservé au makefile
AUTEUR	: mba 01/2016
*/
#include <stdlib.h>
#include <stdio.h>
#include "MonInclude.h"
#include "boucle.h"

int main ( int argc, char * argv[] )
{  int i;
   if (argc < 2)  // argv[0] est le nom du programme
	   exit(1);

   printf("%s\n",argv[1]);
   i = atoi (argv[1]); // une chaine numérique qui devient un entier
   if (i<MAX)
	i=MAX;

   onBoucle ("Salut ! ", i);
   exit(0);
}
