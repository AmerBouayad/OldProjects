#include <stdio.h>
#include "matesi.h"

int main(void)
{
    printf("Hello World!\n");
    testGCD();
    return 0;
}

void testGCD(void){
    for(int i = 423; i<=438; i=i+3){
        for(int j = 135; j>=125; j=j-5){
            printf("gcd(%u, %u) =  %u |",i,j,gcd(i,j));
        }
        printf("\n");
    }
}

