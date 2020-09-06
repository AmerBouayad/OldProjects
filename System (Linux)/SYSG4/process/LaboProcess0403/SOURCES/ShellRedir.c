/*
NOM    	: ShellBack.c
CLASSE 	: FS - LaboProcess 04-03
#OBJET  : réservé au Makefile
AUTEUR	: J.C. Jaumain, 07/2011
#BUGS	: Pour simplifier, on impose que le symbole > soit l'avant dernier mot de la ligne de
#	: commande, le dernier mot étant le nom du fichier.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
int main ()
{	int i,h;
	char * ligne;
	char *tokens[100];
	ligne=(char*)malloc(300);
	printf("$ ");
	fgets(ligne,256,stdin);
	while (strcmp(ligne,"exit\n"))
	{	i=0;
		tokens[i]=strtok(ligne," \n");
		while (tokens[i] != NULL) tokens[++i]=strtok(NULL," \n");
		if (fork()==0)
		{	if ((i>1) && (strcmp(tokens[i-2],"<")==0))
			{	h=open(tokens[i-1],O_RDONLY);
				dup2(h,0);
				close(h);
				tokens[i-2]=0;
			}
			execvp(tokens[0],tokens);
			perror("exec");
		}
		wait(0);
		printf("$ ");
		fgets(ligne,256,stdin);
	}
	free (ligne);
	exit(0);
}

