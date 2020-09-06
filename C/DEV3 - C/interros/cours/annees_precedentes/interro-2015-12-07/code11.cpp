#include <iostream>
using namespace std ;

class A
{
public :
A() {cout << "+A" << endl ; }
A(const A&) {cout << "cA" << endl ; }
virtual ~A() {cout << "´A" << endl ; }
};
class B : public A
{
public :
B() {cout << "+B" << endl ; }
B(const B&) {cout << "cB" << endl ; }
virtual ~B() {cout << "´B" << endl ; }
};

void f (A)
{
cout << " f " << endl ;
}

int main()
{
B b; f (b );
}
