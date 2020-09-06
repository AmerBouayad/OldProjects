#include <iostream>
class B;
class A
{
  public:
    B * b;
    A(): b(nullptr) {}
    void print()
    {
        std::cout << "A with B" << std::endl;
    }
};
