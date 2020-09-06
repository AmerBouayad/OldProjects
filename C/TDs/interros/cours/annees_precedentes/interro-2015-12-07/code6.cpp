#include <iostream>
int& f ( int& i )
{
i *= 2;
return i ;
}

int main()
{
 auto i=23;
std :: cout << f ( i)++ << std :: endl ;
f ( i ) = 321.123;
std :: cout << i << std :: endl ;
}
