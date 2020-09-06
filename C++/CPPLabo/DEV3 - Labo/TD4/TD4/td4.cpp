#include <td4.h>


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

void printNumbers(unsigned int n1, unsigned int n2){
    unsigned int j =0;
    for(unsigned int i = n1; i<=n2; i++){
        if (j%10 == 0){
            cout << "" << endl;
        }
        if(isPrime(i)){
            cout << i ;
        } else {
            cout << " . ";
        }
        j++;
    }
    cout << "\n" << endl;
}

std::pair<int, int> euclidianDivision(int dividend, int divisor){
    if (divisor ==0){
        throw domain_error("Division par zero");
    }
    pair<int,int> p1(dividend/divisor,dividend%divisor);
    return p1;

}

void print(const std::vector<int> &data){

    for (int i : data){
        cout << i << " " ;
    }
    cout << " " << endl;
}

void sort(std::vector<int> &data, bool ascending){
    if(ascending){
        std::sort(data.begin(),data.end());
    } else {
        //std::sort(data.rbegin(),data.rend());
        std::sort(data.begin(), data.end(), std::greater<int>());
    }
}

bool compareModulo(int a, int b){
    return a%3 < b%3;
}

unsigned primeFactor(std::map<unsigned, unsigned> &result, long value){

    if(isPrime(value)){
        return 0;
    } else {
        unsigned int i = 2;
        unsigned int pow;
        while(value > 1){
            pow = 0;
            if(value %i ==0){
                while (value %i ==0){
                    value = value/i;
                    pow++;
                    result[i] = pow;
                }
            } else {
                i = nextPrime(i);
            }

        }
    }
    return result.size();
}

int nextPrime(unsigned int number) {
    number++;
    while(!isPrime(number)){
        number++;
    }
    return number;
}

void printFactor(std::map<unsigned, unsigned> &result, unsigned nbElem, long nb){

    if (nbElem != 0){
        unsigned int j = 0;
        cout << nb << " = " ;
        for (const auto &p : result){
            if (p.second != 1)
            cout << p.first << "^" << p.second;
            else
                cout <<p.first ;
            if (j <nbElem-1) {
                cout << " * " ;
            } else {
                cout << "\n";
            }
            j++;
        }
    } else {
        cout << nb << " = " << nb << endl;
    }
}
