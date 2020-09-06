#include<iostream>
template<int N>struct Number
{
    int n;
    Number(): n(N)
    {
        std::cout << n << std::endl;
    }
};
int fib(int n)
{
    if (n == 0 || n == 1)return 1;
    else return fib(n - 1) + fib(n - 2);
}
int main()
{
    Number<fib(5)> n;
}
