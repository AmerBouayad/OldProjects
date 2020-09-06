#include<iostream>
using namespace std;
int main()
{
    unsigned i = 5;
    while (i >= 0)
    {
        if (i != 0)
            cout << i << endl;
        i--;
    }
    cout << "BOOM" << endl;
}
