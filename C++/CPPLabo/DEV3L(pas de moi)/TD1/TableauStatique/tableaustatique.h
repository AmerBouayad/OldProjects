#ifndef TABLEAUSTATIQUE_H
#define TABLEAUSTATIQUE_H
#include <stdbool.h>


void arrayIntPrint(const int data [], unsigned nbElem);
void arrayIntSort(int data [], unsigned nbElem, bool ascending);
void tricroissant( int tab[], unsigned tab_size);
void tridecroissant( int tab[], unsigned tab_size);
int compareCroissant (void const *a, void const *b);
int compareDecroissant (void const *a, void const *b);
void arrayIntSortGeneric(int data [], unsigned nbElem,int (*comp)(const int *, const int *));
#endif // TABLEAUSTATIQUE_H
