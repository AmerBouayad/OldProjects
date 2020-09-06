/*
NOM    	: FichierCreux.c
CLASSE 	: FS - LaboFS 02-02
#OBJET  : réservé au makefile
AUTEUR	: J.C. Jaumain, 07/2011
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
int main ()
{	char bufA[]="H";
	char bufB[]="B";
	int handle;
	handle=open("FichCreux.dat",O_WRONLY|O_CREAT,0644);
	if (handle < 0){
		perror ("FichierCreux.dat");
		exit(1);
	}

	write(handle,bufA,strlen(bufA));
	lseek(handle,28000,SEEK_SET);
	write(handle,bufB,strlen(bufB));
	close(handle);
	exit(0);
}
