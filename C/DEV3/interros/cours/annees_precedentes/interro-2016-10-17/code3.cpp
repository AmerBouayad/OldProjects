#include <iostream>
int f(const char tab[])
{
    return sizeof(tab) / sizeof(*tab);
}
int main()
{
    char bat[] = {1, 2, 3, 4, 5, 6, 7};
    std::cout << (sizeof(bat) / sizeof(*bat)) << std::endl;
    std::cout << f(bat) << std::endl;
}
