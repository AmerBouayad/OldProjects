/*!
 * \file surcharge_03.cpp
 * \brief surcharge de fonctions
 */
#include <iostream>


namespace surcharge_03
{
void f(short a)
{
    std::cout << "f(short): " << a <<  std::endl;
}

void f(double a)
{
    std::cout << "f(double): " << a << std::endl;
}

int main()
{
    std::cout << "surcharge_03" << std::endl;

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
