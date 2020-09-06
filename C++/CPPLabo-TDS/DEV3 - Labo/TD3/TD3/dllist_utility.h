/*
 \file dllist_utility.h

 \brief Fonctions diverses de traitement de listes bi-chaînées.
*/
#ifndef DLLIST_UTILITY_H
#define DLLIST_UTILITY_H


#include "dllist.h"

/*
* \brief Description de la méthode de tri.
*
* Cette énumération est utilisée par la fonction ::sortDLL().
*/
enum SortingMethod
{
/*
* \brief Tri par remaillage des éléments de la liste.
*/
SORT_BY_CHANGING_LINK,
/*
* \brief Tri par modification des valeurs des éléments de
* la liste.
ABS – BEJ – NVS [18/21]
rsion du 18 octobre 2017, 18:56:41) CPPL1 : TD 3 : C : Liste bi-chaînée
*/
SORT_BY_CHANGING_VALUE
};

/*
* \brief Conversion d’une liste en tableau dynamique.
*
* Le premier élément du tableau dynamique retourné est l’élément
* en tête de liste, le deuxième celui qui suit (‘pDLL->head->next‘),
* etc. jusqu’au dernier qui est la queue de liste.
*
* Si la liste est vide, la variable pointée par ‘size‘ est mise à
* 0 et ‘NULL‘ est retourné.
*
* Si l’allocation de mémoire échoue :
* + le contenu de la variable pointée par ‘size‘ n’est pas
* modifié ;
* + ‘errno‘ est mis à ::EDLLMEMORYFAIL ;
* + ‘NULL‘ est retourné.
*
* \param size adresse d’une variable où le nombre d’éléments du
* tableau dynamique retourné.
* \param pDLL adresse de la liste à convertir en tableau.
*
* \return adresse du premier élément du tableau dynamique produit.
*/
value_t * to_arrayDLL(size_t * size, const struct DLList * pDLL);

/*
* \brief Conversion d’une liste en tableau dynamique.
*
* Le premier élément du tableau dynamique retourné est l’élément
* en queue de liste, le deuxième celui qui précède
* (‘pDLL->tail->previous‘), etc. jusqu’au dernier qui est la tête
* de liste.
*
* Si la liste est vide, la variable pointée par ‘size‘ est mise à
* 0 et ‘NULL‘ est retourné.
*
* Si l’allocation de mémoire échoue :
* + le contenu de la variable pointée par ‘size‘ n’est pas
* modifié ;
* + ‘errno‘ est mis à ::EDLLMEMORYFAIL ;
* + ‘NULL‘ est retourné.
*
* \param size adresse d’une variable où le nombre d’éléments du
* tableau dynamique retourné.
* \param pDLL adresse de la liste à convertir en tableau.
*
* \return adresse du premier élément du tableau dynamique produit.
*/
value_t * to_array_reverseDLL(size_t * size,
const struct DLList * pDLL);

/*
* \brief Production d’une liste inverse d’une originale
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction
* est indéterminé.
*
* Si l’allocation de mémoire pour produire la liste fusionnée
* échoue :
* + ‘errno‘ est mis à ::EDLLMEMORYFAIL ;
* + ‘NULL‘ est retourné.
*
* \param pDLL l’adresse de la liste dont on désire produire
* une liste inversée.
*
* \return adresse de la liste inverse de celle pointée par
* ‘pDLL‘.
*/
struct DLList * reverseDLL(const struct DLList * pDLL);

/*
* \brief Tri d’une liste.
 *
 * Si ‘pDLL‘ ou ‘comp‘ sont ‘NULL‘, le comportement de la fonction
 * est indéterminé.
 *
 * La fonction ‘comp‘ définit l’ordre des éléménent de la liste
 * triée comme la fonction d’ordre utilisée par la fonction standard
 * [qsort](http://en.cppreference.com/w/c/algorithm/qsort).
 *
 * Il est possible de choisir le type de tri :
 * + avec ‘sm‘ valant ::SORT_BY_CHANGING_LINK, le maillage des
 * éléments de la liste est modifié, mais les valeurs contenues
 * par les éléments ne sont pas modifiées ;
 * + avec ‘sm‘ valant ::SORT_BY_CHANGING_VALUE, les valeurs
ABS – BEJ – NVS [20/21]
rsion du 18 octobre 2017, 18:56:41) CPPL1 : TD 3 : C : Liste bi-chaînée
 * contenues dans les éléments sont modifiées, mais le maillage
 * des éléments de la liste n’est pas modifié.
 *
 * \param pDLL adresse de la liste à trier.
 * \param comp fonction d’ordre utilisée pour ordonner les éléments
 * de la liste.
 * \param sm choix du type de tri.
 */
 void sortDLL(struct DLList * pDLL, int (* comp)(value_t, value_t),
 enum SortingMethod sm);

 /*
 * \brief Fusion de listes triées.
 *
 * La liste produite est ordonnée selon la fonction d’ordre ‘comp‘.
 *
 * Si les listes à fusionner ne sont pas ordonnées comme la fonction
 * ‘comp‘ le définit, le comportement de la fonction est indéterminé.
 *
 * Si l’allocation de mémoire pour produire la liste fusionnée
 * échoue :
 * + ‘errno‘ est mis à ::EDLLMEMORYFAIL ;
 * + ‘NULL‘ est retourné.
 *
 * Si ‘pDLL_l‘ ou ‘pDLL_r‘ sont ‘NULL‘, le comportement de la
 * fonction est indéterminé.
 *
 * \param pDLL_l adresse d’une liste triée selon l’ordre défini par
 * ‘comp‘.
 * \param pDLL_r adresse d’une liste triée selon l’ordre défini par
 * ‘comp‘.
 * \param comp fonction d’ordre utilisée pour ordonner ‘pDLL_l‘,
 * ‘pDLL_r‘ et la fusion de ces listes.
 *
 * \return adresse d’une liste dont le contenu est la fusion des
 * listes ‘pDLL_l‘ et ‘pDLL_r‘.
 */
 struct DLList * mergeDLL(const struct DLList * pDLL_l,
 const struct DLList * pDLL_r,
 int (* comp)(value_t, value_t));

 #endif // DLLIST_UTILITY_H
