#include <stdbool.h>

bool isPrime(unsigned int number){
    if(number==0 || number==1){
        return false;
    }

    for(unsigned cptNumber=2; cptNumber < number; cptNumber++ ){
        if(number%cptNumber==0){
            return false;
        }
    }
    return true;
}
