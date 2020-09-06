#include <iostream>
using namespace std ;
class A
{
public :
const int i ;
A( int entier ) { entier = i ;}
};

int main()
{
A a (2.5); cout << a . i << endl ;
}
