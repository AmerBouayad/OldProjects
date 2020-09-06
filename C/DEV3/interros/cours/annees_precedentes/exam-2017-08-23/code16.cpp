#include <iostream>
#include"code16_B.cpp" // cette ligne manquait dans l'énoncé

using namespace std;
// FIXME le code est annoncé avec "erreur de compilation", mais il
// fonctionne et donne le résultat attendu
int main()
{
    B b;
    A a;
    a.b = &b;
    b.a = a;
    a.print();
    b.print();
}
