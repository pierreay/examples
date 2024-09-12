#include <string>

class Node
{
    public:
        /* Constructeurs et destructeurs. */
        Node(const int val = 0, Node *next_node = nullptr);
        Node(const Node &node);
        ~Node();
        /* Gestion de la liste. */
        int get_size();
        void display();
        std::string to_string();

    private:
        /* Pointeur vers le noeud suivant. */
        Node *next_node;
        /* Valeur du noeud. */
        int val;
        /* Gestion du noeud. */
        int get_val();
        Node* get_next_node();
        void set_val(const int val);
        void set_next_node(Node *node);

    protected:
        /* Gestion de la liste. */
        void push_to(const int val, int place);
        int get_to(int place);
        int pop_to(int place);
};

class CPile : public Node
{
    public:
        CPile(const int val = 0, CPile *next_node = nullptr);
        ~CPile();
        int pop();
        int get();
        void push(const int val);
        void operator<(const int i);
        int operator>(const CPile &stack);
        friend std::ostream& operator<<(std::ostream &output, CPile &stack);
    private:
};
