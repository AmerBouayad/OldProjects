#ifndef TD4_H
#define TD4_H

#include <math.h>
#include <iostream>
#include <random.h>
#include <array>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

bool isPrime(unsigned number);
void printNumbers(unsigned int n1, unsigned int n2);

std::pair<int, int> euclidianDivision(int dividend, int divisor);
void print(const std::vector<int> & data);
void sort(std::vector<int> & data, bool ascending);
bool compareModulo(int a, int b);

unsigned primeFactor(std::map<unsigned, unsigned> &result, long value);
int nextPrime(unsigned int number);

void printFactor (std::map<unsigned,unsigned> &result, unsigned nbElem, long nb);

#endif // TD4_H
