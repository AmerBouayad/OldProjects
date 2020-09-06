#include<iostream>
class Integer
{
    unsigned i;
    bool positive;
  public:
    Integer(unsigned i, bool positive = true): i(i), positive(positive) {}
    Integer operator+(Integer a)
    {
        if (positive && a.positive)
            return Integer(i + a.i);
        else if (positive && !a.positive)
            return Integer(i - a.i);
        else if (!positive && a.positive)
            return Integer(a.i - i);
        else
            return Integer(- i - a.i);
    }
    friend std::ostream & operator<<(std::ostream & out,
                                     const Integer & i)
    {
        if (!i.positive)
            out << " ́";
        out << i.i;
    }
};

int main()
{
    Integer a1(2u);
    Integer a2(3u, false);
    Integer s = a1 + a2;
    std::cout << s << std::endl;
}
