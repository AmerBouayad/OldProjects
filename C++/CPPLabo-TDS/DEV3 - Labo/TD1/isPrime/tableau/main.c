#include <stdio.h>
#include <stdlib.h>
#include <tableau.h>

int main()
{
    int data [6] = {0,2,1,3,4,7};
    //unsigned int nbElem = 4;
    //unsigned int tmp;
    //arrayIntPrint(data,6);
    //arrayIntSort(data, nbElem, false);
    //arrayIntPrint(data,6);
    qsort(data,4,sizeof(int), );
    arrayIntPrint(data,4);
    return 0;
}
