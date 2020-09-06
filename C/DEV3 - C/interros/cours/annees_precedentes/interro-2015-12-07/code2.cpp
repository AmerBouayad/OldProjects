#include <iostream>
using namespace std ;

class A
{
public :
void f ( int n) {cout << "A: : entier ␣" << n << endl ; }
void f (char n) {cout << "A: : char␣" << n << endl ; }
};

class B : public A
{
public :
void f ( int n , int m) { cout << "B: : entiers ␣" << n << "␣" << m << endl ; }
};


int main()
{
int n = 1;
char c = 'a' ;
B b;
b. f (n );
b. f (c );
}
