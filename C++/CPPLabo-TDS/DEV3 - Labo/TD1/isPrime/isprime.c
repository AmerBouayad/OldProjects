#include <isprime.h>
#include <math.h>
#include <stdio.h>

bool isPrime(unsigned int n)
{

    int i=2;
    bool prime = true;
    int m = sqrt(n);
    if (n > 1)
        while ((i<= m) && (prime))
        {
            if (n%i == 0)
                prime = false;
            else
                i++;
        }
    else
        prime = false;
    return prime;
}

void printPrimeFactor(unsigned int number, bool showPower)
{
    unsigned int i = 2;
    unsigned int power;
    if(!isPrime(number)){
        while( number > 1){
            if(showPower){
                power = 0;
                while (number %i ==0){
                    number = number/i;
                    power++;
                }
                if (power == 1){
                    printf("%d", i);
                } else if(power != 0){
                    printf("%d^%d", i, power);
                }
                if(number !=1 && power !=0){
                    printf(" * ");
                }
                i = nextPrime(i);

            } else {
                if(number %i ==0){
                    number = number/ i;
                    printf("%d", i);
                    if(number != 1){
                        printf(" * ");
                    }
                } else {
                    i = nextPrime(i);
                }
            }
        }
    } else {
        printf("Le nombre n'est divisible que par lui meme");
    }
}

int nextPrime(unsigned int number) {
    number++;
    while(!isPrime(number)){
        number++;
    }
    return number;
}

unsigned gcd(unsigned a, unsigned b){
    unsigned int r;
    unsigned int c;
    while (r>0){
        if ( a < b){
            c = a;
            a = b;
            b = c;
        }
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void printGcd(unsigned a, unsigned b){
    unsigned int x = a;
    unsigned int y = b;
    for (int i = 0; i<6;i++){
        for (int j=0; j<3;j++){
            printf("gcd(%3d, %3d) = %2d", x,y,gcd(x,y));

            if(j != 2)
                printf(" | ");

            y = y-5;
        }
        printf("\n");
        x = x +3;
        y = b;
    }
}

