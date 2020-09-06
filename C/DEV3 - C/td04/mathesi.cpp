#include <math.h>
#include "mathesi.h"
#include <stdexcept>
bool isPrime(unsigned int number)
{
    int div = 2;
    int result = number % div;

    while (div < sqrt(number) && result != 0)
    {
        div++;
        result = number % div;
    }
    return (div > sqrt(number));
}

std::pair<int, int> euclidianDivision(int dividend, int divisor)
{
    if (divisor == 0)
        throw std::domain_error("division by 0!");
    return std::pair<int, int>(dividend / divisor, dividend % divisor);
}

unsigned primeFactor(std::map<unsigned, unsigned> &result, unsigned value)
{
    unsigned initial_value = value;
    unsigned div = 2;
    result.clear();
    while (value > 1 && div <= sqrt(initial_value)) {
        while (value % div == 0) {
            value /= div;
            auto a = result.find(div);
            if (a != result.end()) {
                (std::get<1>(*a))++; // TODO: use first and second
            } else {
                result.emplace(std::make_pair(div, 1));
            }
        }
        div++;
    }
    if(result.size() == 0) { // we have a prime number
        result.emplace(std::make_pair(value, 1));
    }
    return result.size();
}
