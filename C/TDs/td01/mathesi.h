#ifndef MATHESI_H
#define MATHESI_H

#include <stdbool.h>

bool isPrime(unsigned int number);

void printPrimeFactor(unsigned int number, bool showPower);
void printPrimeFactorPowered(unsigned int number);
void printPrimeFactorUnpowered(unsigned int number);
unsigned gcd(unsigned a, unsigned b);

void printArray(int* array, int len);
#endif // MATHESI_H
