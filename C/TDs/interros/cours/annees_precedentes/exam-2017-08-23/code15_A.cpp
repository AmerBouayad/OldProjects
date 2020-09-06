#ifndef A_H
#define A_H
#include <iostream>
#include "code15_B.cpp"
class A
{
  public:
    B b;
    A() {}
    void print()
    {
        std::cout << "A with B" << std::endl;
    }
};
#endif
