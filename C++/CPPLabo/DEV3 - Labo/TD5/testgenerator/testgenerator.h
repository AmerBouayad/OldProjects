/*!
 * \file testgenerator.h
 * \brief Définition de fonctions pour la création de Date et Person.
 */
#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H

#include <tuple>
#include <string>
#include <vector>

/*!
 * \mainpage Des fonctions pour tester les classes Date et Person
 *
 * Un bon point d'entrée est celui de la documentation de
 * l'espace de nom \ref nvs.
 *
 */

/*!
 * \brief Espace de nom de Nicolas Vansteenkiste.
 */
namespace nvs
{

/*!
 * \brief Générateur d'arguments pour la construction d'une Date.
 *
 * Parmi les valeurs retournées, certaines permettent de produire
 * une Date correcte, d'autres devraient produire une erreur lors
 * de la création de la Date correspondante.
 *
 * Le générateur de nombres uniformément aléatoires urng() est
 * utilisé, sans bruit. Si vous désirez des séquences différentes
 * d'une exécution à l'autre, il faut invoquer randomize() _avant_
 * dategenerator().
 *
 * \return un std::tuple dont :
 *          * le premier élément (celui d'indice 0) est à utiliser
 *            comme argument pour l'_année_ ;
 *          * le deuxième élément (celui d'indice 1) est à utiliser
 *            comme argument pour le _mois_ ;
 *          * le dernier élément (celui d'indice 2) est à utiliser
 *            comme argument pour le _jour_.
 */
std::tuple<int, unsigned, unsigned> dategenerator();

/*!
 * \brief Générateur d'arguments pour la construction d'une Person.
 *
 * Cette fonction retourne l'ensemble des arguments nécessaires
 * à la création d'une instance de Person.
 * Aucun des ensembles de valeurs retournés ne produit une erreur
 * lors de son utilisation par les constructeurs de Person tels que
 * ceux demandés, mais :
 *  + dans la liste des prénoms, certains peuvent apparaître
 *    plusieurs fois ;
 *  + les listes de prénoms sont de longueurs variables ;
 *  + il n'y a que deux valeurs possibles pour le sexe de la
 *    Person :
 *      - un `'f'` indique une femme ;
 *      - un `'m'` indique une homme.
 *
 * Le générateur de nombres uniformément aléatoires urng() est
 * utilisé, sans bruit. Si vous désirez des séquences différentes
 * d'une exécution à l'autre, il faut invoquer randomize() _avant_
 * people().
 *
 * \param size le nombre d'éléments du std::vector retourné.
 *
 * \return un std::vector de std::tuple dont :
 *          + le premier élément (celui d'indice 0) est un
 *            std::vector de std::string à utiliser
 *            comme argument pour la _liste de prénoms_ de la
 *            Person ;
 *          + le deuxième élément (celui d'indice 1) est une
 *            std::string à utiliser
 *            comme argument pour le _nom_ de la Person ;
 *          + le troisième élément (celui d'indice 2) est un char à
 *            utiliser pour déterminer le _sexe_ de la Person :
 *              - `'f'` pour `Sex::FEMALE` ;
 *              - `'m'` pour `Sex::MALE` ;
 *          + le dernier élément (celui d'indice 3) est un
 *            std::tuple à utiliser pour fixer la
 *            _date de naissance_ de la Person en prenant :
 *              - en guise d'_année de naissance_ le premier
 *                élément de ce std::tuple, c'est-à-dire celui
 *                d'index 0 ;
 *              - en guise de _mois de naissance_ le deuxième
 *                élément de ce std::tuple, c'est-à-dire celui
 *                d'index 1 ;
 *              * en guise de _jour de naissance_ le deuxième
 *                élément de ce std::tuple, c'est-à-dire celui
 *                d'index 2.
 */
std::vector<std::tuple<std::vector<std::string>, std::string, char,
    std::tuple<int, unsigned, unsigned>>>
    people(unsigned size = 1000);

} // namespace nvs

#endif // TESTGENERATOR_H
