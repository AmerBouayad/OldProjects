#include <iostream>

using namespace std;
class A
{
  public:
    A()
    {
        cout << "+A" << endl;
    }
    A (const A & a)
    {
        cout << "rA" << endl;
    }
    virtual ~A()
    {
        cout << "-A" << endl;
    }
};

class B
{
  public:
    B()
    {
        cout << "+B" << endl;
    }
    B (const B & b)
    {
        cout << "rB" << endl;
    }
    virtual ~B()
    {
        cout << "-B" << endl;
    }
};

class C: public A, public virtual B
{
  public:
    C()
    {
        cout << "+C" << endl;
    }
    C (const C & c)
    {
        cout << "rC" << endl;
    }
    virtual ~C()
    {
        cout << "-C" << endl;
    }
};

void f(A a ) {}

int main ()
{
    C c; cout << endl;
    f(c); cout << endl;
    C * cc = new C(); cout << endl;
    delete cc; cout << endl;
    return 0;
}
