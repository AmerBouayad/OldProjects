#include <stdio.h>
#include<stdlib.h>
#include "tableaustatique.h"

int main(int argc, char *argv[])
{
    unsigned nbElem = 4, i = 0;

    int tableau[nbElem];
    for (i = 0 ; i <nbElem ; i++)
    {
    tableau[i] =  (rand() % 20)-10;
    }
    // Ex 1.6
    arrayIntPrint(tableau,nbElem);

    // Ex 1.7
    arrayIntSort(tableau,nbElem,true);
    arrayIntPrint(tableau,nbElem);
    arrayIntSort(tableau,nbElem,false);
    arrayIntPrint(tableau,nbElem);

    // EX 1.8
    // Croissant
    int tableau2[] = { -2, 99, 0, -743, 2, 4 };
    int size2 = sizeof tableau2 / sizeof *tableau2;
    qsort(tableau2,size2, sizeof(tableau[0]), &compareCroissant);
    arrayIntPrint(tableau2, size2);

    // Decroissant
    int tableau3[] = { -2, 99, 0, -743, 2, 4 };
    int size3 = sizeof tableau3 / sizeof *tableau3;
    qsort(tableau3,size3, sizeof(tableau[0]), &compareDecroissant);
    arrayIntPrint(tableau3, size3);
    //Croissant Modulo 3?




    return 0;
}
