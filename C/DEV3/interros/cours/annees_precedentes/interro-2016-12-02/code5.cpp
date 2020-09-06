#include<iostream>
using namespace std;
class Integer
{
    unsigned i;
    bool positive;
  public:
    Integer(unsigned i, bool positive = true): i(i), positive(positive) {}
    Integer operator+(Integer a)
    {
        if (positive && a.positive)return Integer(i + a.i);
        else if (positive && !a.positive)return Integer(i - a.i);
        else if (!positive && a.positive)return Integer(a.i - i);
        else return Integer(-i - a.i);
    }
    void print()
    {
        if ( !positive)
            cout << "-";
        cout << i << endl;
    }
};
int main()
{
    Integer a1(2u);
    Integer a2(3u, false);
    Integer s = a1 + a2 ;
    s.print();
    return 0;
}
