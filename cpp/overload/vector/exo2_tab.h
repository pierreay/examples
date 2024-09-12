#include <string>

class Vecteur
{
    public:
        Vecteur(const int size = 10);
        Vecteur(const Vecteur& vec);
        ~Vecteur();
        void copy(const int tab[], const int size);
        std::string to_string();
        void add(const int x, const int ind);
        int get_int(const int i);
        void operator=(const Vecteur& vec);
        int operator[](const int i);
        void operator+=(const int i);
        friend std::ostream& operator<<(std::ostream &output, const Vecteur& vec);

    private:
        /** Tableau dynamique stockant les entiers. */
        int* tab;
        /** Taille du tableau dynamique. */
        int tab_size;
};
