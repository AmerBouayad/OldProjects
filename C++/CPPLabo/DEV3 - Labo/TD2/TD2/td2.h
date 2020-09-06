#ifndef TD2_H
#define TD2_H
#include <stdio.h>
#include <stdlib.h>

unsigned * primeFactorsA(unsigned * count, unsigned number);
unsigned primeFactorsB(unsigned * * factor,unsigned * * multiplicity,unsigned number);
struct PrimeFactor * primeFactorsC(unsigned * count, unsigned number);

struct PrimeFactor{
    unsigned value;
    unsigned multiplicity;
};

struct PrimeFactorization
{
unsigned number;
unsigned count;
struct PrimeFactor * primeFactors;
};

void primeFactorsD(struct PrimeFactorization * pf);

#endif // TD2_H
