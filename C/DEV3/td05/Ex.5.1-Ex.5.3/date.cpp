#include "date.h"

#include <array>        // pour std::array
#include <string>       // pour std::string
#include <ostream>      // pour std::ostream
#include <chrono>       // pour std::chrono, std::chrono::time_point
//                              std::chrono::system_clock,
//                              std::chrono::system_clock::now,
//                              std::chrono::system_clock::to_time_t
#include <ctime>        // pour std::time_t, std::tm, std::localtime,
//                              std::time

#include "validation/validation.hpp"
#include <sstream> // pour std::ostringstream

// TODO : éventuellement ajouter des #include

namespace nvs
{

// définition des attributs statiques

constexpr int Date::MINIMUM_YEAR;
constexpr int Date::MAXIMUM_YEAR;
constexpr unsigned Date::MINIMUM_MONTH;
constexpr unsigned Date::MAXIMUM_MONTH;
constexpr unsigned Date::MINIMUM_DAY;
constexpr std::array < unsigned, Date::MAXIMUM_MONTH + 1 >
Date::MAXIMUM_DAY;

// méthodes

Date::Date(int year, unsigned month, unsigned day) :
    year_ { year }, // TODO: shouldn't we validate BEFORE creating the date ?
    month_ { month },
    day_ { day }
{
    nvs::validate(year, MINIMUM_YEAR, MAXIMUM_YEAR,
                  "L'année est invalide\n");
    nvs::validate(month, MINIMUM_MONTH, MAXIMUM_MONTH,
                  "Le mois est invalide\n");
    nvs::validate(day, MINIMUM_DAY, dayNumberInMonth(),
                  "Le jour est invalide\n");
}

std::string Date::to_string() const
{
    std::ostringstream oss;
    oss << day_ << "/" << month_ << "/" << year_;
    return oss.str();
}

// méthodes statiques

// fonctions

std::ostream & operator<<(std::ostream & out, const Date & in)
{
    return out << in.to_string();;
}

Date today()
{
    std::chrono::time_point<std::chrono::system_clock> now
    { std::chrono::system_clock::now() };
    std::time_t ttnow { std::chrono::system_clock::to_time_t(now) };
    /*
    std::time_t ttnow = std::time(nullptr);
    */ // old c-style
    std::tm * nowUsefull = std::localtime(&ttnow);

    return Date{ nowUsefull->tm_year + 1900,
                 static_cast<unsigned>(nowUsefull->tm_mon) + 1,
                 static_cast<unsigned>(nowUsefull->tm_mday) };
}

} // namespace nvs
