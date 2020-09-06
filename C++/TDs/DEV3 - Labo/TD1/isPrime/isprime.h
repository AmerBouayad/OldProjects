#ifndef ISPRIME_H
#define ISPRIME_H

#include <stdbool.h>

bool isPrime(unsigned int n);
void printPrimeFactor(unsigned int number, bool showPower);
int nextPrime(unsigned int i);
unsigned gcd(unsigned a, unsigned b);
void printGcd(unsigned a, unsigned b);

#endif // ISPRIME_H
