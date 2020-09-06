/*!
 * \file surcharge_04.cpp
 * \brief surcharge de fonctions
 */
#include <iostream>

namespace surcharge_04
{
void f(int a)
{
    std::cout << "f(int): " << a << std::endl;
}

void f(unsigned a)
{
    std::cout << "f(unsigned): " << a << std::endl;
}

void f(long long a)
{
    std::cout << "f(long long): " << a << std::endl;
}

void f(double a)
{
    std::cout << "f(double): " << a << std::endl;
}

void f(long double a)
{
    std::cout << "f(long double): " << a << std::endl;
}

int main()
{
    std::cout << "surcharge_04" << std::endl;

    f(3);
    f(4.5);
    f(true);
    f(3LL);
    f('T');
    f(.3F);
    f(5U);
    short s {44};
    f(s);
    f(2e-2L);
}
}
