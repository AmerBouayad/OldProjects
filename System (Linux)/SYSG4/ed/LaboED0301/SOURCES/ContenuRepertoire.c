/*
NOM    	: ContenuRepertoire.c
CLASSE 	: FS - LaboFS 03-01
#OBJET  : réservé au makefile
AUTEUR	: J.C. Jaumain, 07/2011
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
int main ()
{	
	struct dirent *dirp;
	struct dirent *dirpOther;

	DIR *dp;
	DIR *dpOther;

	

	dp=opendir(".");

	printf(" Inode   - Nom\n");
	printf("------------------------------------\n");





	while ((dirp=readdir(dp)) != NULL)
	{ 

		if((dirp->st_mode & S_IFMT) == S_IFREG)
		{
		
			printf("%8d - %s\n",(int)dirp->d_ino,dirp->d_name);
	
		}


		if(S_ISDIR (dirp->st_mode))
		{
		
			dpOther=opendir(dirp.d_name);
		
			while ((dirpOther=readdir(dpOther)) != NULL)
			{
		
				printf("%8d - %s\n", (int)dirpOther->d_ino, dirpOther->d_name);
		
			}
			
		}
	}
	
	closedir(dp);
	exit(0);
}

