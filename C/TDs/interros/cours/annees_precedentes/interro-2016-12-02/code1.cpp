
#include<iostream>
#include<vector>
using namespace std ;
class A
{
  public :
    ~A( )
    {
        cout << "Boom" << endl ;
    }
};
class B
{
    vector < A> v ;
  public:
    B() : v ( vector < A > (4)) {}
};
void f ( )
{
    B b ;
}
int main ( )
{
    f ();
    cout << "I␣want␣you␣in␣my␣room" << endl <<
         "(outdated␣song)" << endl ;
    return 0;
}
