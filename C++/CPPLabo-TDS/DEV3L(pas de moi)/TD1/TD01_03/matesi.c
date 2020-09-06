#include <stdbool.h>
#include <stdio.h>
#include "matesi.h"
#include "/home/rey/ESI/DEV3L/TD01_01/matesi.h"
#include "/home/rey/ESI/DEV3L/TD01_01/matesi.c"
void printPrimeFactor(unsigned int number, bool showPower){
    printf("%u = ",number);
    unsigned numDiv;
    if (isPrime(number==true)){
        printf("%u\n",number);
    }else{

        numDiv = number;
        while(numDiv != 1){
            for(unsigned i = 2; i<=numDiv; ++i){
                if(numDiv%i==0){
                    printf("%u",i);
                    numDiv = numDiv/i;
                    if(numDiv != 1){
                        printf(" x ");
                    }
                    break;
                }

            }
        }
        printf("\n");
    }
}
//int checkDivisor()

