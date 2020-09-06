#include<iostream>
using namespace std;
class A
{
  public:
    A()
    {
        cout << "+A ";
    }
    A(const A & a)
    {
        cout << "rA ";
    }
    ~A()
    {
        cout << "-A";
    }
    A & operator=(const A & a)
    {
        cout << "=A " << endl;
        return *this;
    }
};
void f(A a) {}
void g(A & a) {}
int main()
{
    A a;
    f(a);
    A * aa = new A();
    aa = &a;
    g(*aa);
}
