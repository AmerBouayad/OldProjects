#include<iostream>
int main()
{
    int i = 33;
    int const & ri = i;
    std::cout << ri << std::endl;
    i++;
    std::cout << ri << std::endl;
    return 0;
}
