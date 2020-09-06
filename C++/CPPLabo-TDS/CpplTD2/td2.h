#ifndef TD2_H
#define TD2_H

#include "../BouayadAmer42392Td1Dev3l/mathesi.h"

unsigned * primeFactorsA(unsigned * count, unsigned number);
unsigned primeFactorsB(unsigned * * factor,
unsigned * * multiplicity,
unsigned number);

struct PrimeFactor * primeFactorsC(unsigned * count, unsigned number);

struct PrimeFactor
{
unsigned value;
unsigned multiplicity;
};


#endif // TD2_H


