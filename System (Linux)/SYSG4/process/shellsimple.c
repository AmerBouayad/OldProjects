#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(void)
{	int i;
	char ligne[257];
	char *tokens[100];
	printf("$ ");
	fgets(ligne,256,stdin);
	while (strcmp(ligne,"exit\n"))
	{	i = 0;
		tokens[i] = strtok(ligne," \n");
		while (tokens[i] != NULL)
			tokens[++i] = strtok(NULL," \n");
		if (fork()==0)
			execvp(tokens[0], tokens);
		wait(0);
		printf("$ ");
		fgets(ligne,256,stdin);
	}
	exit(0);
}
 
