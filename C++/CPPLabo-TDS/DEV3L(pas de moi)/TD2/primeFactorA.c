#include "td2.h"
#include <math.h>
/**
 * @brief primerFactorsA
 * @param count le 2e retour de nombre d'éléments qui se trouve dedans
 * @param number numero to check
 * @return le pointeur d'un tableau avec les valeurs de primes du nombre.
 */

unsigned * primerFactorsA(unsigned * count, unsigned number)
{
    unsigned numDiv = 1;
    unsigned * tabNbPrimes;
    *count = numberElemetsPrime(number);
    tabNbPrimes = malloc(*count * sizeof(unsigned));
    if (tabNbPrimes == NULL) {
        exit(0);
    }
    numDiv = number;
    tabNbPrimes[0] = 1;
    unsigned indice = 2;
    for (unsigned i = 1; i < *count; i++) {
        calculeOnePrime(&indice, &numDiv);
        tabNbPrimes[i] = indice;
    }
    return tabNbPrimes;

}
void calculeOnePrime(unsigned * indice , unsigned * numDiv)
{
    for (; *indice <= *numDiv; ++(*indice)) {
        if (*numDiv % *indice == 0) {
            *numDiv = *numDiv / *indice;
            break;
        }
    }
}
unsigned numberElemetsPrime(unsigned number)
{
    unsigned numDiv;
    unsigned count  = 1;
    if (isPrime(number)&&number>1) {
        count = 2;
    }
    else {
        numDiv = number;
        while (numDiv != 1) {
            for (unsigned i = 2; i <= numDiv ; ++i) {
                if (numDiv % i == 0) {
                    count++;
                    numDiv = numDiv / i;
                    break;
                }
            }
        }
    }
    return count;
}

bool isPrime(unsigned number)
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
