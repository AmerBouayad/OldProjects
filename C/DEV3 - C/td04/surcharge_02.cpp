/*!
 * \file surcharge_02.cpp
 * \brief surcharge de fonctions
 */
#include <iostream>

namespace surcharge_02
{
void f(int a)
{
    std::cout << "f(int): " << a <<  std::endl;
}

void f(long double a)
{
    std::cout << "f(long double): " << a << std::endl;
}

int main()
{
    std::cout << "surcharge_02" << std::endl;

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
