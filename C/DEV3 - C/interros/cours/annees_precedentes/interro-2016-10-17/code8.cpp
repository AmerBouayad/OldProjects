#include <iostream>
using namespace std;
void swap(int * i, int *j); //vous ne pouvez pas modifier ce prototype
int main()
{
    int i = 2; int j = 3;
    swap(&i, &j);
    cout << i << " " << j << endl;
}
void swap(int * i, int * j)
{
    int * tmp = i;
    i = j;
    j = tmp;
}
