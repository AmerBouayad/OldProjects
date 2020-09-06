#NOM    : Makefile
#CLASSE : Intro - LaboIntro 01-02
#OBJET  : autour du Makefile
#HOWTO	: make
#AUTEUR	: mba 01/2016
#
 
Test:TestMake2
	@# Comment exécuter le programme TestMake2
	@echo "vous pouvez exécuter votre programme TestMake2 avec un paramètre numérique. Exemple ./TestMake2 5"


TestMake2 : TestMake2.c  MonInclude.h boucle.c boucle.h

	@# compiler le programme
	gcc -std=c99  -Wall -pedantic TestMake2.c -c -o TestMake2.o  	

	@# compile TestMake2.c (compilation séparée produit le fichier objet)
	@# compilation séparée de boucle.c 
	@# (pas de fonction main) produit l'objet
	gcc -std=c99 -Wall  -pedantic boucle.c -c -o boucle.o	 	

	@# édition des liens TestMake2.o et boucle.o 
	@# produit l'exécutable TestMake2
	gcc TestMake2.o boucle.o -o TestMake2	

clean:
	@# supprime les fichiers objet, l'exécutable 
	@# et les fichiers temporaires
	@rm -f TestMake2 *.o  *~


