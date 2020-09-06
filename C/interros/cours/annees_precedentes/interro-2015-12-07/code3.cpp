#include <iostream>
#include <utility>

int main()
{
std :: pair<char , double> pcd( 'Z' , -3.14);
std :: pair<float , long> pfl = pcd ; // on ne peut pas assigner comme ça avec un vector, avec une pair oui !
std :: cout << pcd . first<< "␣" << pfl . second << std :: endl ;
}
