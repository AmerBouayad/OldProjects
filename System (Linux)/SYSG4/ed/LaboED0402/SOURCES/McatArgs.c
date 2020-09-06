/*
NOM    	: Mcat.c
CLASSE 	: FS - LaboFS 04-02
#OBJET  : réservé au makefile
AUTEUR	: J.C. Jaumain, 07/2011 - revu mba 1/2015
BUGS	:
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void traitement(int h)
{
	int n;
	char c;
	int i = 0;

	while (( n= read (h, &c, 1)) > 0 && i < 10){
		write(1, &c, 1);
		if(c == '\n'){
			i++;
		}
	}
}

int main ( int argc, char * argv[] )
{	int i,h;
	if ( argc==1) traitement(0);
	else
		for (i=1; i<argc; i++)
		{	h=open(argv[i],O_RDONLY);
			if (h<0){
				perror (argv[i]);
			}
			else {
				traitement(h);
				close(h);
			}
		}
	exit(0);
}
