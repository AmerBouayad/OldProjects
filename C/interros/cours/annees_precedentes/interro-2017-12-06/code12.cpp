#include<iostream>
using namespace std;

class A {}; // cette ligne est manquante dans l'énoncé de base
class Licorne
{
  public:
    Licorne()
    {
        cout << "+ ";
    }
    Licorne(const Licorne & a) // il y avait une erreur dans cette ligne: A au lieu de Licorne
    {
        cout << "r ";
    }
    ~Licorne()
    {
        cout << "- ";
    }
    Licorne & operator=(const Licorne & a)
    {
        cout << "= " << endl;
        return *this;
    }
};
void f(Licorne a) {}
void g(Licorne & a) {}
int main()
{
    Licorne a;
    f(a);
    Licorne * aa = new Licorne();
    aa = &a;
    g(*aa);
}
