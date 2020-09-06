#ifndef SEX_HPP
#define SEX_HPP

#include <string>
#include "misc/formoption.h"

/*!
 * @brief Namespace de g43317
 */
namespace g43317
{

/**
 * @brief Cette énumération représente le sexe d'une personne.
 */
enum class Sex
{
    /**
    * Indique que la valeur du sexe est inconnue.
    */
    UNKNOWN,
    /**
     * Indique que la valeur du sexe est celle d'une femme.
     */
    FEMALE,
    /**
     * Indique que la valeur du sexe est celle d'un homme.
     */
    MALE,
    /**
     * Indique l'absence de valeur pour le sexe.
     */
    VOID,
    /**
     * Indique que la valeur du sexe n'est ni Sex::UNKNOWN, ni Sex::FEMALE, ni Sex::MALE, ni Sex::VOID.
     */
    OTHER
};

/* note: dans les hpp c'est bien d'écrire tous les prototypes avant les implémentations.
 * Sans ça, il faut retenir les dépendances entre toutes les fonctions (ici l'opérateur << utilise to_string
 * donc on aurait été obligé d'écrire to_string en premier...).
 */

// prototypes:

/**
 * @brief Opérateur d'injection d'une variable ou valeur nvs::Sex dans un flux en sortie.
 * @details La valeur injectée correspond à la forme courte retournée par la fonction to_string(Sex, FormOption).
 * @param out le flux dans lequel réaliser l'injection.
 * @param in la variable ou la valeur à injecter.
 * @return le flux après injection.
 */

inline std::ostream & operator<< (std::ostream & out, Sex in);

/**
 * @brief Fonction de conversion d'une variable / valeur g43317::Sex en std::string.
 * @details En forme courte (fo différent de FormOption::LONG), la std::string retournée est :
 * - u pour la valeur Sex::UNKNOWN ;
 * - f pour la valeur Sex::FEMALE ;
 * - m pour la valeur Sex::MALE ;
 * - v pour la valeur Sex::VOID ;
 * - o pour la valeur Sex::OTHER.
 *
 * C'est la même forme que celle injectée par l'opérateur d'injection dans un flux en sortie.
 *
 * En forme longue (fo explicitement égal à FormOption::LONG), la std::string retournée est :
 * - unknown pour la valeur Sex::UNKNOWN ;
 * - female pour la valeur Sex::FEMALE ;
 * - male pour la valeur Sex::MALE ;
 * - void pour la valeur Sex::VOID ;
 * - other pour la valeur Sex::OTHER
 * @param sex la valeur de g43317::Sex à convertir.
 * @param fo  pour contrôler la forme courte ou longue de la std::string retournée.
 * @return une représentation de la valeur de sex sous la forme d'une std::string.
  **/
inline std::string to_string(Sex sex,
                             FormOption fo = FormOption::SHORT);

// implémentations:

inline std::string to_string (Sex sex, FormOption fo)
{
    std::string s;
    switch (sex)
    {
        case Sex::FEMALE : s = "female" ;
            break;
        case Sex::MALE : s = "male";
            break;
        case Sex::OTHER : s = "other";
            break;
        case Sex::VOID : s = "void";
            break;
        default: s = "unknown";
            break;
    }
    if (fo == FormOption::SHORT)
    {
        s = s.substr(0, 1);
    }
    return s;
}

inline std::ostream & operator<< (std::ostream & out, Sex in)
{
    return out << to_string(in, FormOption::SHORT);
}

} // namespace g43317
#endif // SEX_HPP
