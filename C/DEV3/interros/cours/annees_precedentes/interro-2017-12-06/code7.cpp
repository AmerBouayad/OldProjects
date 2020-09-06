#include <iostream>
#include <vector> // cette ligne est manquante dans l'énoncé d'origine
template<class T>struct MyVector
{
    std::vector<T> v;
    MyVector(std::vector<T> & v): v(v) {}
};
template<class Container, class Fct>void forall(Container c, Fct f)
{
    for (auto e : c)
        f(e);
}
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5};
    MyVector<int> myv(v);
    forall(myv, [](int i)
    {
        std::cout << i << "␣";
    });
}
