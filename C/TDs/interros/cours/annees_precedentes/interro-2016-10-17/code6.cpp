#include<iostream>
using namespace std;
int main()
{
    int a1 = 2.1;
    cout << a1 << " ";
    int a2(2.1);
    cout << a2 << " ";
    int a3{2.1};
    cout << a3 << endl;
}
