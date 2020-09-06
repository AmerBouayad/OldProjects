#ifndef MATHESI_H
#define MATHESI_H

struct PrimeFactor
{
    unsigned value;
    unsigned multiplicity;
};

struct PrimeFactorization {
    unsigned number;
    unsigned count;
    struct PrimeFactor * primeFactors;
};

unsigned * primeFactorsA(unsigned * count, unsigned number);
unsigned primeFactorsB(unsigned ** factor, unsigned ** multiplicity,
                       unsigned number);
struct PrimeFactor * primefactorsC(unsigned * count, unsigned number);



void primeFactorD(struct PrimeFactorization * pf);


#endif // MATHESI_H
