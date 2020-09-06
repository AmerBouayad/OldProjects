#include <iostream>

class Ball {};
class P
{
public :
P* target ;
P(P* target ) : target ( target ) {}
void aim( Ball b)
{
try
{
throw b;
}
catch( Ball& b)
{
std::cout << "Got␣ it ␣ ! " << std::endl ;
target->aim(b );
}
}
};

int main()
{
P * parent = new P(0);
P * child = new P( parent );
parent->target = child ;
parent->aim( Ball ( ) ) ;
}
