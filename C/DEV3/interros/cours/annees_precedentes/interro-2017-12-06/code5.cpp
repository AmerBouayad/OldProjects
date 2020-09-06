#include<iostream>
using namespace std; // cette ligne est manquante dans l'énoncé d'origine
class A {};
struct B // Ce b est manquant dans l'énoncé d'origine
{
    A * a;
    B(): a(new A()) {}
    ~B()
    {
        delete a;
    }
    void print()
    {
        cout << "Get␣to␣the␣choppaaa" << endl;
    }
};
void f(B b)
{
    std::cout << "You␣have␣no␣respect␣for␣logic" << std::endl;
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
