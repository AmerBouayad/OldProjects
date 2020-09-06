#include <td2.h>
int main(){

    /*unsigned * facteurs = NULL;
    unsigned * multiplicites = NULL;
    unsigned nbElem = primeFactorsB(&facteurs, &multiplicites, 84);
    for (unsigned int i = 0; i < nbElem; i++){
        printf("%d ", facteurs[i]);
    }
    printf("\n");
    for (unsigned int i = 0; i < nbElem; i++){
        printf("%d ", multiplicites[i]);
    }
    printf("\n");
    free(facteurs);
    free(multiplicites);
    return 0;

    unsigned nbElem =0;
    struct PrimeFactor *decomposition = primeFactorsC(&nbElem, 84);
    for (unsigned int i = 0; i < nbElem; i++){
        printf("{%d,%d} ", decomposition[i].value, decomposition[i].multiplicity);
    }
    printf("\n");
    free(decomposition);
    return 0;*/

    struct PrimeFactorization f = { 84, 0, NULL };
    primeFactorsD(&f);

    return 0;

}
