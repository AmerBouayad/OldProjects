#include <iostream>
#include "date.h"

int main()
{
    using namespace std;
    using namespace nvs;

    // TODO
    
    //cout << today() << endl;

    Date date(2017,12,2);
    cout << date.Date::to_string() << endl;

}
