#include <iostream>

#include "date.h"
#include "sex.hpp"
#include "person.h"
#include "misc/formoption.h"
#include "testgenerator.h"
#include <vector>
#include <algorithm>

using namespace std;
using namespace g43317;

/*!
 * \mainpage Un projet pour répondre aux questions 5.4 à 5.12 du td05.
 * \details 
 * Pour les questions 5.1 à 5.3, voir le dossier "Ex.5.2-Ex.5.3"
 *
 * Un bon point d'entrée est celui de la documentation de
 * l'espace de nom \ref g43317.
 */

void test_date_class();
void test_sex_class();
void test_person_class();
void print(const std::vector<const Person *> & c);
void sort_birthdate(std::vector<const Person *> & c);
void sort_birthdate_name(std::vector<const Person *> & c);
void sort_birthdate_name_firstnames(std::vector<const Person *> & c);
void sort_old_ladies_first(std::vector<const Person *> & c);

int main()
{
    using namespace std;
    using namespace g43317;

    test_date_class();
    test_sex_class();
    test_person_class();


}

void test_date(int year, int month, int day,
               const string & msg )
{
    Date d(year, month, day);
    cout << msg << endl << "Date:" <<  d << " is leap year: "
         << (d.leapYear() ? "true" : "false") << endl << endl;
}

void test_date_comparison (int year, int month, int day, int year2,
                           int month2, int day2,
                           const string & msg )
{
    Date d1(year, month, day);
    Date d2(year2, month2, day2);
    cout << msg << endl;
    cout << "Date1:" <<  d1 << " Date2: " << d2 << endl;
    cout << "Date1 == Date2: " << (d1 == d2 ? "true" : "false") << endl;
    cout << "Date1 < Date2: " << (d1 < d2 ? "true" : "false") << endl <<
         endl;;
}

void test_date_class()
{
    test_date(1970, 1, 1, "premier test");
    test_date(0, 2, 29, "test de l'an 0 (bissextile)");
    test_date(-4, 2, 29, "test d'une année bissextile négative:");
    //test_date(1, 2, 29, "test du 29/02 d'une année non bissextile");

    test_date_comparison(1970, 1, 1, 1970, 1, 1,
                         "test de deux dates égales");
    test_date_comparison(1970, 1, 25, 1970, 1, 1, "test d1 > d2");
    test_date_comparison(1970, 1, 1, 1970, 1, 10, "test d1 < d2");
    cout << today() << endl;
}

void test_sex_class()
{
    cout << endl << "testing sex class:" << endl;
    Sex s = Sex::FEMALE;
    cout << to_string(s) << endl;
    cout << to_string(s, FormOption::LONG) << endl;
    cout << s << endl;
}

void test_person_class()
{
    cout << endl << "test de la classe person: " << endl;
    std::vector<Person> person_vector;
    std::vector<std::tuple<std::vector<std::string>, std::string, char,
        std::tuple<int, unsigned, unsigned>>> peop = nvs::people();
    for (auto a : peop)
    {
        person_vector.emplace_back(get<0>(a), get<1>(a),
                                   (get<2>(a) == 'm' ? Sex::MALE : Sex::FEMALE), get<0>(get<3>(a)),
                                   get<1>(get<3>(a)), get<2>(get<3>(a)));
    }
    for (auto p : person_vector)
    {
        cout << p << endl;
    }

    //Ex. 5.8:
    std::vector<const Person *> sorting_vector;
    // TODO: pourquoi spécifiquement utiliser transform() et back_inserter() ?

    /*
        for (const Person & p : person_vector)
        {
            sorting_vector.push_back(&p);
        }
    */
    /*
        for_each(person_vector.begin(),
                 person_vector.end(), [&](const Person & p)
        {
            sorting_vector.push_back(&p);
        });
    */
    std::transform(person_vector.begin(), person_vector.end(),
                   std::back_inserter(sorting_vector), [](const Person & p)
    {
        return &p;
    });
    cout << "vecteur de pointeurs: " << endl;
    print(sorting_vector);
    // Ex. 5.9:
    cout << "vecteur après le tri par date de naissance croissante: " <<
         endl;
    sort_birthdate(sorting_vector);
    print(sorting_vector);

    // Ex. 5.10:
    cout << "vecteur après le tri en majeur par date de naissance croissante"
         " et en mineur par nom de famille croissant: " << endl;
    sort_birthdate_name(sorting_vector);
    print(sorting_vector);

    // Ex. 5.11:
    cout << "vecteur après le tri en majeur par date de naissance croissante,"
         << endl
         << " en médian par nom de famille croissant et en mineur par prénoms croissants: "
         << endl;
    sort_birthdate_name_firstnames(sorting_vector);
    print(sorting_vector);

    // Ex. 5.12:
    cout << "vecteur après le tri demandé dans l'exercice 5.12:" <<
         endl;
    sort_old_ladies_first(sorting_vector);
    print(sorting_vector);

}

void print(const std::vector<const Person *> & c)
{
    for (const Person * p : c)
    {
        cout << *p << endl;
    }
}

void sort_birthdate(std::vector<const Person *> & c)
{
    std::sort(c.begin(), c.end(), [](const Person *& p1,
                                     const Person *& p2)
    {
        return p1 -> birthdate() < p2 -> birthdate();
    });
}

void sort_birthdate_name(std::vector<const Person *> & c)
{
    std::sort(c.begin(), c.end(), [](const Person *& p1,
                                     const Person *& p2)
    {
        return p1 -> birthdate() < p2 -> birthdate()
               || (p1 -> birthdate() == p2 -> birthdate()
                   && p1 -> name() < p2 -> name());
    });
}

void sort_birthdate_name_firstnames(std::vector<const Person *> & c)
{
    std::sort(c.begin(), c.end(), [](const Person *& p1,
                                     const Person *& p2)
    {
        return p1 -> birthdate() < p2 -> birthdate()
               || (p1 -> birthdate() == p2 -> birthdate() &&
                   p1 -> name() < p2 -> name())
               || ((p1 -> birthdate() == p2 -> birthdate() &&
                    p1 -> name() == p2 -> name() &&
                    p1 -> firstnames() < p2 -> firstnames()));
    });
}

void sort_old_ladies_first(std::vector<const Person *> & c)
{
    std::sort(c.begin(), c.end(), [](const Person *& p1,
                                     const Person *& p2)
    {
        return ((p1 -> sex() == Sex::FEMALE &&
                 p2 -> sex() != Sex::FEMALE) ? true : false)
               || (p1 -> sex() == p2 -> sex() &&
                   (p1 -> birthdate() < p2 -> birthdate()))
               || (p1 -> sex() == p2 -> sex() &&
                   p1 -> birthdate() == p2 -> birthdate() &&
                   p1 -> name() < p2 -> name())
               || ((p1 -> sex() == p2 -> sex() &&
                    p1 -> birthdate() == p2 -> birthdate() &&
                    p1 -> name() == p2 -> name()) &&
                   p1 -> firstnames() < p2 -> firstnames());
    });
}




