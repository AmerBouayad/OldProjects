/*!
 * \file validation.hpp
 * \brief Fonctions d'aide à la validation.
 */
#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <functional>
#include <utility>
#include <string>
#include <stdexcept>

namespace g43317
{

/*!
 * \brief Évaluation si une valeur est comprise entre deux autres.
 *
 * Les opérateurs `<` et `==` doivent être disponibles pour le type
 * `T`.
 *
 * \param value valeur à tester.
 * \param min borne minimale.
 * \param max borne maximale.
 *
 * \return `true` si `min <= value <= max`, `false` sinon.
 */
template<typename T>
bool between(const T & value, T min, T max)
{
    // reference_wrapper pour que ça fonction avec classe immuable
    std::reference_wrapper<T> min_ { min };
    std::reference_wrapper<T> max_ { max };

    if (max_ < min_) std::swap(min_, max_);

    return (min_ < value || min_ == value) &&
           (value < max_ || value == max_);
}

/*!
 * \brief Production d'un message d'erreur.
 *
 * La fonction `to_string()` doit être disponible pour le type `T`.
 *
 * \param value valeur.
 * \param min borne minimale.
 * \param max borne maximale.
 * \param msg en-tête du message.
 *
 * \return message d'erreur.
 *
 * \see validate()
 */
template<typename T>
std::string error_message(const T & value, T min, T max,
                          const std::string & msg = "error : ")
{
    // pour les types primitifs hors namespace g43317...
    using std::to_string;

    // reference_wrapper pour que ça fonction avec classe immuable
    std::reference_wrapper<T> min_ { min };
    std::reference_wrapper<T> max_ { max };

    if (max_ < min_) std::swap(min_, max_);

    return msg + to_string(value) + " not in [" +
           to_string(min_) + ", " + to_string(max_) + "]";
}

/*!
 * \brief Validation d'une valeur entre deux bornes.
 *
 * \param value valeur à valider.
 * \param min borne minimale.
 * \param max borne maximale.
 * \param msg en-tête du message en cas de problème.
 *
 * \return `value` si `min <= value <= max`.
 *
 * \throw std::invalid_argument si
 *              value \f$\notin\f$ [`min`, `max`]
 *
 * \see between()
 */
template<typename T>
T validate(const T & value, const T & min, const T & max,
           const std::string & msg = "error : ")
{
    if (!between(value, min, max))
    {
        throw std::invalid_argument { error_message(value, min,
                                      max, msg) };
    }

    return value;
}

} // namespace g43317

#endif // VALIDATION_HPP
