#include <stdio.h>
#include "matesi.h"

unsigned gcd(unsigned a, unsigned b){
    unsigned max, min, reste;

    if(a<b){
        max=b;
        min=a;
    }else if(a>b) {
        max=a;
        min=b;
    }else{
        return a;
    }

    reste = min;
    do{
    reste = max%min;
    max=min;
    min = reste;
    }while(reste!=0);
    return max;
}
