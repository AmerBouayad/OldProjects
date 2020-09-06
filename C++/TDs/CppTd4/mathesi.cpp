#include "mathesi.h"

using namespace std;

//ex 1
bool isPrime(unsigned number){
    if(number<=1 || (number%2==0 && number != 2))
        return false;
    if(number== 2 || number==3)
        return true;

    unsigned int diviseur=3;
    unsigned int limite=(unsigned int)(sqrt(number));

    while(diviseur<=limite){
        if(number%diviseur==0)
            return false;
        diviseur=diviseur+2;
    }
    return true;
}

//ex 2
void affPrime(unsigned int bInf, unsigned int bSup){
    cout<< "Les nombres premiers entre " << bInf << " et " << bSup << endl;
    unsigned int cpt = 0;
    for (unsigned int nb = bInf; nb<=bSup; nb++){
        cpt++;
       if(isPrime(nb)){
            cout << nb;
       }else{
            cout <<" . ";
       }
       if (cpt==10){
        cpt = 0;
        cout << "" << endl;
       }
    }
}

//ex 3
pair<int, int> euclidianDivision(int dividend, int divisor){
   pair < int, int > result;
   if(divisor == 0){
       throw domain_error( "Le diviseur est nul !" );
   }
    result.first = dividend / divisor;
    result.second = dividend % divisor;
    return result;
}

//ex 4
void printEuclidianDivision(int number){
    cout << "euclidianDivision : division by zero" << endl;
    for(unsigned int i = 1; i <= number; i++){
        pair<int, int> result = euclidianDivision(number, i);
        cout << number << " = " << result.first << " * " << i << " + " << result.second << endl;
    }
}
//ex 10
void print(const std::vector<int> & data){

}
