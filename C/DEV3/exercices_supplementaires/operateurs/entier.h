#ifndef ENTIER_H
#define ENTIER_H
#include <ostream>
/**
 * @brief Une classe d'entier très simple, uniquement destinnées à faire quelques tests
 * sur la surcharge d'opérateurs.
 */
class Entier
{
    // friends are accessible no matter where they are defined in the class
    // (inside the public section as well as in private)
    friend std::ostream & operator<<(std::ostream & out,
                                     const Entier & a);
    // qtcreator complains but not gcc:
    friend Entier operator+(const int & b, const Entier & a);

  private:
    int valeur;

  public:
    /**
     * @brief Constructeur d'Entier
     * @param v la valeur.
     */
    Entier(int v);
    Entier operator+(const int & b) const;
};

// prototypes:

// définition des inlines:






#endif // ENTIER_H
