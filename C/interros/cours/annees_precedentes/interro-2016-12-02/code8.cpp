#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class A
{
  public:
    int i;
};

int main()
{
    vector <A> v = {5, 4, 3, 2, 1};
    sort(v.begin(), v.end());
    for (A a : v)
    {
        cout << a.i << " ";
    }
}
