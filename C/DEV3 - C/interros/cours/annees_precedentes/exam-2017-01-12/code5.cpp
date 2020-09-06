#include <iostream>
#include <list>
int main()
{
    std::list<int>l;
    for (int i = 0; i <= 6; i++)
        l.push_back(i * i - i);
    for (int i = 0; i < l.size(); i++)
    {
	    // attention l'énoncé de base contenait une erreur
	    // il faut utiliser --end() ou rbegin() pour obtenir le
	    // "résultat produit" annoncé
        auto j = l.rbegin();
        std::cout << *j << " ";
        l.pop_back();
    }
}
