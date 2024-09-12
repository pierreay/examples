#include <iostream>
#include "exo2.h"

int main(int argc, char* argv[])
{
    int i = 5, j = 6;
    float l = 10.0, m = 5.0;
    Pair<int> myInts (i, j);
    Pair<float> myFloats (l, m);
    // Créer une paire d’entiers
    // Créer une paire de flottants
    std::cout << myInts.GetMax() << std::endl; // Affiche le plus grand des 2 entiers
    std::cout << myFloats.GetMax() << std::endl; // Affiche le plus grand des 2 flottants

    char c1 = 'c', c2 = 'd';
    Pair<char> myChars(c1, c2); // Creer un objet qui contient une paire d’entiers
    std::cout << myChars.GetMax() << std::endl;
    return 0;
}
