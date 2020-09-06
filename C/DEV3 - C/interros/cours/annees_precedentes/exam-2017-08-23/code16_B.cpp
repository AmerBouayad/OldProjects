#include <iostream>
#include "code16_A.cpp"
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
