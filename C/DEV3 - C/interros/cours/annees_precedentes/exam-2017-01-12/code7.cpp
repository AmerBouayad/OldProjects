#include <iostream>
template<class T>class Brol
{
  public:
    Ti & t; int & i;
    Brol(T & t)
    {
        this->t = t;
    }
    Brol(int & i)
    {
        this->i = i;
    }
    void print()
    {
        std::cout << t << " " << i << std::endl;
    }
};
int main()
{
    Brol<int>b(2);
    b.print();
}
