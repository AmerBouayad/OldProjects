#include<iostream>
#include<vector>
struct A
{
    int i;
    A(int i): i(i) {}
    void print()
    {
        std::cout << i << "␣";
    }
};
int main()
{
    std::vector<A> v(5);
    for (int j = 0; j < v.size(); j++)
        v[j].i = j;
    for (A a : v)
        a.print();
}
