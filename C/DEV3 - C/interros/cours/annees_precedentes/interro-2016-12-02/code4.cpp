
#include<iostream>
int f()
{
    static int i = {4};
    return --i;
}
int main()
{
    std::cout << f() << std::endl;
    while (f())
    {
    }
    std::cout << f() << std::endl;
    return 0;
}
