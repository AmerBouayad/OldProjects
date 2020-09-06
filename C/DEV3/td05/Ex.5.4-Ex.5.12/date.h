/*!
 * \file date.h
 * \brief Définition de la classe g43317::Date et de fonctions utilisant
 *        ce type.
 */
#ifndef DATE_H
#define DATE_H

#include <limits>
#include <array>
#include <string>
#include <ostream>

/*!
 * \namespace Espace de nom de g43317.
 */
namespace g43317
{

/*!
 * \brief Classe représentant une date.
 *
 * On ne se soucie pas ici du type de calendrier et de sa
 * pertinence historique. Il n'y a pas d'années minimale ou
 * maximale autre que celles impliquées par la taille du
 * type sous-jacent.
 *
 * Les attributs Date#year_, Date#month_ et Date#day_ sont constants.
 * Les instances de Date sont donc
 * [immuables](http://www.cnrtl.fr/definition/immuable).
 */
class Date
{
  public:

    /*!
     * \brief Valeur minimale acceptée pour l'année.
     */
    constexpr static int MINIMUM_YEAR { std::numeric_limits<int>::min() };

    /*!
     * \brief Valeur maximale acceptée pour l'année.
     */
    constexpr static int MAXIMUM_YEAR { std::numeric_limits<int>::max() };

    /*!
     * \brief Valeur minimale acceptée pour le mois.
     */
    constexpr static unsigned MINIMUM_MONTH { 1 };

    /*!
     * \brief Valeur maximale acceptée pour le mois.
     */
    constexpr static unsigned MAXIMUM_MONTH { 12 };

    /*!
     * \brief Valeur minimale acceptée pour le jour.
     */
    constexpr static unsigned MINIMUM_DAY { 1 };

    /*!
     * \brief Nombre de jours par mois, _hors_ années bissextiles.
     *
     * Il s'agit des valeurs maximales acceptées pour le jour
     * en fonction du mois, _sans_ tenir compte des années
     * bissextiles. Pour connaître le nombre de jours d'un mois
     * en tenant compte des années bissextiles, il faut utiliser
     * la méthode dayNumberInMonth().
     *
     * La valeur initiale nulle est présente pour permettre
     * d'utiliser directement la valeur du mois comme index
     * de la `std::array`.
     */
    constexpr static std::array < unsigned,
              MAXIMUM_MONTH + 1 > MAXIMUM_DAY
    {{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }};

  private:

    /*!
     * \brief L'année.
     *
     * Cet attribut est constant.
     *
     * Elle est comprise entre \ref MINIMUM_YEAR et
     * \ref MAXIMUM_YEAR, ces valeurs comprises.
     *
     * On considère qu'il y a une
     * [année 0](https://fr.wikipedia.org/wiki/Ann%C3%A9e_z%C3%A9ro).
     */
    const int year_;

    /*!
     * \brief Le mois.
     *
     * Cet attribut est constant.
     *
     * Janvier a comme valeur \ref MINIMUM_MONTH, février
     * \ref MINIMUM_MONTH + 1, etc., jusquà décembre de valeur
     * \ref MAXIMUM_MONTH.
     */
    const unsigned month_;

    /*!
     * \brief Le jour.
     *
     * Cet attribut est constant.
     *
     * Le premier jour du mois a comme valeur \ref MINIMUM_DAY, le
     * suivant \ref MINIMUM_DAY + 1, etc., jusqu'au dernier du mois,
     * dépendant du mois et de l'année et fourni par
     * dayNumberInMonth().
     */
    const unsigned day_;

  public:

    /*!
     * \brief Constructeur.
     *
     * Ce constructeur valide ses arguments à l'aide du modèle
     * de fonction validate(). Dès lors,
     * une exception de type `std::invalid_argument` peut être levée
     * lors de son utilisation.
     *
     * On considère qu'il y a une
     * [année 0](https://fr.wikipedia.org/wiki/Ann%C3%A9e_z%C3%A9ro).
     *
     * \param year l'année.
     * \param month le mois.
     * \param day le jour.
     *
     * \throw std::invalid_argument si :
     *  + year \f$\notin\f$ [Date::MINIMUM_YEAR, Date::MAXIMUM_YEAR]
     *  + month \f$\notin\f$ [Date::MINIMUM_MONTH, Date::MAXIMUM_MONTH]
     *  + day \f$\notin\f$ [Date::MINIMUM_DAY, Date::MAXIMUM_DAY[month]]
     *  tenant compte des années bissextiles.
     *
     * \see year_, month_, day_.
     */
    Date(int year, unsigned month, unsigned day);

    /*!
     * \brief Accesseur en lecture de l'année.
     *
     * \return l'année.
     */
    inline int year() const;

    /*!
     * \brief Accesseur en lecture du mois.
     *
     * \return le mois.
     */
    inline unsigned month() const;

    /*!
     * \brief Accesseur en lecture du jour.
     *
     * \return le jour.
     */
    inline unsigned day() const;

    /*!
     * \brief Méthode pour déterminer si l'année courante est
     *        bissextile.
     *
     * \return `true` si l'année courante est bissextile, `false`
     *         sinon.
     *
     * \see leapYear(int).
     */
    inline bool leapYear() const;

    /*!
     * \brief Méthode pour connaître le nombre de jours du mois
     *        courant.
     *
     * \return le nombre de jours du mois courant.
     */
    inline unsigned dayNumberInMonth() const;

    /*!
     * \brief Méthode pour obtenir la date courante sous la forme
     *        d'une std::string.
     *
     * La `std::string` retournée est `"jj/mm/aaaa"`, par exemple
     * `"26/04/2016"`.
     *
     * Il s'agit de la même forme que celle lors de l'injection
     * d'une Date dans un flux en sortie
     * (voir operator<<(std::ostream &, const Date &)).
     *
     * \return une représentation de la date courante sous la forme
     *         d'une std::string.
     *
     * \see to_string(const Date &).
     */
    std::string to_string() const;
};

// prototypes

/*!
 * \brief Opérateur d'injection d'une Date dans un flux en sortie.
 *
 * La Date est injectée sous la forme `jj/mm/aaaa`, par exemple
 * `26/04/2016`.
 *
 * Il s'agit de la même forme que celle
 * retournée par \ref g43317::Date::to_string().
 *
 * \param out le flux dans lequel la Date est injectée.
 * \param in la Date injectée dans le flux en sortie.
 *
 * \return le flux dans lequel la Date a été injectée.
 */
std::ostream & operator<<(std::ostream & out, const Date & in);

/*!
 * \brief Opérateur de comparaison de deux dates.
 *
 * La valeur `true` est retournée si `lhs` est
 * _strictement antérieure_ à `rhs`. Lorsque `lhs` est
 * _égale ou postérieure_ à `rhs`, `false` est retourné.
 *
 * \param lhs une Date.
 * \param rhs une autre Date.
 * \return `true` si lhs est strictement antérieure à rhs,
 *         `false` sinon.
 */
inline bool operator<(const Date & lhs, const Date & rhs);

/*!
 * \brief Opérateur de test d'égalité de deux dates.
 *
 * \param lhs une Date.
 * \param rhs une autre Date.
 * \return `true` si les deux dates sont identiques, `false` sinon.
 */
inline bool operator==(const Date & lhs, const Date & rhs);

/*!
 * \brief Fonction de conversion d'une g43317::Date en std::string.
 *
 * La `std::string` retournée est `"jj/mm/aaaa"`, par exemple
 * `"26/04/2016"`.
 *
 * Il s'agit de la même forme que celle lors de l'injection
 * d'une Date dans un flux en sortie
 * (voir operator<<(std::ostream &, const Date &)).
 *
 * L'appel :
 *
 *     to_string(in);
 *
 * est équivalent à celui-ci :
 *
 *     in.to_string();
 *
 * \param in la Date à convertir.
 *
 * \return une représentation de la date courante sous la forme
 *         d'une std::string.
 *
 * \see Date::to_string().
 */
inline std::string to_string(const Date & in);

/*!
 * \brief Fonction retournant la date actuelle (au moment de
 *        l'exécution) sous la forme d'une Date.
 *
 * \return la date au moment de l'exécution comme une Date.
 *
 * \see http://en.cppreference.com/w/cpp/chrono/time_point
 * \see http://en.cppreference.com/w/cpp/chrono/c/time
 * \see http://en.cppreference.com/w/cpp/chrono/c/localtime
 */
Date today();

/*!
 * \brief Fonction pour déterminer si une année est bissextile.
 *
 * \param year l'année à tester.
 *
 * \return `true` si `year` est bissextile, `false` sinon.
 *
 * \see Date::leapYear().
 */
inline bool leapYear(int year);

// implémentations inline

// fonctions inline

bool operator<(const Date & lhs, const Date & rhs)
{
    if (lhs.year() < rhs.year())
    {
        return true;
    }
    if (lhs.year() == rhs.year() && lhs.month() < rhs.month())
    {
        return true;
    }
    if (lhs.year() == rhs.year()
            && lhs.month() == rhs.month()
            && lhs.day() < rhs.day())
    {
        return true;
    }
    return false;
}

bool operator==(const Date & lhs, const Date & rhs)
{
    return lhs.year() == rhs.year()
           && lhs.month() == rhs.month()
           && lhs.day() == rhs.day();
}

std::string to_string(const Date & in)
{
    return in.to_string();
}

bool leapYear(int year)
{
    return (year % 4 == 0) && (year % 100 != 0 || (year % 400 == 0));
}

// méthodes inline

int Date::year() const
{
    return year_;
}

unsigned Date::month() const
{
    return month_;
}

unsigned Date::day() const
{
    return day_;
}

bool Date::leapYear() const
{
    return (year_ % 4 == 0) && (year_ % 100 != 0 || (year_ % 400 == 0));
}

unsigned Date::dayNumberInMonth() const
{
    if (leapYear() && month_ == 2)
    {
        return 29;
    }
    else
    {
        return MAXIMUM_DAY[month_];
    }
}

} // namespace g43317

#endif // DATE_H
