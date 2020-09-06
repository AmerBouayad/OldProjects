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

int main(int argc, char * argv []){ 
int r;
printf ("Je␣suis␣le␣processus␣père␣%d\n",getpid());
if ((r=fork()) == 0){ // père temporaire
	if ( (r=fork()) == 0){
		usleep (1); // pourquoi ?
		printf ("Je suis le fils non attendu :(␣%d,␣"
		"mon␣père␣est␣le␣%d\n", getpid(),getppid());
		exit (0);
	}else{
		exit (0);// mon fils sera adopté
	}
}
wait (0); // wait père temporaire
printf("*********");
while(1);
exit (0);
}
