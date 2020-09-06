#include <stdio.h>
#include "matesi.h"
#include <stdbool.h>
int main(void)
{
    printPrimeFactor2(1526, true);
    printPrimeFactor2(1526, false);
    printf("\n");
    printPrimeFactor2(8343584, true);
    printPrimeFactor2(8343584, false);
    printf("\n");
    printPrimeFactor2(126, true);
    printPrimeFactor2(126, false);
    printf("\n");
    printPrimeFactor2(75, true);
    printPrimeFactor2(75, false);
    return 0;
}

