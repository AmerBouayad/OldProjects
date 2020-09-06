#include <iostream>
class A
{
    int i;
  public:
    A(int i = 0): i(i) {}
    double operator+(double d)
    {
        return i + d;
    }
    operator int()
    {
        return i;
    }
    operator double()
    {
        return i;
    }
};
int main()
{
    A a(2); std::cout << (a + 5) << std::endl;
}
