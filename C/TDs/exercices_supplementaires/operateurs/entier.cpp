#include "entier.h"

Entier::Entier(int v) : valeur(v)
{}

Entier Entier::operator+(const int & b) const
{
    return Entier(valeur + b);
}

Entier operator+(const int & a, const Entier & b)
{
    return b + a; // on utilise l'opérateur entre un Entier et un int
}

std::ostream & operator<<(std::ostream & out,
                          const Entier & a)
{
    return out << a.valeur;
}


