#include<iostream>
class A
{
    int i;
  public:
    A operator+(int i)
    {
        std::cout << "I am one with the force" << std::endl;
    }
    A operator+(A a)
    {
        std::cout << "and the force is with me" << std::endl;
    }
};
int main()
{
    int i1; A a1; A a2;
    i1 + a1 + a2;
}
