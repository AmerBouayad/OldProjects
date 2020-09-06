#ifndef ARRAY_UTILITY_H
#define ARRAY_UTILITY_H
#include <iostream>
#include <map>

namespace container_utility
{
/**
 * Prints an array of any type.
 * @param a the array.
 */
template <typename T, std::size_t taille>
inline void print(std::array<T, taille> a)
{
    std::cout << "array:" << std::endl;
    // T is probably better than auto as the type won't have to be deduced two times
    for (T elem : a)
    {
        std::cout << elem << " ";
    }
}

// on peut même imprimer un conteneur de n'importe quel type qui contient n'importe quel type:

/**
 * Prints any iterable container.
 * @param c the container
 */
template <typename C>
inline void print_generic(C c)
{
    std::cout << "container:" << std::endl;
    for (auto elem : c)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

/**
 * Prints a map of any type.
 * @param m the map
 */
template <typename T1, typename T2>
inline void print_map(std::map<T1, T2> m)
{
    std::cout << "map:" << std::endl;
    for (std::pair<T1, T2> elem : m)
    {
        std::cout << elem.first << "-" << elem.second << std::endl;
    }
    std::cout << std::endl;
}
// TODO: it might be good to test overloading << on pairs

// another idea would be to overload << for std::array



/**
 * @brief Prints a vector of int.
 * Written as asked in the wording, print_generic can do it.
 * @param data the vector.
 */
inline void print(const std::vector<int> & data)
{
    std::cout << "vector:" << std::endl;
    for (auto a : data)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

/**
 * Swaps two elements of any type.
 * This function acts the same as std::swap and was only written
 * for an academic purpose.
 * @param a the first element.
 * @param b the second element.
 */
template<class T>
inline void swap(T & a, T & b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/**
 * @brief sorts a vector of int.
 * @param data the vector
 * @param ascending true to sort ascendingly, false to sort descendingly.
 */
inline void sort(std::vector<int> & data, bool ascending)
{
    if (data.empty())
    {
        return;
    }
    bool swapped;

    do
    {
        swapped = false;
        size_t size = data.size();
        for (size_t i = 0; (i + 1) < size; i++)
        {
            if (data[i] != data[i + 1] && (data[i] < data[i + 1]) ^ ascending)
            {
                swap(data[i], data[i + 1]);
                swapped = true;
            }
        }
    }
    while (swapped);
}

}
#endif // ARRAY_UTILITY_H
