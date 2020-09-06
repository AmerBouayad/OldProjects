#include <stdio.h>
#include "mathesi.h"
#include <math.h>

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

// TODO: consider having a seperate function to display
void printPrimeFactor(unsigned int number, bool showPower)
{
    if(number == 1) {
        printf("1");
    }
    if(showPower) {
        printPrimeFactorPowered(number);
    } else {
        printPrimeFactorUnpowered(number);
    }
    //printf("\n");
}

void printPrimeFactorPowered(unsigned int number)
{
    int div = 2;
    int power = 0;
    while(number > 1) {
        while (number % div == 0) {
            number /= div;
            power++;
        }
        if (power == 1) {
            printf("%d", div);
        } else if (power > 1) {
            printf("%d^%d", div, power);
        }
        div++;
        if(number != 1 && power > 0) {
            printf(" x ");
        }
        power = 0;
    }
    printf("\n");
}

void printPrimeFactorUnpowered(unsigned int number)
{
    int div = 2;
    while(number > 1) {
        if(number % div == 0) {
            printf("%d", div);
            number /= div;
            if(number != 1) {
                printf(" x ");
            }
        } else {
            div++;
        }
    }
    printf("\n");
}

// TODO: do a recursive call (if b == 0 return a else return gcd(b, a%b) )
unsigned gcd(unsigned a, unsigned b)
{
    int tmp;
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    tmp = a % b;
    while (tmp != 0)
    {
        a = b;
        b = tmp;
        tmp = a % b;
    }
    return b;
}



