#include<iostream>
using namespace std;
class exceptA {};
class exceptB: public exceptA {};
class exceptC: public exceptB {};
void f()
{
    throw exceptB();
}
int main()
{
    try
    {
        f();
    }
    catch (exceptA & e)
    {
        cout << "I caught an A" << endl;
    }
    catch (exceptB & e)
    {
        cout << "I caught a B" << endl;
    }
    catch (exceptC & e)
    {
        cout << "I caught a C" << endl;
    }
    catch (...)
    {
        cout << "I caught something" << endl;
    }
}
