#include <iostream>
int f (const int tab[], int u)
{
    return * (tab + u) ;
}
int main ()
{
    int bat [ ] = { 1, 2, 3, 4, 5, 6, 7 } ;
    std::cout << * ( bat + 1 ) << std::endl;
    std::cout << f ( bat + 4, 2) << std::endl ;
}
