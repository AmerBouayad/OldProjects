#ifndef B_H
#define B_H
#include <iostream>
#include "code7_A.cpp"
class B
{
  public:
    A a;
    B() {}
    void print()
    {
        std::cout << "B with A" << std::endl;
    }
};
#endif
