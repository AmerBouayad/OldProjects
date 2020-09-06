#include <stdio.h>
#include <stdio.h>
#include "matesi.h"
#include <stdbool.h>

int main(void)
{

    unsigned nb = 200, nbMax =349;
    printf("Les nombres premiers entre %u et %u :\n", nb,nbMax);
    for(;nb<=nbMax ;++nb){
        if (isPrime(nb)){
            printf("  %u", nb);
        }else{
            printf("    .");
        }
        if((nb+1)%10==0){
            printf("\n");
        }
    }
    return 0;
}
