/*
NOM    	: Mcat.c
CLASSE 	: FS - LaboFS 04-01
#OBJET  : réservé au makefile
AUTEUR	: J.C. Jaumain, 07/2011
BUGS	:
*/
#include <stdlib.h>
#include <unistd.h>

int main ()
{  int n;
   char c;
   while ((n=read(0,&c,1)) > 0) write(1,&c,1);
   exit(0);
}
