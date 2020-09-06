#include<iostream>
using namespace std; // cette ligne manquait dans l'énoncé de base
class A {};
class B
{
    A * a;
  public:
    B(): a(new A()) {}
    ~B()
    {
        delete a;
    }
    void print()
    {
        cout << "Get to the choppaaa" << endl;
    }
};
void f(B b)
{
    std::cout << "You have no respect for logic" << std::endl;
}
int main()
{
    B b;
    f(b);
    b.print();
    B bb;
    bb = b;
    bb.print();

    bb = bb;
    bb.print();
}
