#include <stdbool.h>
#include <math.h>

bool isPrime(unsigned int number)
{
    if (number == 0 || number == 1) {
        return false;
    }
    if (number == 2) return true;
    unsigned limit = sqrt(number);
    for (unsigned cptNumber = 3; cptNumber <= limit; cptNumber += 2 ) {
        if (number % cptNumber == 0) {
            return false;
        }
    }
    return true;
}
