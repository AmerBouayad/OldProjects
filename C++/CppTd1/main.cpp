#include "mathesi.h"
#include "random.hpp"
#include <array>

using namespace std;
using namespace nvs;

int main(int argc, char *argv[])
{
    //ex 1
    //cout << boolalpha << isPrime(7) << endl;

    //ex 2
    //affPrime(200, 349);

    //ex 3
    /*
    try
      {
        pair < int, int > result = euclidianDivision(0,0);
        cout << result.first << " " << result.second <<endl;
      }
      catch (exception &e)
      {
         cerr << "Erreur: " << e.what( ) << endl;
      };

    */

    //ex 4
    //printEuclidianDivision(27);

    //ex 9
    std::array<unsigned, 10> tab = {0};
    unsigned total = 0;
    double occurence = 4000000;
    for(unsigned i = 0; i < occurence; i++){
        unsigned random = random_value(9,0);
        tab[random] = tab[random] + 1;
    }
    for(unsigned i = 0; i < 10; i++){
        total = total + tab[i];
        cout << "nombre de " << i << " : " << tab[i] << " (" << 100.0 *tab[i]/occurence << " %)" << endl;
    }
        cout << "total       : " << total << " (" << 100 *total/occurence << " %)" << endl;

    //ex 12 : c): lambda expression
      return 0;
}

