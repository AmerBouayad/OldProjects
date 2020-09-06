#include<iostream>
class A
{
  protected:
    int i;
  public:
    A(int i = 0): i(i) {}
    void print()
    {
        std::cout << i << std::endl;
    }
};
class B: public A
{
    int j;
  public:
    B(int i = 0): A(i + 2), j(i + 3) {}
    void print()
    {
        std::cout << (i + j) << std::endl;
    }
};
int main()
{
    A a = B();
    a.print();
}
