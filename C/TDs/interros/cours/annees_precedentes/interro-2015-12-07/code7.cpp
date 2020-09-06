#include<iostream>
#include<set>
int main()
{
    std::multiset<int>msi = {3, 5, 3, 6, 2};
    for (auto e : msi)
        std::cout << e << "␣";
    std::cout << std::endl;
}
