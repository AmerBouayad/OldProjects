#include <iostream>
#include <list>
#include <algorithm>
class MyList
{
    std::list<int>l;
  public:
    MyList(int i = 0): l(std::list<int>(i)) {}
    void add(int i)
    {
        l.push_back(i);
    }
    void print()
    {
        for (int i : l)
            std::cout << i << " ";
        std::cout << std::endl;
    }
};
int main()
{
    std::list<MyList>list(
        5);// cette ligne était incorrecte dans l'énoncé
    int n = 4; // cette ligne était dans le for, c'est une erreur de syntaxe
    for (auto it = list.begin(); it != list.end(); it++, n--)
    {
        MyList l;// cette ligne était incorrecte (MyList n'est pas une classe template)
        for (int i = n; i >= 0; i--)
            l.add(i);
        *it = l;
    }
    std::sort(list.begin(),
              list.end()); //trie les listes par taille croissante
    for (MyList l : list)// cette ligne était incorrecte
        l.print();
}
