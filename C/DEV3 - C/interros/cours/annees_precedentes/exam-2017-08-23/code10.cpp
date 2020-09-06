#include<iostream>
#include<list>
int main()
{
    std::list<int> l;
    for (int i = 0; i <= 6; i++)
        l.push_back(i * i - i);
	int size = l.size();
    for (int i = 0; i < size; i++)
    {
        auto j = l.rend();
	//FIXME:
	// ATTENTION il y a une erreur de logique dans ce code.
	// l.rend() n'est pas un élément de la liste!!!
	// pour que le code produise l'affichage annoncé, ça devrait
	// être l.rbegin() par exemple.
        std::cout << *j << " ";
        l.pop_back();
    }
}
