#include <iostream>
using namespace std ;

class A
{
public :
int a ;
A() { cout << "Def␣A" << endl ; }
A( int a) : a(a) { cout << "+A" << endl ; }
};

class B : public A
{
public :
int b;
B( int a = 2 , int b = 1) : A(a) , b(b) { cout << "+B" << endl ; }
};

class C : public A
{
public :
int c ;
C( int a = 3 , int c = 2) : A(a) , c(c) { cout << "+C" << endl ; }
};

class D : public B, public C
{
public :
int d;
D( int a = 4 , int b = 5 , int c = 6 , int d = 7) : B(b , c ) , C(c ,d) , d(a)
{ cout << "+D" << endl ; }
};

int main()
{
D d(1 ,2 ,3 ,4);
}
