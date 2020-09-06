/*!
* \file dlnode_utility.h
*
* \brief Fonctions diverses de traitement de éléments de listes
* bi-chaînées.
*/
#ifndef DLNODE_UTILITY_H
#define DLNODE_UTILITY_H

#include "dlnode.h"

/*!
* \brief Accès en lecture d’un élément suivant en position donnée.
*
* \param pDLN adresse du struct DLNode dont on désire accèder à
* un suivant.
* \param value position relative de l’élément désiré :
* + une valeur positive indique un déplacement via
* le champ ‘next‘ ;
* + une valeur négative indique un déplavement via
* le champ ‘previous‘.
*
* \return adresse de l’élément ‘value‘ positions après celui
* d’adresse ‘pDLN‘ ou ‘NULL‘ s’il n’y en a pas.
*/
struct DLNode * forwardDLN(struct DLNode * pDLN, int value);

/*!
* \brief Accès en lecture d’un élément précédant en position donnée.
*
* \param pDLN adresse du struct DLNode dont on désire accèder à
* un précédant.
* \param value position relative de l’élément désiré :
* + une valeur positive indique un déplacement via
* le champ ‘previous‘ ;
* + une valeur négative indique un déplavement via
* le champ ‘next‘.
*
* \return adresse de l’élément ‘value‘ positions avant celui
* d’adresse ‘pDLN‘ ou ‘NULL‘ s’il n’y en a pas.
*/
struct DLNode * backDLN(struct DLNode * pDLN, int value);
#endif // DLNODE_UTILITY_H
