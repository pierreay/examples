#include <string>

class Node
{
    public:
        Node(const int val = 0, Node *next_node = nullptr);
        ~Node();
        int get_val();
        Node* get_next_node();
        void set_val(const int val);
        void set_next_node(Node *node);

    private:
        /** Pointeur vers le noeud suivant. */
        Node *next_node;
        /** Valeur du noeud. */
        int val;
};

class Vecteur
{
    public:
        Vecteur(const int size = 0);
        Vecteur(const Vecteur& vec);
        ~Vecteur();
        void copy(Node *node, const int size);
        std::string to_string();
        void add(const int x, const int ind);
        int get_int(const int ind);
        void operator=(const Vecteur& vec);
        int operator[](const int i);
        void operator+=(const int i);
        friend std::ostream& operator<<(std::ostream &output, const Vecteur& vec);

    private:
        /** Liste chaînée stockant les entiers. */
        Node *list;
        /** Taille de la liste. */
        int list_size;
};
