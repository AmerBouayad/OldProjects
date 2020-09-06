#include <iostream>
class A
{
  public:
    B b;
    void print()
    {
        std::cout << "A";
    }
};
class B
{
  public:
    A a;
    void print()
    {
        std::cout << "B";
    }
};
int main()
{
    A a;
    B b;
    a.print();
    b.print();
}
