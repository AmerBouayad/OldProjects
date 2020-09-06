#include <mathesi.h>
#include <math.h>

bool isPrime(unsigned int n)
{

    bool ok = true;
    int m = sqrt(n);
    int i = 2;
    if (n > 1)
        while( i<= m && ok){
            if (n%i == 0)
              ok = false;
         else
             i++;
    }
    else
        prime = false;
    return ok;
}
