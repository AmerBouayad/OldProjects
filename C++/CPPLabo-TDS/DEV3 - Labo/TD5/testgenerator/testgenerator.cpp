#include "testgenerator.h"
#include "../random/random.hpp"

#include <tuple>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace nvs
{

tuple<int, unsigned, unsigned> dategenerator()
{
    static constexpr array<array<unsigned, 6>, 3> data {{
            { 2000, 1900, 0, 10000, 2014, 2020 },
            { 0, 4, 2, 12, 13, 2 },
            { 0, 102, 28, 29, 30, 31 }
        }};    // double accolade car aggrégat

    return tuple<int, unsigned, unsigned>
    {
        data[0][random_value(0, static_cast<int>(data[0].size()) - 1)],
        data[1][random_value(0, static_cast<int>(data[1].size()) - 1)],
        data[2][random_value(0, static_cast<int>(data[2].size()) - 1)]
    };
}

vector<tuple<vector<string>, string, char,
       tuple<int, unsigned, unsigned>>> people(unsigned size)
{
    // http://statbel.fgov.be/fr/statistiques/chiffres/population/noms/

    static const array<array<string, 10>, 2> possibleFN {{
            {
                "Lina", "Aya", "Sarah", "Sofia", "Nour", "Yasmine",
                "Malak", "Emma", "Sara", "Anna"
            },
            {
                "Adam", "Mohamed", "Rayan", "Gabriel", "David",
                "Imran", "Amir", "Lucas", "Youssef", "Yanis"
            }
        }};

    static constexpr array<char, 2> possibleS {'f', 'm'};

    static const array<string, 10> possibleN
    {
        "Diallo", "Bah", "Janssens", "Peeters", "Dubois",
        "Nguyen", "Barry", "Jacobs", "Mertens", "Martin" };

    // make_tuple : constexpr c++14
    static constexpr array<tuple<int, unsigned, unsigned>, 10>
    possibleB
    {
        make_tuple(2014, 5u, 27u), make_tuple(2014, 5u, 20u),
        make_tuple(2014, 9u, 27u), make_tuple(2013, 5u, 27u),
        make_tuple(2015, 5u, 27u), make_tuple(2013, 5u, 28u),
        make_tuple(2013, 5u, 26u), make_tuple(2013, 6u, 27u),
        make_tuple(2014, 5u, 31u), make_tuple(2015, 5u, 26u)
    };

    vector<tuple<vector<string>, string, char,
           tuple<int, unsigned, unsigned>>> ret;

    for (unsigned u {0}; u < size; ++u)
    {
        unsigned indexS { random_value(0u, static_cast<unsigned>(
                                           possibleS.size()) - 1) };
        unsigned indexN { random_value(0u, static_cast<unsigned>(
                                           possibleN.size()) - 1) };
        unsigned indexB { random_value(0u, static_cast<unsigned>(
                                           possibleB.size()) - 1) };
        vector<string> fn(random_value(1u, 9u));
        generate(begin(fn), end(fn), [indexS]()
        {
            return possibleFN[indexS]
                   [nvs::random_value(0u,
                                      static_cast<unsigned>(
                                          possibleFN[indexS].size())
                                      - 1)];
            // Q : pq pas besoin de capturer possibleFN ?
            // car possibleFN est static ? const ?
        });
        ret.emplace_back(move(fn), possibleN[indexN],
                         possibleS[indexS],
                         possibleB[indexB]);
    }

    return ret;
}

} // namespace nvs


