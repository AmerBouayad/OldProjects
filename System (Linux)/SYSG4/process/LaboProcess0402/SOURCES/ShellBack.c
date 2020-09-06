/*
NOM    	: ShellBack.c
CLASSE 	: FS - LaboProcess 04-02
#OBJET  : réservé au Makefile
AUTEUR	: J.C. Jaumain, 07/2011
#BUGS	: Pour simplifier, on impose que le symbole & soit le dernier argument sur la ligne de commande (précédé par un espace).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
int main ()
{	int i,r;
	bool bg;
	char *tokens[100];
	char errmsg[200];
	char *ligne;			// pour changer ;-)
	ligne=(char*)malloc(257); 
	printf("$ ");
	fgets(ligne,256,stdin);
	while (strcmp(ligne,"exit\n"))
	{	i=0;
		bg=false;
		tokens[i]=strtok(ligne," \n");
		while (tokens[i] != NULL) tokens[++i]=strtok(NULL," \n");
		if ((i>0) && (strcmp(tokens[i-1],"&")==0))
		{	bg=true;
			tokens[i-1]=0;
		}
		if ((r=fork())==0)
		{	execvp(tokens[0],tokens);
			sprintf (errmsg, "exec <%s> :", tokens[0]);
		    	perror(errmsg);
		}
		if (!bg) waitpid(r,0,0); 
		// sinon attention zombie
		printf("$ ");
		fgets(ligne,256,stdin);
	}
	free (ligne);
	exit(0);
}
