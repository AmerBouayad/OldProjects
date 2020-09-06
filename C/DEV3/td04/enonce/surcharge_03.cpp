/*!
 * \file surcharge_03.cpp
 * \brief surcharge de fonctions
 */
#include <iostream>

void f(short) {
    std::cout << "f(short)" << std::endl;
}

void f(double) {
    std::cout << "f(double)" << std::endl;
}

int main() {
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

