#include<iostream>
#include<list>
#include<algorithm>
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
            std::cout << i << "␣";
        std::cout << std::endl;
    }
};
int main()
{
    std::list <MyList> list(5);
    // la ligne suivante était dans le for dans l'énoncé de base. 
    // C'est une erreur de syntaxe. (mais ce n'est pas cette erreur qui rapportait des points...)
    // it et n devraient avoir le même type pour que ça fonctionne
    // ( for(int it, n ; ; ) )
    int n = 4;
    for (auto it = list.begin(); it != list.end(); it++, n--)
    {
        MyList l;
        for (int i = n; i >= 0; i--)
            l.add(i);
        *it = l;
    }
    std::sort(list.begin(),
              list.end()); //trie les listes par taille croissante
    for (MyList l : list)
        l.print();
}
