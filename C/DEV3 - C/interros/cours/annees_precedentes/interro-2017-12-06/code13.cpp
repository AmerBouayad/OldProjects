#include<iostream>
struct Balle {};
struct Joueur
{
    Joueur * cible;
    Joueur(Joueur * j = nullptr): cible(j) {}
    void lance(Balle ball)
    {
        try
        {
            throw ball;
        }
        catch (Balle & b)
        {
            std::cout << "J’ai␣attrapé␣la␣balle" << std::endl;
            cible->lance(b);
        }
    }
};
int main()
{
    Joueur p1;
    Joueur p2(&p1);
    p1.cible = &p2;
    Balle b;
    p1.lance(b);
}
