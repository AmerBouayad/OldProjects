#include<iostream>
class A
{
    int * t;
    int n;
  public:
    A(int n): t(new int[n]), n(n) {}
    ~A()
    {
        delete t;
    }
    void print()
    {
        for (int i = 0; i < n; i++)
            std::cout <<
                      t[i] << " ";
    }
};
void f(A a)
{
    std::cout << "GET TO THE CHOPPAAA !!!" << std::endl;
}
int main()
{
    A a(5);
    f(a);
    a.print(); std::cout << std::endl;
    A b(4);
    b = a;
    b.print(); std::cout << std::endl;
    b = b;
    b.print(); std::cout << std::endl;
}
