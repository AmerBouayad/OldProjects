#include <iostream>

#include "date.h"

int main()
{
    using namespace std;
    using namespace nvs;

    auto test_date = [](int year, int month, int day,
                        const string & msg ) -> void
    {
        Date d(year, month, day);
        cout << msg << endl << "Date:" <<  d << " is leap year: " << (d.leapYear() ? "true" : "false") << endl << endl;
    };

    auto test_comparison = [](int year, int month, int day, int year2,
                              int month2, int day2,
                              const string & msg ) -> void
    {
        Date d1(year, month, day);
        Date d2(year2, month2, day2);
        cout << msg << endl;
        cout << "Date1:" <<  d1 << " Date2: " << d2 << endl;
        cout << "Date1 == Date2: " << (d1 == d2 ? "true" : "false") << endl;
        cout << "Date1 < Date2: " << (d1 < d2 ? "true" : "false") << endl << endl;;

    };

    test_date(1970, 1, 1, "premier test");
    test_date(0, 2, 29, "test de l'an 0 (bissextile)");
    test_date(-4, 2, 29, "test d'une année bissextile négative:");
    //test_date(1, 2, 29, "test du 29/02 d'une année non bissextile");

    test_comparison(1970, 1, 1, 1970, 1, 1, "test de deux dates égales");
    test_comparison(1970, 1, 25, 1970, 1, 1, "test d1 > d2");
    test_comparison(1970, 1, 1, 1970, 1, 10, "test d1 < d2");

    cout << today() << endl;
}
