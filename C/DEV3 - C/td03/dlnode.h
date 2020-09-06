/*!
 * \file dlnode.h
 *
 * \brief Définition d’un type représentant un élément de liste
 * bi-chaînée.
 */

#ifndef DLNODE_H
#define DLNODE_H

#include "value_t.h"

/*!
 * \brief Valeurs d’erreurs associées à un élément de liste.
 */
enum DLNError
{
    /*!
     * \brief Erreur lors d’une allocation mémoire d’un élément de
     * liste.
     */
    EDLNMEMORYFAIL = 50
};

/*!
 * \brief Structure représentant le type d’un élément d’une
 * liste doublement chaînée
 * ([doubly linked list]
 * (https://en.wikipedia.org/wiki/Doubly_linked_list)).
 */
struct DLNode
{
    /*!
     * \brief Adresse de l’élément _précédant_ dans la liste.
     *
     * S’il n’y a pas d’élément précédant, ‘previous‘ vaut ‘NULL‘.
     */
    struct DLNode * previous;

    /*!
     * \brief Adresse de l’élément _suivant_ dans la liste.
     *
     * S’il n’y a pas d’élément suivant, ‘next‘ vaut ‘NULL‘.
     */
    struct DLNode * next;

    /*!
     * \brief Valeur conservée par l’élément de la liste.
     */
    value_t value;
};

/*!
 * \brief Création d’une instance de struct DLNode.
 *
 * L’élément de liste créé est dans un état valide : il ne possède ni
 * précédent, ni suivant.
 *
 * Il est alloué dynamiquement et doit donc être détruit quand
 * son usage n’est plus requis.
 *
 * Si l’allocation mémoire échoue :
 * + ‘errno‘ est mis à ::EDLNMEMORYFAIL ;
 * + ‘NULL‘ est retourné.
 *
 * \param value la valeur contenue dans le struct DLNode.
 *
 * \return l’adresse du struct DLNode créé.
 */
struct DLNode * newDLN(value_t value);

/*!
 * \brief Destruction d’une instance de struct DLNode.
 *
 * Le struct DLNode dont l’adresse est fournie est dédruit
 * puis mis à ‘NULL‘.
 *
 * Aucun maillage n’est modifié par la fonction !
 *
 * Si ‘adpDLN‘ est ‘NULL‘, le comportement de la fonction est
 * indéterminé.
 *
 * \param adpDLN adresse d’un pointeur de struct DLNode vers le
 * struct DLNode à détruire.
*/
void deleteDLN(struct DLNode * * adpDLN);

/*!
 * \brief Accès en lecture à l’élément précédant de la liste.
 *
 * Si ‘pDLN‘ est ‘NULL‘, le comportement de la fonction est
 * indéterminé.
 *
 * \param pDLN adresse du struct DLNode dont on désire connaître le
 * précédant.
 *
 * \return Adresse du struct DLNode précédant celui pointé par ‘pDLN‘.
 */
struct DLNode * getPreviousDLN(const struct DLNode * pDLN);

/*!
 * \brief Accès en lecture à l’élément suivant de la liste.
 *
 * Si ‘pDLN‘ est ‘NULL‘, le comportement de la fonction est
 * indéterminé.
 *
 * \param pDLN adresse du struct DLNode dont on désire connaître le
 * suivant.
 *
 * \return Adresse du struct DLNode suivant celui pointé par ‘pDLN‘.
 */
struct DLNode * getNextDLN(const struct DLNode * pDLN);

/*!
* \brief Accès en lecture à la valeur stockée dans l’élément de liste.
*
* Si ‘pDLN‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLN adresse du struct DLNode dont on désire connaître la
* valeur qu’il contient.
*
* \return valeur contenue dans le struct DLNode pointé par ‘pDLN‘.
*/
value_t getValueDLN(const struct DLNode * pDLN);

/*!
 * \brief Accès en écriture à l’élément précédant de la liste.
 *
 * Seul le maillage du struct DLNode pointé par ‘pDLN‘ est modifié
 * par cette fonction.
 * Celui de l’élément pointé par ‘pNewPrevious‘ n’est pas modifié. La
 * mémoire n’est pas gérée ici.
 *
 * Si ‘pDLN‘ est ‘NULL‘, le comportement de la fonction est
 * indéterminé.
 *
 * \param pDLN adresse du struct DLNode dont on désire modifier le
 * précédant.
 * \param pNewPrevious adresse du nouveau struct DLNode précédant
 * celui pointé par ‘pDLN‘.
 */
void setPreviousDLN(struct DLNode * pDLN,
                    struct DLNode * pNewPrevious);

/*!
 * \brief Accès en écriture à l’élément suivant de la liste.
 *
 * Seul le maillage du struct DLNode pointé par ‘pDLN‘ est modifié
 * par cette fonction.
 * Celui de l’élément pointé par ‘pNewNext‘ n’est pas modifié. La
 * mémoire n’est pas gérée ici.
 *
 * Si ‘pDLN‘ est ‘NULL‘, le comportement de la fonction est
 * indéterminé.
 *
 * \param pDLN adresse du struct DLNode dont on désire modifier le
 * suivant.
 * \param pNewNext adresse du nouveau struct DLNode suivant celui
 * pointé par ‘pDLN‘.
 */
void setNextDLN(struct DLNode * pDLN, struct DLNode * pNewNext);

/*!
* \brief Accès en écriture à la valeur contenue dans l’élément de
* liste.
*
* Si ‘pDLN‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLN adresse du struct DLNode dont on désire modifier la
* valeur.
* \param newValue nouvelle valeur à conserver dans le struct DLNode
* pointé par ‘pDLN‘.
*/
void setValueDLN(struct DLNode * pDLN, value_t newValue);

#endif // DLNODE_H
