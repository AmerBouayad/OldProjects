#ifndef MATHESI_H
#define MATHESI_H

#include <utility>
#include <map>
bool isPrime(unsigned number);
std::pair<int, int> euclidianDivision(int dividend, int divisor);
unsigned primeFactor(std::map<unsigned, unsigned> &result, unsigned value);
#endif // MATHESI_H
