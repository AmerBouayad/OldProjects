#include <iostream>
#include "code15_B.cpp" // cette ligne manquait dans l'énoncé

using namespace std;

int main()
{
    B b;
    A a;
    a.b = b;
    b.a = a;
    a.print();
    b.print();
}
