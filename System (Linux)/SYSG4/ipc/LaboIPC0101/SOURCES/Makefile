#NOM    : Makefile
#CLASSE : IPC - LaboIPC 01-01
#OBJET  : demo du programme FreeShm.c
#HOWTO	: make; make clean
#AUTEUR	: J.C. Jaumain, 07/2011

all: FreeShm AlloueShm
FreeShm: FreeShm.c 
	gcc -std=c99 -D _GNU_SOURCE -Wall --pedantic-errors FreeShm.c -o FreeShm

AlloueShm: AlloueShm.c 
	gcc -std=c99 -D _GNU_SOURCE -Wall --pedantic-errors AlloueShm.c -o AlloueShm

clean:
	rm -f FreeShm AlloueShm *~
