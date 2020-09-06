#include <iostream>
using namespace std ;

class A
{
public :
virtual A& operator=(const A&) { cout << "Aff␣A" << endl ;}
};
class B : public A
{
public :
virtual B& operator=(const B&) { cout << "Aff␣B" << endl ;}
};

int main()
{
A * a1 = new A(); A * a2 = new A();
B * b1 = new B(); B * b2 = new B();
b1 = b2 ; a1 = b1 ; a1 = b2 ;
a1 = new A(); a2 = new A();
b1 = new B(); b2 = new B();
*b1 = *b2 ; *a1 = *b1 ; *a1 = *b2 ;
}
