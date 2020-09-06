#include<iostream>
using namespace std;
struct Mere
{
    void f(int n)
    {
        cout << "Mere::integer␣" << n << endl;
    }
    void f(char n)
    {
        cout << "Mere::character␣" << n << endl;
    }
};
struct Fille: public Mere
{
    void f(int n, int m)
    {
        cout << "Fille::integers␣" << n << "␣" << m << endl;
    }
};
int main()
{
    int n = 1;
    char c = 'a';
    Fille b;
    b.f(n);
    b.f(c);
    b.f(n, c);
}
