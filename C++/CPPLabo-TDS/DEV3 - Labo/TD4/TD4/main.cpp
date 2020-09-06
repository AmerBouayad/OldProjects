#include <td4.h>

int main()
{

    // cout << isPrime(84) << endl;
    // printNumbers(200,349);

    /*pair<int,int> p1;
    int dividend = 27;
    int divisor = 1;
    for (int i = divisor; i <= dividend; i++){
        p1 = euclidianDivision(dividend,i);
        cout << dividend << " = " << p1.first << " * " << i << " + "<< p1.second<< endl;
    }*/


    /*unsigned int total = 1000000;
    array<unsigned, 10> a;
    for (int i = 0; i<10; i++){
        a[i] = 0;
    }
    nvs::randomize();
    int n ;
    for(unsigned int i =0; i<total;i++){
        n = nvs::random_value(0,9);
        a[n]= a[n] + 1;
    }

    double max = 0;
    for (unsigned int i = 0; i <10; i++){
        cout << "nombre de " << i << " : " << a[i] << " (" << setprecision(9) << ((double)a[i]/(double)total)*100 << " %)" << endl;
        max = max + ((double)a[i]/(double)total)*100;
    }
    cout << "total :              " <<max << endl;
    */


    /*vector<int> data(20);
    auto f = []()
    {
    return nvs::random_value(-5, 5);
    };

    generate(begin(data), end(data), f);
    print(data);
    sort(data, false);
    print(data);
    std::sort(data.begin(), data.end(), compareModulo);
    print(data);
    */

    for (unsigned int i = 1552521051; i <= 1552521060; i++){
        std::map<unsigned, unsigned> result;
        unsigned int nbElem = primeFactor(result, i);
        printFactor(result, nbElem, i);
    }
    /*unsigned long nb = 1552521053;
    std::map<unsigned, unsigned> result1;
    unsigned int nbElem1 = primeFactor(result1, 1552521051);
    printFactor(result1, nbElem1, 1552521051);
    std::map<unsigned, unsigned> result2;
    unsigned int nbElem2 = primeFactor(result2, 1552521052);
    printFactor(result2, nbElem2, 1552521052);
    std::map<unsigned, unsigned> result3;
    unsigned int nbElem3 = primeFactor(result3, nb);
    printFactor(result3, nbElem3, nb);
    std::map<unsigned, unsigned> result4;
    unsigned int nbElem4 = primeFactor(result4, 1552521054);
    printFactor(result4, nbElem4, 1552521054);
    std::map<unsigned, unsigned> result5;
    unsigned int nbElem5 = primeFactor(result5, 1552521055);
    printFactor(result5, nbElem5, 1552521055);
    std::map<unsigned, unsigned> result6;
    unsigned int nbElem6 = primeFactor(result6, 1552521056);
    printFactor(result6, nbElem6, 1552521056);
    std::map<unsigned, unsigned> result7;
    unsigned int nbElem7 = primeFactor(result7, 1552521057);
    printFactor(result7, nbElem7, 1552521057);
    std::map<unsigned, unsigned> result8;
    unsigned int nbElem8 = primeFactor(result8, 1552521058);
    printFactor(result8, nbElem8, 1552521058);
    std::map<unsigned, unsigned> result9;
    unsigned int nbElem9 = primeFactor(result9, 1552521059);
    printFactor(result9, nbElem9, 1552521059);
    std::map<unsigned, unsigned> result10;
    unsigned int nbElem10 = primeFactor(result10, 1552521060);
    printFactor(result10, nbElem10, 1552521060);
    cout << isPrime(36964787) << endl;*/

    return 0;
}
