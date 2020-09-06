/*
NOM    	: ShellBackZ.c
CLASSE 	: Process - LaboProcess 06-03
#OBJET  : réservé au Makefile
AUTEUR	: J.C. Jaumain, 07/2011
	: M.Bastreghi, 03/2017 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
void fwait(int s);
int main ()
{	int i,bg,r;
	char * ligne;
	char *tokens[100];
	ligne=(char*)malloc(300);
	printf("$ ");
	fgets(ligne,256,stdin);
	while (strcmp(ligne,"exit\n"))
	{	i=0;
		bg=0;
		tokens[i]=strtok(ligne," \n");
		while (tokens[i] != NULL) tokens[++i]=strtok(NULL," \n");
		if ((i>0) && (strcmp(tokens[i-1],"&")==0))
		{	bg=1;
			tokens[i-1]=0;
		}
		if ((r=fork())==0)
		{	execvp(tokens[0],tokens);
			printf("Commande invalide\n");
			exit(1);
		}
		if (bg==0) waitpid(r,0,0);
		printf("$ ");
		fgets(ligne,256,stdin);
	}
	exit(0);
}

