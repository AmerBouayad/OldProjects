#include<iostream>
using namespace std;
class point
{
  protected:
    int x, y;
  public:
    point(int a = 0, int b = 0): x(a), y(b) {}
    virtual void affiche()
    {
        cout << "Je␣suis␣en␣" << x << "␣,␣" << y << endl;
    }
};
class pointcol: public point
{
    short col;
  public:
    pointcol(int a = 0, int b = 0, int c = 0): point(a, b), col(c) {}
    void affiche()
    {
        cout << "Je␣suis␣en␣" << x << "␣,␣" << y <<
             "␣et␣ma␣couleur␣"
             << "est␣" << col << endl;
    }
};
int main()
{
    point * p = new point(3, 5);
    pointcol * pc = new pointcol(8, 6, 2);
    p = pc;
    p->affiche(); pc->affiche();
    p = new point(3, 5);
    pc = (pointcol *)p;
    p->affiche(); pc->affiche();
}
