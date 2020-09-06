#include<iostream>
using namespace std; // cette ligne manquait dans l'énoncé de base
void swap(int * i, int * j)
{
    int * tmp = i;
    i = j; j = tmp;
}
int main()
{
    int i = 2; int j = 3; swap(&i, &j);
    cout << i << " " << j << endl;
}
