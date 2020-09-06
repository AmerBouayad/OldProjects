#include <iostream>
#include <iomanip>
#include "mathesi.h"
#include "surcharge_01.h"
//#include "surcharge_02.h"
//#include "surcharge_03.h"
#include "surcharge_04.h"
#include "random.hpp"
#include "container_utility.hpp"
#include <algorithm>
using namespace std;

void ex4_2();
void ex4_4();
void ex4_5to4_8();
void ex4_9();
void testArrays();
vector<int> vector20();
void ex4_11();
void ex4_12();
void ex4_13();

int main()
{
    ex4_2();
    ex4_4();
    ex4_5to4_8();
    ex4_9();
    ex4_11();
    ex4_12();
    ex4_13();
}

void ex4_2()
{
    cout << "ex 4.2:" << endl;
    int min = 200;
    int max = 349;
    cout << "Les nombres compris entre " << min << " et " << max << endl;
    for (int i = min; i <= max; i++)
    {
        if (isPrime(i))
        {
            cout << right << setw(5) << i;
        }
        else
        {
            cout << right << std::setw(5) << ".";
        }
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}

void ex4_4()
{
    cout << "ex 4.4:" << endl;

    int n = 250;
    for (int i = 1; i <= n; ++i)
    {
        pair<int, int> p = euclidianDivision(n, i);
        cout << n << " = " << setw(3) << p.first << " * " << setw(
                 3) << i << " + " << setw(3) << p.second << endl;
    }
}

void ex4_5to4_8()
{
    std::cout << "Ex. 4.5 - 4.8" << std::endl;
    surcharge_01::main();
    //surcharge02();
    //surcharge03();
    surcharge_04::main();
}

/**
 * Tests the values returned by the random function.
 * Don't forget to call randomize() yourself if you want a random seed.
 * @param nb the number of times to call the random function.
 */
inline void test_Random_values(int nb)
{
    std::cout << "Testing random with " << nb << " values" << std::endl;
    std::array<unsigned, 10> myArray;
    for (unsigned & elem : myArray)
    {
        elem = 0;
    }

    for (int i = 0; i < nb; ++i)
    {
        unsigned r = nvs::random_value(0, 9);
        myArray[r]++;
    }

    std::cout << "Results:" << std::endl;
    int i = 0;
    for (auto elem : myArray)
    {
        std::cout << "Nombre de " << i << ": " << elem << " (" <<
                  ((double)elem / nb) * 100 <<
                  "%)" << std::endl;
        i++;
    }
    std::cout << std::endl;
}

void ex4_9()
{
    cout << "ex 4.9:" << endl;
    testArrays();

    nvs::randomize();
    test_Random_values(10);
    test_Random_values(100);
    test_Random_values(1000);
    test_Random_values(10000);
    test_Random_values(100000);
    cout << endl;
}


void testArrays()
{
    cout << "Playing with arrays: " << endl;
    std::array<unsigned, 10> myArray;
    for (int i = 0; i < 10; ++i)
    {
        myArray[i] = i;
    }
    container_utility::print(myArray);
    cout << endl;
    container_utility::print_generic(myArray);
    cout << endl;
}

/**
 * @brief Creates and returns a vector of 20 elements of type T between min and max.
 * @param min the minimum value.
 * @param max the maximum value.
 */
template<class T>
std::vector<T> vector20(T min, T max)
{
    std::vector<T> data(20);
    /* I'm seeding the urng myself because I want my values to always be
     * the same, for testing purposes. Remove this line and only properly randomize the urng
     * once in the main if you need random values.
     */
    nvs::urng().seed(0);
    auto f = [&]()
    {
        return nvs::random_value(min, max);
    };
    // ce qui précède est nécessaire car la fonction utilisée
    // par generate ne peut pas avoir d’argument
    // cf. http://en.cppreference.com/w/cpp/algorithm/generate
    generate(begin(data), end(data), f);
    return data;
}

void ex4_11()
{
    cout << "ex 4.11:" << endl;
    vector<int> v = vector20<int>(-5, 5);
    container_utility::print(v);
    cout << "tri ascendant: " << endl;
    container_utility::sort(v, true);
    container_utility::print(v);
    cout << "tri descendant: " << endl;
    container_utility::sort(v, false);
    container_utility::print(v);
}

void ex4_12()
{
    cout << "ex 4.12:" << endl;
    std::vector<unsigned> v = vector20<unsigned>(0, 11);
    container_utility::print_generic(v);
    std::cout << "tri ascendant:" << std::endl;
    // we could use std::less but we would like to test lambdas:
    std::sort(v.begin(), v.end(),
              [](unsigned & a, unsigned & b)
    {
        return a < b;
    }
             );
    container_utility::print_generic(v);

    std::cout << "tri descendant:" << std::endl;
    std::sort(v.begin(), v.end(), std::greater<unsigned>() );
    container_utility::print_generic(v);

    std::cout << "tri ascendant modulo 3:" << std::endl;
    std::sort(v.begin(), v.end(),
              [](unsigned & a, unsigned & b)
    {
        return (a % 3) < (b % 3);
    }
             );
    container_utility::print_generic(v);
}

void ex4_13()
{
    cout << "ex 4.13:" << endl;
    std::map<unsigned, unsigned> result = std::map<unsigned, unsigned>();
    for (int i = 1552521051; i < 1552521061; ++i)
    {
        primeFactor(result, i);
        container_utility::print_map(result);
    }
}
