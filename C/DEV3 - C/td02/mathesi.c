#include <math.h>
#include <mathesi.h>
#include <stdlib.h>

unsigned * primeFactorsA(unsigned * count, unsigned number)
{
    unsigned * tab = malloc((int)(sqrt(number)) * sizeof(unsigned));
    *count = 0;
    int div = 2;
    while (number > 1)
    {
        while (number % div == 0)
        {
            number /= div;
            tab[*count] = div;
            (*count)++;
        }
        div++;
    }
    return tab;
}

unsigned primeFactorsB(unsigned ** factor, unsigned ** multiplicity,
                       unsigned number)
{

    *factor = malloc( ((int) sqrt(number)) * sizeof(unsigned));
    *multiplicity = malloc( ((int) sqrt(number)) * sizeof(unsigned));

    int div = 2;
    int count = 0;
    while (number > 1)
    {
        if (number % div == 0 )
        {
            multiplicity[0][count] = 0;
            factor[0][count] = div;
            while (number % div == 0)
            {
                number /= div;
                (multiplicity[0][count])++;
            }
            count++;
        }
        div++;
    }
    return count;
}

struct PrimeFactor * primefactorsC(unsigned * count, unsigned number)
{
    struct PrimeFactor * tab = malloc( (int)(sqrt(number)) * sizeof(unsigned));

    int div = 2;
    *count = 0;
    while (number > 1)
    {
        if (number % div == 0 )
        {
            tab[*count].multiplicity = 0;
            tab[*count].value = div;
            while (number % div == 0)
            {
                number /= div;
                tab[*count].multiplicity++;
            }
            (*count)++;
        }
        div++;
    }
    return tab;

}

void primeFactorD(struct PrimeFactorization *pf)
{
    pf -> primeFactors = primefactorsC(& (pf -> count), pf -> number);
}
