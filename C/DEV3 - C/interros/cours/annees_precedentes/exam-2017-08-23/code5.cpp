#include<iostream>
#include<vector>
using namespace std;
class A
{
  public:
    int i;
    A(int i): i(i) {}
    void print()
    {
        cout << i << " ";
    }
};
int main()
{
    vector<A>v(5);
    for (int j = 0; j < v.size(); j++)
        v[j].i = j;
    for (A a : v)
        a.print();
}
