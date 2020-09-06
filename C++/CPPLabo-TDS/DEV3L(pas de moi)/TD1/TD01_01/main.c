#include <stdio.h>
#include <stdio.h>
#include "matesi.h"
#include <stdbool.h>

// La taille des types n'est pas specifié.
// int est type le plus rapide, il petmet les lecture et les ecritures en mémoire les plus performantes.
// Unsigned veut dire que la valeur va étre de 0  à 255.
// Si on écrit seulement unsigned (= unsigned int))
// le type bool: est un alias car il n'ezst pas une variable car il est defini dans le fichier stdbool.h
// 3==2 en C/c++ est un entier
// int i = (3==2) -> alors i = 0 car c'est faux
// si on a une expression et il est false alors il vaut 0


int main(void)
{
    printf("Hello World!\n");
    unsigned nb = 7;
    if (isPrime(nb)) {
        printf("%u is prime", nb);
    } else {
        printf("%u is not prime", nb);
    }
    printf("\n");
    return 0;
}
