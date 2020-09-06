#include "td2.h"

unsigned * primeFactorsA(unsigned * count, unsigned number){
    unsigned * tab = malloc(sizeof(int));
    unsigned int restant = number;
    unsigned int nb = 2;
    while(nb<=restant){
        if(restant%nb==0){
            *count = *count +1;
            tab = realloc(tab, *count * sizeof(int));
            tab[*count - 1] = nb;
            restant = restant/nb;
        }else{
            nb++;
        }
    }
    return tab;
}

unsigned primeFactorsB(unsigned * * factor,unsigned * * multiplicity,unsigned number){
    *factor = malloc(sizeof(int));
    *multiplicity = malloc(sizeof(int));
    unsigned int restant = number;
    unsigned int nb = 2;
    unsigned int cpt = 0;
    unsigned int prevNb;
    unsigned int nbElem = 0;
    while(nb<=restant){
        if(restant%nb==0){
            prevNb = nb;
            while(restant%nb==0){
                cpt++;
                restant = restant/nb;
            }
            nbElem = nbElem + 1;
            *multiplicity = realloc(*multiplicity, nbElem * sizeof(int));
            *factor = realloc(*factor, nbElem * sizeof(int));
            *(*factor + nbElem - 1) = prevNb;
            *(*multiplicity + nbElem - 1) = cpt;
            cpt=0;
        }else{
            nb++;
        }
    }
    return nbElem;
}

struct PrimeFactor * primeFactorsC(unsigned * count, unsigned number){
    struct PrimeFactor * decomposition = malloc(sizeof(struct PrimeFactor));
    unsigned int restant = number;
    unsigned int nb = 2;
    unsigned int cpt = 0;
    unsigned int prevNb;
    while(nb<=restant){
        if(restant%nb==0){
            prevNb = nb;
            while(restant%nb==0){
                cpt++;
                restant = restant/nb;
            }
            *count = *count + 1;;
            decomposition = realloc(decomposition, *count * sizeof(struct PrimeFactor));
            struct PrimeFactor pf = {prevNb, cpt};
            decomposition[*count - 1] = pf;
            cpt=0;
        }else{
            nb++;
        }
    }
    return decomposition;
}

