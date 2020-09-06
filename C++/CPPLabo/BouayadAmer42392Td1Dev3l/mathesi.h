#ifndef MATHESI_H
#define MATHESI_H

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#include <string.h>
#include <stdio.h>


bool isPrime(unsigned int number);
void affPrime(unsigned int bInf, unsigned int bSup);
void printPrimeFactor(unsigned int number, bool showPower);
unsigned gcd(unsigned a, unsigned b);
void td1ex5();
void arrayIntPrint(const int data [], unsigned nbElem);
void arrayIntSort(int data [], unsigned nbElem, bool ascending);
int compare_ints(const void* a, const void* b);
int compare_intsDec(const void* a, const void* b);
int compare_intsMod3(const void* a, const void* b);
void demo(const char* lhs, const char* rhs);
#endif // MATHESI_H
