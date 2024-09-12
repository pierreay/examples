#include <iostream>

/**************
*  Template  *
**************/

template<typename T>
class Pair
{
    private:
        T x1;
        T x2;

    public:
        Pair(T x_1, T x_2) {
            x1 = x_1;
            x2 = x_2;
        }
        T GetMax() {
            std::cout << "Ce type n'est pas encore pris en charge." << std::endl;
            return 1;
        }
};

// Version spécialisée pour les float.
template<>
float Pair<float>::GetMax() {
    return x1 > x2 ? x1 : x2;
}

// Version spécialisée pour les int.
template<>
int Pair<int>::GetMax() {
    return x1 > x2 ? x1 : x2;
}

/* Conclusion :
 * Quelle que soit la nature des fonctions template, elles peuvent êtres
 * spécialisées pour faire des traitements spéciaux pour certaines classes. Pour
 * ces classes, ce sont les versions spécialisées qui seront appellées, sinon
 * les versions templates. */
