#include <iostream>

void swap(int * i, int * j)
{
    int * tmp = i;
    i = j; j = tmp;
}
using namespace std; // cette ligne manquait dans l'énoncé de base
int main()
{
    int i = 2; int j = 3; swap(&i, &j);
    cout << i << " " << j << endl;
}
