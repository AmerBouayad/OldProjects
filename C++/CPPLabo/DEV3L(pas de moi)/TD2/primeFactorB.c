#include "td2.h"
#include <math.h>
unsigned primeFactorsB(unsigned * * factor,
                       unsigned * * multiplicity,
                       unsigned number)
{
    unsigned cpt = 0;
    unsigned nbElem = 0;
    unsigned numDiv;
    * factor = malloc(sizeof(unsigned));
    * multiplicity = malloc(sizeof(unsigned));

    numDiv = number;
    for (unsigned i = 2; i <= numDiv; i++)
    {
        while (numDiv % i == 0)
        {
            numDiv = numDiv / i;
            cpt++;
        }
        if (cpt > 0)
        {
            nbElem++;
            *factor = realloc(*factor, sizeof(unsigned) * nbElem);
            *multiplicity = realloc(*multiplicity, sizeof(unsigned) * nbElem);
            *(*factor + (nbElem - 1)) = i;
            *(*multiplicity + (nbElem - 1)) = cpt;
        }
        cpt = 0;
    }
    return nbElem;

}
