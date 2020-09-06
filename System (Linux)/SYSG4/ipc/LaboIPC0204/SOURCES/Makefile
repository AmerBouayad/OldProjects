#NOM    : Makefile
#CLASSE : IPC - LaboIPC 02-04
#OBJET  : demo du programme ProdCons.c
#HOWTO	: make; make clean
#AUTEUR	: J.C. Jaumain, 07/2011

all: prod cons

prod: prod.o opsem.o
	gcc -std=c99 -D _GNU_SOURCE -Wall --pedantic-errors prod.o opsem.o -std=c99 -o prod 
cons: cons.o opsem.o
	gcc -std=c99 -D _GNU_SOURCE -Wall --pedantic-errors cons.o opsem.o -std=c99 -o cons 

opsem.o: opsem.c 
	gcc -std=c99 -D _GNU_SOURCE -Wall --pedantic-errors -c opsem.c -std=c99 -o opsem.o -D _SVID_SOURCE

prod.o: prod.c 
	gcc -std=c99 -D _GNU_SOURCE -Wall --pedantic-errors -c prod.c -std=c99 -o prod.o -D _SVID_SOURCE

cons.o: cons.c 
	gcc -std=c99 -D _GNU_SOURCE -Wall --pedantic-errors -c cons.c -o cons.o -D _SVID_SOURCE

clean:
	rm -f cons prod *~
