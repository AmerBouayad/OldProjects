#ifndef PERSON_H
#define PERSON_H
#include <date.h>
#include <sex.hpp>
#include <vector>
#include <sstream>
#include <iomanip> // for setw()
/**
 * \namespace Espace de nom de g43317.
 */
namespace g43317
{

/**
 * @brief Cette classe représente une personne.
 */
class Person
{
  private:
    /**
     * @brief Les prénoms de la personne.
     */
    std::vector<std::string> firstnames_;
    /**
     * @brief Le nom de famille de la personne
     */
    std::string name_;
    /**
     * @brief Le g43317::Sex, représentant le sexe de la personne
     */
    Sex sex_;
    /**
     * @brief La date de naissance de la personne.
     */
    const Date birthdate_;

  public:
    /**
     * @brief Constructeur de Personne.
     * @details Pour ce qui concerne les validations :
     *      * la date de naissance est nécessairement valide ;
     *      * le sexe n'est pas validé ;
     *      * le nom de famille ne peut pas être vide ;
     *      * seuls les prénoms non vide sont retenus, si un prénom apparaît plusieurs fois,
     *          seule sa première occurence est retenue.
     * @param firstnames la liste ordonnée des prémons de la personne.
     * @param name le nom de famille de la personne.
     * @param sex le sexe de la personne.
     * @param birthdate la date de naissance de la personne.
     * @exception std::invalid_argument
     *      * name est vide.
     *      * firstnames est vide.
     *      * firstnames ne contient que des std::string vides.
     */
    Person(const std::vector<std::string> & firstnames,
           const std::string & name, Sex sex, const Date & birthdate);
    /**
     * @brief Constructeur de Personne.
     * @details Pour ce qui concerne les validations :
     *      * la date de naissance est nécessairement valide ;
     *      * le sexe n'est pas validé ;
     *      * le nom de famille ne peut pas être vide ;
     *      * seuls les prénoms non vide sont retenus, si un prénom apparaît plusieurs fois,
     *          seule sa première occurence est retenue.
     * @param firstnames la liste ordonnée des prémons de la personne.
     * @param name le nom de famille de la personne.
     * @param sex le sexe de la personne.
     * @param birthdateyear l'année de naissance de la personne.
     * @param birthdatemonth le mois de naissance de la personne.
     * @param birthdateday le jour de naissance de la personne.
     * @exception std::invalid_argument
     *      * name est vide.
     *      * firstnames est vide.
     *      * firstnames ne contient que des std::string vides.
     */
    Person(const std::vector<std::string> & firstnames,
           const std::string & name, Sex sex, int birthdateyear,
           unsigned birthdatemonth, unsigned birthdateday);

    /**
     * @brief Accesseur en écriture pour ajouter un prénom à la liste de prénoms de la personne.
     * @details L'ajout se fait toujours en bout de la liste des prénoms.
     *
     * Si le nouveau prénom est vide ou est un prénom déjà présent dans la liste, il n'est pas ajouté. Rien ne vient signaler
     * cette absence d'ajout.
     * @param newFirstname le prénom à ajouter.
     */
    void addFirstname (const std::string & newFirstname);
    /**
     * @brief Accesseur en écriture pour ajouter une liste de prénoms à celle de la personne.
     * @details L'ajout se fait toujours en bout de la liste des prénoms.
     *
     * Si la liste de nouveaux prénoms est vide ou si chaque nouveau prénom est vide, aucun prénom n'est ajouté. Cela se
     * passe silencieusement. Si un prénom de la liste des nouveaux prénoms est déjà présent dans la liste des prénoms
     * de la personne, il n'est pas ajouté. Cela également se passe silencieusement.
     * @param newFirstnames liste des prénoms à ajouter.
     */
    void addFirstnames (const std::vector<std::string> & newFirstnames);

    /**
     * @brief Accesseur en lecture de la date de naissance.
     * @return la date de naissance de la personne.
     */
    inline Date birthdate() const;

    /**
     * @brief Accesseur en lecture d'un prénom en position d'index donné de la personne.
     * @param index index du prénom désiré dans la liste de ceux-ci.
     * @return le prénom de la personne d'index fourni.
     * @exception std::out_of_range index déborde du tableau de prénoms.
     */
    inline std::string firstname (unsigned index = 0 ) const;

    /**
     * @brief Accesseur en lecture des prénoms de la personne.
     * @return les prénoms de la personne.
     */
    inline std::vector<std::string> firstnames () const;

    /**
     * @brief Accesseur en écriture pour modifier la liste des prénoms de la personne.
     * @details La liste des nouveaux prénoms doit respecter les mêmes contraintes que la liste des prénoms lors de la création
     * d'une Person : elle ne peut être vide ni ne contenir que des prénoms vide. Si c'est le cas, la liste des prénoms n'est
     * pas modifiée. Ceci se passe sans notification.
     *
     * Si la liste des nouveaux prénoms contient plusieurs fois le même prénom, il n'est inclu qu'une seule fois à la liste
     * des prénoms de la personne. Seuls les prénoms non vides sont pris en compte.
     * @param newFirstnames nouvelle liste des prénoms de la personne.
     */
    void firstnames (const std::vector<std::string> & newFirstnames);

    /**
     * @brief Accesseur en lecture du nombre de prénoms de la personne.
     * @return le nombre de prénoms de la personne.
     */
    unsigned firstnamesCount () const;

    /**
     * @brief Accesseur en lecture du nom de la personne.
     * @return le nom de famille de la personne.
     */
    inline std::string name() const;

    /**
     * @brief Accesseur en écriture du nom de la personne.
     * @details Le nouveau nom est limité par la même contrainte que lors de la création d'une personne : il ne peut pas être vide.
     *
     * Par contre, aucune validation n'est réalisée quant à savoir si la nouvelle valeur du nom est réellement nouvelle.
     *
     * Si le nouveau nom n'est pas valide, le nom de la personne reste inchangé. Rien ne vient signaler cette non-
     * modification.
     * @param newName nouveau nom de la personne.
     */
    void setName(const std::string & newName);

    /**
     * @brief Accesseur en écriture pour supprimer un prénom de la liste des prénoms de la personne.
     *
     * Si le prénom à supprimer n'est pas un prénom de la personne, rien ne se passe.
     * @param oldFirstname prénom à supprimer de la liste des prénoms de la personne.
     */
    void removeFirstname (const std::string & oldFirstname);

    /**
     * @brief Accesseur en écriture pour supprimer un ensemble de prénoms de la liste des prénoms de la personne.
     *
     * Si aucun des prénoms de la liste des prénoms à supprimer n'est un prénom de la personne, rien ne se passe.
     * @param oldFirstnames liste des prénoms à supprimer de la liste des prénoms de la personne.
     */
    void removeFirstnames (const std::vector<std::string>
                           & oldFirstnames);

    /**
     * @brief Accesseur en lecture du sexe de la personne.
     * @return la valeur du sexe de la personne.
     */
    inline Sex sex () const;

    /**
     * @brief Accesseur en écriture du sexe de la personne.
     * Aucune validation n'est réalisée, y compris quant à savoir si la nouvelle valeur est réellement nouvelle.
     * @param newSex nouvelle valeur du sexe de la personne.
     * @return nouvelle valeur du sexe de la personne.
     */
    inline Sex sex (Sex newSex);

    /*!
     * \brief Fonction de conversion d'une g43317::Person en std::string.
     *
     * La `std::string` retournée est  sous la forme 'champ : valeur'
     * suivi d'un passage à la ligne.
     *
     * Il s'agit de la même forme que celle
     * retournée par \ref operator<<(std::ostream &, const Person &).
     *
     * \return une représentation de la Person courante sous la forme
     *         d'une std::string.
     *
     */
    inline std::string to_string() const;

  private:

    /**
     * @brief Validation de la liste des prénoms.
     * @details Une liste de prénoms valide contient au moins un prénom non vide. Si elle contient plusieurs prénoms, la multiplicité
     * de chacun est de un.
     * @param firstnames liste des prénoms à valider.
     * @return la liste des prénoms validée : chaque prénom y apparaît une seule fois, dans l'ordre de première occurence.
     * @exception std::invalid_argument
     *      * firstnames est vide
     *      * firstnames ne contient que des std ::string vides.
     */
    std::vector<std::string> validateFirstnames (
        const std::vector<std::string> & firstnames) const;

    /**
     * @brief Validation du nom.
     * @details Un nom valide est un nom non vide.
     * @param name nom à valider.
     * @return le nom s'il est valide.
     * @exception std::invalid_argument si name est vide.
     */
    std::string validateName (const std::string & name ) const;
};

/*!
 * \brief Opérateur d'injection d'une Person dans un flux en sortie.
 *
 * La Person est injectée sous la forme 'champ : valeur'
 * suivi d'un passage à la ligne.
 *
 * Il s'agit de la même forme que celle
 * retournée par \ref g43317::Person::to_string().
 *
 * \param out le flux dans lequel la Person est injectée.
 * \param in la Person injectée dans le flux en sortie.
 *
 * \return le flux dans lequel la Person a été injectée.
 */
std::ostream & operator<<(std::ostream & out, const Person & in);

// définition des inlines:

Date Person::birthdate() const
{
    return birthdate_;
}

std::string Person::firstname(unsigned index) const
{
    return firstnames_.at(index);
}

std::vector<std::string> Person::firstnames() const
{
    return firstnames_;
}

std::string Person::name() const
{
    return name_;
}

Sex Person::sex() const
{
    return sex_;
}

Sex Person::sex(Sex newSex)
{
    return sex_ = newSex;
}

inline std::string Person::to_string() const
{
    std::ostringstream out;
    out << std::left << std::setw(20) << "Nom" << ": "
        << name_ << std::endl
        << std::setw(21) << "Prénom(s)" << ": ";
    for (auto p : firstnames_)
    {
        out << p << " ";
    }
    out << std::endl
        << std::setw(20) << "Date de naissance" << ": "
        << birthdate_ << std::endl
        << std::setw(20) << "Sexe" << ": " << sex_ << std::endl;
    return out.str();
}


} // namespace g43317

#endif // PERSON_H
