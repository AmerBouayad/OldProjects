#include <stdio.h>
#include <stdlib.h>
#include "mathesi.h"
#include <math.h>

int main()
{

    // // see https://stackoverflow.com/questions/30088025/c-malloc-invalid-conversion-from-void-to-double
    //    unsigned * tab = malloc(5 * sizeof(int));
    //    tab[0] = 45;
    //    printf("%d\n", tab[0]);

    // Ex 2.1

    printf("Ex 2.1\n");
    unsigned count = 0;

    unsigned * tab = primeFactorsA(&count, 126);

    for (unsigned i = 0; i < count; ++i)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");

    free(tab);

    // Ex 2.2

    printf("Ex 2.2\n");
    unsigned * facteurs = NULL;
    unsigned * multiplicites = NULL;
    unsigned nbElem = primeFactorsB(&facteurs, &multiplicites, 84);


    for (unsigned i = 0; i < nbElem; ++i)
    {
        printf("%d^%d ", facteurs[i], multiplicites[i]);
    }

    printf("\n");

    free(facteurs);
    free(multiplicites);

    // Ex 2.3

    printf("Ex 2.3\n");
    unsigned nbElem2 = 0;
    struct PrimeFactor * decompostion = primefactorsC(&nbElem2, 126);


    for (unsigned i = 0; i < nbElem2; ++i)
    {
        printf("%d^%d ", decompostion[i].value, decompostion[i].multiplicity);
    }

    printf("\n");
    free(decompostion);

    // Ex 2.4

    printf("Ex 2.4\n");

    struct PrimeFactorization f = {126, 0, NULL};
    primeFactorD(&f);

    for (unsigned i = 0; i < f.count ; ++i)
    {
        printf("%d^%d ", f.primeFactors[i].value,
               f.primeFactors[i].multiplicity );
    }
    printf("\n");
    free(f.primeFactors);

    return 0;
}
