#include <iostream>
#include <vector>
using namespace std ;

int main()
{
int t [ ] = {1 ,2 ,3 ,4};
vector<int> v(t , t );
cout << v . size () << "␣" << v . capacity () << endl ;
for ( int i = 0; i <= 8; i++)
{
v . push_back (0);
cout << v . size () << "␣" << v . capacity () << endl ;
}
}
