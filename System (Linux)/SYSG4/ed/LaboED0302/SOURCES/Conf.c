/*
NOM    	: Conf.c
CLASSE 	: FS - LaboFS 03-02
#OBJET  : réservé au makefile
AUTEUR	: J.C. Jaumain, 07/2011
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
int main ()
{	char Texte[]="Contenu du fichier Confidentiel : ";
	char c;
	int handle;
	printf ("UID = %d  - EUID = %d\n", getuid(), geteuid());
	handle=open("Confidentiel",O_RDONLY);
	if (handle<0)
	{	perror ("Confidentiel");
		exit(1);
	}

	write(1,Texte,strlen(Texte));
	while(read(handle,&c,1)>0) write(1,&c,1);
	close(handle);
	exit(0);
}
