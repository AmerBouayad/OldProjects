
int main(int argc, char *argv[]) {
    /*unsigned nbElem = 0;
    unsigned * tab = primeFactorsA(&nbElem, 84);
    for (unsigned int i = 0; i < nbElem; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    free(tab);*/

    unsigned * facteurs = NULL;
    unsigned * multiplicites = NULL;
    unsigned nbElem = primeFactorsB(&facteurs, &multiplicites, 84);

    for (unsigned int i = 0; i < nbElem; i++) {
        printf("%d ", facteurs[i]);
    }
    printf("\n");
    for (unsigned int i = 0; i < nbElem; i++) {
        printf("%d ", multiplicites[i]);
    }
    printf("\n");

    free(facteurs);
    free(multiplicites);

    /*unsigned nbElem = 0;
    struct PrimeFactor * decomposition = primeFactorsC(&nbElem, 84);

    for (unsigned int i = 0; i < nbElem; i++) {
        printf("{%d,%d} ", decomposition[i].value, decomposition[i].multiplicity);
    }
    printf("\n");
    free(decomposition);*/
    return 0;
}



