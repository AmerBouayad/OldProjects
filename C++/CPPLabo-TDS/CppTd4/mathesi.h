#ifndef EXO_H
#define EXO_H

#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <utility>

bool isPrime(unsigned number);
void affPrime(unsigned int bInf, unsigned int bSup);
std::pair<int, int> euclidianDivision(int dividend, int divisor);
void printEuclidianDivision(int number);
void print(const std::vector<int> & data);

#endif // EXO_H
