/*!
 * \file formoption.h
 * \brief Définition de l'énumération fortement typée
 *        nvs::FormOption.
 */
#ifndef FORMOPTION_H
#define FORMOPTION_H

namespace nvs
{

/*!
 * \brief Énumération pour spécifier les options de mise en forme
 *        d'impression ou de conversion binaire → chaîne de 
 *        caractères.
 */
enum class FormOption
{
    /*!
     * \brief Absence de spécification.
     */
    NONE = 0b0000,
    // binary literals : c++14 :
    // http://www.informit.com/articles/article.aspx?p=2209021

    /*!
     * \brief Forme courte.
     */
    SHORT = 0b0001,

    /*!
     * \brief Forme longue.
     */
    LONG = 0b0010
};

} // namespace nvs

#endif // FORMOPTION_H

