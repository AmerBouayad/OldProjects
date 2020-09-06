#include "td2.h"

int main(void)
{
    printf("\n---------------2.1--------------\n");
    unsigned nbElem = 0;

    unsigned * decomposition = primerFactorsA(&nbElem, 2);
    for(unsigned i = 0; i < nbElem; ++i){
        printf("%u ", decomposition[i]);
    }
    printf("\n");
    printf("\n---------------2.2--------------\n");
    unsigned * facteurs = NULL;
    unsigned * multiplicites = NULL;
    unsigned nbElem2 = primeFactorsB(&facteurs, &multiplicites, 104);
    for(unsigned i = 0; i < nbElem2; ++i){
        printf("%u ", facteurs[i]);
    }
    printf("\n");
    for(unsigned i = 0; i < nbElem2; ++i){
        printf("%u ", multiplicites[i]);
    }
    printf("\n");
    printf("\n---------------2.3--------------\n");
    return 0;
}

