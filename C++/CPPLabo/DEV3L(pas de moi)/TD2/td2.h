#ifndef TD2_H
#define TD2_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

unsigned * primerFactorsA(unsigned * count, unsigned number);
void calculeOnePrime(unsigned * indice , unsigned * numDiv);
unsigned numberElemetsPrime(unsigned number);
bool  isPrime(unsigned number);
unsigned primeFactorsB(unsigned ** factor,
                       unsigned * * multiplicity,
                       unsigned number);

#endif // TD2_H

