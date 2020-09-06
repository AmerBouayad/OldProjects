/*!
* \file dllist.h
*
* \brief Définition d’un type représentant une liste bi-chaînée.
*/
#ifndef DLLIST_H
#define DLLIST_H

#include <stdbool.h>
#include <stddef.h>

#include "dlnode.h"

/*!
* \brief Valeurs d’erreurs associées à une liste.
*/
enum DLLError
{
    /*!
    * \brief Erreur lors d’une allocation mémoire d’une liste ou
    * d’un de ses éléments.
    */
    EDLLMEMORYFAIL = 60,

    /*!
    * \brief Opération interdite car la liste est vide.
    */
    EDLLEMPTY
};

/*!
* \brief Structure représentant une liste doublement chaînée
* ([doubly linked list]
* (https://en.wikipedia.org/wiki/Doubly_linked_list)).
*/
struct DLList
{
    /*!
    * \brief Tête de la liste bi-chaînée.
    *
    * L’élément de tête de liste est celui qui ne possède pas de
    * précédant.
    */
    struct DLNode * head;

    /*!
    * \brief Queue de la liste bi-chaînée.
    *
    * L’élément en queue de liste est celui qui ne possède pas de
    * suivant.
    */
    struct DLNode * tail;
};

/*!
* \brief Création d’une liste bi-chaînée.
*
* La liste est créée vide, c’est-à-dire que ses champs ‘head‘
* et ‘tail‘ sont mis à ‘NULL‘.
*
* Si l’allocation dynamique échoue :
* + ‘errno‘ est mis à ::EDLLMEMORYFAIL ;
* + ‘NULL‘ est retourné.
*
* \return adresse de la struct DLList créée.
*/
struct DLList * newDLL();

/*!
* \brief Destruction d’une liste bi-chaînée.
*
* La struct DLList dont l’adresse est fournie est dédruite
* puis mise à ‘NULL‘. La destruction de la liste implique
* la destruction de tous ses éléments.
*
* Si ‘adpDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param adpDLL adresse d’un pointeur de struct DLList vers la
* struct DLList à détruire.
*/
void deleteDLL(struct DLList ** adpDLL);

/*!
* \brief Destruction du contenu de la liste.
*
* Tous les struct DLNode qui constituent la liste sont détruits,
* mais pas la liste elle-même. En fin de fonction, la liste est
* vide, ses champs ‘head‘ et ‘tail‘ sont mis à ‘NULL‘.
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLL adresse de la struct DLList dont on désire
* détruite les éléments.
*/
void clearDLL(struct DLList * pDLL);

/*!
* \brief Accès en lecture de l’élément en tête de liste.
*
* Si la liste pointée par ‘pDLL‘ est vide, ‘NULL‘ est retourné.
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLL adresse de la struct DLList dont on désire connaître
* le struct DLNode de tête.
*
* \return adresse du struct DLNode en tête de la liste pointée
* par ‘pDLL‘.
*/
struct DLNode * getHeadDLL(const struct DLList * pDLL);

/*!
* \brief Accès en lecture de la valeur de l’élément en tête de liste.
*
* Si la liste est vide :
* + la valeur retournée est indéterminée ;
* + ‘errno‘ est mis à ::EDLLEMPTY.
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLL adresse de la struct DLList dont on désire connaître
* la valeur de tête.
*
* \return valeur contenue dans le struct DLNode en tête de la liste
* pointée par ‘pDLL‘.
*/
value_t getHeadValueDLL(const struct DLList * pDLL);

/*!
* \brief Accès en lecture de l’élément en queue de liste.
*
* Si la liste pointée par ‘pDLL‘ est vide, ‘NULL‘ est retourné.
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLL adresse de la struct DLList dont on désire connaître
* le struct DLNode de queue.
*
* \return adresse du struct DLNode en queue de la liste pointée
* par ‘pDLL‘.
*/
struct DLNode * getTailDLL(const struct DLList * pDLL);

/*!
* \brief Accès en lecture de la valeur de l’élément en queue de liste.
*
* Si la liste est vide :
* + la valeur retournée est indéterminée ;
* + ‘errno‘ est mis à ::EDLLEMPTY.
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLL adresse de la struct DLList dont on désire connaître
* la valeur de queue.
*
* \return valeur contenue dans le struct DLNode en queue de la
* liste pointée par ‘pDLL‘.
*/
value_t getTailValueDLL(const struct DLList * pDLL);

/*!
* \brief Accès en lecture de la nature vide ou non de la liste.
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLL adresse de la struct DLList dont on désire savoir
* si elle est vide ou non.
*
* \return ‘true‘ si la liste pointée par ‘pDLL‘ ne contient aucun
* struct DLNode, ‘false‘ sinon.
*/
bool isEmptyDLL(const struct DLList * pDLL);

/*!
* \brief Accès en lecture de la taille de la liste.
*
* La taille de la liste est le nombre de struct DLNode qui la
* constituent. Une liste vide est donc de taille nulle.
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLL adresse de la struct DLList dont on désire
* connaître la taille.
*
* \return nombre d’éléments de la liste pointée par ‘pDLL‘.
*/
size_t getSizeDLL(const struct DLList * pDLL);

/*!
* \brief Insertion d’un élément en tête de liste.
*
* Si l’instanciation du struct DLNode destiné à être la
* nouvelle tête de liste échoue :
* + la liste est laissée telle quelle ;
* + ‘errno‘ est mis à ::EDLLMEMORYFAIL.
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLL adresse de la liste dont on veut modifier
* l’élément de tête.
* \param value valeur que doit renfermer l’élément en tête de liste.
*
* \return adresse de la nouvelle tête de liste... ou
* l’ancienne en cas d’échec.
*/
struct DLNode * insertHeadDLL(struct DLList * pDLL, value_t value);

/*!
* \brief Suppression de l’élément en tête de liste.
*
* Si la liste pointée par ‘pDLL‘ est initialement vide :
* + la liste est laissée telle quelle ;
* + ‘errno‘ est mis à ::EDLLEMPTY ;
* + ‘NULL‘ est retourné.
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLL adresse de la liste dont on veut ôter
* l’élément de tête.
*
* \return adresse de la nouvelle tête de liste... ou
* ‘NULL‘ si elle est désormais vide.
*/
struct DLNode * removeHeadDLL(struct DLList * pDLL);

/*!
* \brief Insertion d’un élément en queue de liste.
*
* Si l’instanciation du struct DLNode destiné à être la
* nouvelle queue de liste échoue :
* + la liste est laissée telle quelle ;
* + ‘errno‘ est mis à ::EDLLMEMORYFAIL.
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLL adresse de la liste dont on veut modifier
* l’élément de queue.
* \param value valeur que doit renfermer l’élément en queue de liste.
*
* \return uadresse de la nouvelle queue de liste... ou
* l’ancienne en cas d’échec.
*/
struct DLNode * insertTailDLL(struct DLList * pDLL, value_t value);

/*!
* \brief Suppression de l’élément en queue de liste.
*
* Si la liste pointée par ‘pDLL‘ est initialement vide :
* + la liste est laissée telle quelle ;
* + ‘errno‘ est mis à ::EDLLEMPTY ;
* + ‘NULL‘ est retourné.
*
* Si ‘pDLL‘ est ‘NULL‘, le comportement de la fonction est
* indéterminé.
*
* \param pDLL adresse de la liste dont on veut ôter
* l’élément de queue.
*
* \return adresse de la nouvelle queue de liste... ou
* ‘NULL‘ si elle est désormais vide.
*/
struct DLNode * removeTailDLL(struct DLList * pDLL);

/*!
* \brief Insertion d’une nouvelle valeur dans la liste _après_ un
* élément spécifique.
*
* Si l’instanciation du struct DLNode destiné à être inséré dans
* la liste échoue :
* + la liste est laissée telle quelle ;
* + ‘errno‘ est mis à ::EDLLMEMORYFAIL.
*
* La fonction ne vérifie pas que l’élément pointé par ‘pDLN‘ se
* trouve bien dans la liste pointée par ‘pDLL‘. Si ce n’est pas
* le cas, l’intégrité de la liste n’est pas garantie.
*
* Si ‘pDLL‘ ou ‘pDLN‘ sont ‘NULL‘, le comportement de la fonction
* est indéterminé.
*
* \param pDLL adresse de la liste dans laquelle on désire insérer
* un nouvel élément.
* \param pDLN adresse de l’élément de la liste après lequel
* l’insertion doit avoir lieu.
* \param newValue valeur conservée dans le nouvel élément à
* insérer.
*
* \return adresse du nouvel élément inséré... ou ‘pDLN‘
* en cas d’échec.
*/
struct DLNode * insertAfterDLL(struct DLList * pDLL,
                               struct DLNode * pDLN,
                               value_t newValue);

/*!
* \brief Insertion d’une nouvelle valeur dans la liste _avant_ un
* élément spécifique.
*
* Si l’instanciation du struct DLNode destiné à être inséré dans
* la liste échoue :
* + la liste est laissée telle quelle ;
* + ‘errno‘ est mis à ::EDLLMEMORYFAIL.
*
* La fonction ne vérifie pas que l’élément pointé par ‘pDLN‘ se
* trouve bien dans la liste pointée par ‘pDLL‘. Si ce n’est pas
* le cas, l’intégrité de la liste n’est pas garantie.
*
* Si ‘pDLL‘ ou ‘pDLN‘ sont ‘NULL‘, le comportement de la fonction
* est indéterminé.
*
* \param pDLL adresse de la liste dans laquelle on désire insérer
* un nouvel élément.
* \param pDLN aderesse de l’élément de la liste avant lequel
* l’insertion doit avoir lieu.
* \param newValue valeur conservée dans le nouvel élément à
* insérer.
*
* \return adresse du nouvel élément inséré... ou ‘pDLN‘
* en cas d’échec.
*/
struct DLNode * insertBeforeDLL(struct DLList * pDLL,
                                struct DLNode * pDLN,
                                value_t newValue);

/*!
* \brief Suppression d’un élément de la liste.
*
* La fonction ne vérifie pas que l’élément pointé par ‘pDLN‘ se
* trouve bien dans la liste pointée par ‘pDLL‘. Si ce n’est pas
* le cas, l’intégrité de la liste n’est pas garantie.
*
* Si la liste pointée par ‘pDLL‘ est initialement vide et que
* ‘pDLN‘ est bel et bien ‘NULL‘, rien ne se passe.
*
* Si ‘pDLL‘ est ‘NULL‘ ou si ‘pDLN‘ est ‘NULL‘ alors que la liste,
* n’est pas vide, le comportement de la fonction est indéterminé.
*
* \param pDLL adresse de la liste dont on désire supprimer
* un élément.
* \param pDLN adresse de l’élément à supprimer.
*
* \return adresse de l’élément de la liste qui se trouve, après
* suppression, en même position dans la liste que l’élément
* supprimé, avant sa suppression, c’est-à-dire l’adresse
* de l’élément qui suivait l’élément supprimé avant la
* suppression, ou l’élément de queue de liste si c’est
* l’élément en queue de liste qui a été supprimé ou ‘NULL‘
* si la liste est finalement vide.
*/
struct DLNode * removeDLL(struct DLList * pDLL, struct DLNode * pDLN);

#endif // DLLIST_H
