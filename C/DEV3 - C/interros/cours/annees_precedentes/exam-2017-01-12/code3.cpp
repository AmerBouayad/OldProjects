#include<iostream>
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
        // il manquait les std dans l'énoncé de base
        std::cout << "Talk to the hand" << std::endl;
    }
};

void f(B b)
{
    std::cout << "I lied" << std::endl;
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
