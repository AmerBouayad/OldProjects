#include <tableau.h>
#include <stdio.h>

void arrayIntPrint(const int data[], unsigned nbElem){
    for (unsigned int i =0;i<nbElem; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
}

void arrayIntSort(int data[], unsigned nbElem, bool ascending){

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int tmp = 0;
    if(ascending){
        for(i=0; i<nbElem ; i++)
        {
            for(j=i; j<nbElem; j++)
            {
                if(data[j]<data[i]){
                    tmp = data[i];
                    data[i] = data[j];
                    data[j] = tmp;
                }
            }
        }
    } else{
        for(i=0; i<nbElem ; i++)
        {
            for(j=i; j<nbElem; j++)
            {
                if(data[j]>data[i]){
                    tmp = data[i];
                    data[i] = data[j];
                    data[j] = tmp;
                }
            }
        }
    }
}
