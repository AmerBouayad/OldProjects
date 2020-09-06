#include<iostream>
template<class T>struct Poney
{
    T & t; int & i;
    Poney(T & t)
    {
        this->t = t;
    }
    Poney(int & i)
    {
        this->i = i;
    }
    void print()
    {
        std::cout << t << "␣" << i << std::endl;
    }
};
int main()
{
    Poney<int>b(2); b.t = 3;
    b.print();
}
