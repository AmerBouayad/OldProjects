#include "tableaustatique.h"
#include <stdlib.h>
#include <stdio.h>


void arrayIntSort(int data [], unsigned nbElem, bool ascending){
    unsigned i=0;
    //int tmp=0;
    if (ascending==true)
        tricroissant(data,nbElem);
    else
        tridecroissant(data,nbElem);
    int tmp = data[0];
    for(i = 0; i < nbElem; i++)
      data[i] = data[i+1];
    data[nbElem-1] = tmp;
}
void tricroissant( int tab[], unsigned tab_size)
{
  int i=0;
  int tmp=0;
  int j=0;

  for(i = 0; i < tab_size; i++)
    {
      for(j = 1; j < tab_size; j++)
        {
          if(tab[i] < tab[j])
            {
              tmp = tab[i];
              tab[i] = tab[j];
              tab[j] = tmp;
              j--;
            }
        }
    }
}

void tridecroissant( int tab[], unsigned tab_size)
{
  int i=0;
  int tmp=0;
  int j=0;

  for(i = 0; i < tab_size; i++)
    {
      for(j = 1; j < tab_size; j++)
        {
          if(tab[i] > tab[j])
            {
              tmp = tab[i];
              tab[i] = tab[j];
              tab[j] = tmp;
              j--;
            }
        }
    }
}
