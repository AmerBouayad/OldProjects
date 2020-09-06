#include "person.h"
#include <unordered_set>
#include <algorithm>
#include <iomanip> // for setw()

namespace g43317
{

Person::Person(const std::vector<std::string> & firstnames,
               const std::string & name, Sex sex, const Date & birthdate)
    : firstnames_(validateFirstnames(firstnames)),
      name_(validateName(name)), sex_(sex),
      birthdate_(birthdate)
{}

Person::Person(const std::vector<std::string> & firstnames,
               const std::string & name, Sex sex, int birthdateyear,
               unsigned birthdatemonth, unsigned birthdateday)
    : firstnames_(validateFirstnames(firstnames)),
      name_(validateName(name)), sex_(sex),
      birthdate_(birthdateyear, birthdatemonth, birthdateday)
{}

void Person::addFirstname(const std::string & newFirstname)
{
    if (! newFirstname.empty()
            && std::find(firstnames_.begin(), firstnames_.end(),
                         newFirstname) == firstnames_.end())
    {
        firstnames_.push_back(newFirstname);
    }
}

void Person::addFirstnames(const std::vector<std::string> &
                           newFirstnames)
{
    for (std::string s : newFirstnames)
    {
        addFirstname(s);
    }
}

void Person::firstnames(const std::vector<std::string> &
                        newFirstnames)
{
    try
    {
        firstnames_ = validateFirstnames(newFirstnames);
    }
    catch (std::invalid_argument)
    {
        // on ne fait rien...
    }
}

unsigned Person::firstnamesCount() const
{
    return firstnames_.size();
}

void Person::setName(const std::string & newName)
{
    try
    {
        name_ = validateName(newName);
    }
    catch (std::invalid_argument)
    {
        // on ne fait rien...
    }
}

void Person::removeFirstname(const std::string & oldFirstname)
{
    auto it = std::find(firstnames_.begin(), firstnames_.end(),
                        oldFirstname);
    firstnames_.erase(it);
    // TODO: que faire si on supprime l'unique prénom de la liste ? (la doc ne précise pas d'exception)
}

void Person::removeFirstnames(const std::vector<std::string> &
                              oldFirstnames)
{
    for (auto s : oldFirstnames)
    {
        firstnames_.erase(std::find(firstnames_.begin(), firstnames_.end(),
                                    s));
    }
    /*
     * erase-remove:
    firstnames_.erase(std::remove_if(firstnames_.begin(),
                                     firstnames_.end(), [&] (auto & elem) -> bool
    {
        return std::find(oldFirstnames.begin(), oldFirstnames.end(), elem) != oldFirstnames.end();
    }),
    firstnames_.end());
    // consider using sort() first then std::binary_search instead of std::find if performance is an issue
    */
}

std::vector<std::string> Person::validateFirstnames(
    const std::vector<std::string> & firstnames) const
{
    if (firstnames.empty())
    {
        throw std::invalid_argument("firstnames est vide");
    }
    std::vector<std::string> validated_firstnames;
    std::unordered_set<std::string> name_set;
    for (const std::string & s : firstnames)
    {
        if ( ! s.empty())
        {
            name_set.insert(s); // on aura pas de doublons
        }
    }
    if (name_set.empty())
    {
        throw std::invalid_argument("Tous les prénoms sont vides");
    }
    for (std::string s : name_set)
    {
        validated_firstnames.push_back(s);
    }
    return validated_firstnames;
}

std::string Person::validateName(const std::string & name) const
{
    if (name.empty())
    {
        throw std::invalid_argument("name est vide");
    }
    return name;
}

std::ostream & operator<<(std::ostream & out,
                          const Person & in)
{
    return out << in.to_string();
}


} // namespace g43317
