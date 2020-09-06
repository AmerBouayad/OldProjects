#include<iostream>
#include "code2_B.cpp" //cette ligne manquait dans l'énoncé de base

using namespace std;

int main()
{
    B b;
    A a;
    a.b = &b;
    b.a = a;
    a.print();
    b.print();
}
