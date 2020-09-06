#include <iostream>
using namespace std;
class A
{
  public:
    void f(int n)
    {
        cout << "A::integer " << n << endl;
    }
    void f(char n)
    {
        cout << "A::character " << n << endl;
    }
};
class B: public A
{
  public:
    void f(int n, int m)
    {
        cout << "B::integers " << n << " " << m << endl;
    }
};
int main()
{
    int n = 1;
    char c = 'a';
    B b;
    b.f(n);
    b.f(c);
    b.f(n, c);
}
