#include <iostream>
#include <string>
#include "exo3.h"

using namespace std;

/******************************
*  Class Node (Linked list)  *
******************************/

Node::Node(const int val, Node *next_node) {
    this->val = val;
    this->next_node = next_node;
}

Node::Node(const Node &node) {
    this->val = node.val;
    this->next_node = node.next_node;
}

Node::~Node() {
    delete next_node;
}

int Node::get_val() {
    return val;
}

Node* Node::get_next_node() {
    return next_node;
}

void Node::set_val(const int val) {
    this->val = val;
}

void Node::set_next_node(Node *node) {
    this->next_node = node;
}

int Node::get_size() {
    Node *ptr = this;
    int cpt;
    for (cpt = 1; ptr->get_next_node(); cpt++)
        ptr = ptr->get_next_node();
    return cpt;
}

void Node::push_to(const int val, int place) {
    /* If 'place' is too far, then it's just over the last element. */
    int size = this->get_size();
    if (place < 0 || place > size)
        place = size;
    Node *curr = this;
    /* Push_front : modifying current node. */
    if (place == 0) {
        /* Create the new node with the current node. */
        Node *new_node = new Node(*this);
        /* Set the current node to the new value. */
        curr->set_next_node(new_node);
        curr->set_val(val);
    }
    /* Push_other_place : adding new node after current node. */
    else {
        /* Deplacment in the list on the node before 'place'. */
        for (int i = 0; i < place - 1; i++)
            curr = curr->get_next_node();
        /* Create the new node with the new value. */
        Node *new_node = new Node(val, curr->get_next_node());
        /* Set the current node to the new node. */
        curr->set_next_node(new_node);
    }
}

int Node::get_to(int place) {
    /* If 'place' is too far, then it's just the last element. */
    int size = this->get_size();
    if (place < 0 || place >= size)
        place = size - 1;
    Node *curr = this;
    /* Deplacment in the list on the place-th node. */
    for (int i = 0; i < place; i++)
        curr = curr->get_next_node();
    return curr->get_val();
}

int Node::pop_to(int place) {
    int res = get_to(place);
    /* If 'place' is too far, then it's just the last element. */
    int size = this->get_size();
    if (place < 0 || place >= size)
        place = size - 1;
    Node *curr = this, *prec = nullptr;
    /* Pop_front : modifying current node. */
    if (place == 0) {
        /* Set the old node with the next node of current node. */
        Node *old = curr->get_next_node();
        /* If old_node exists, else, the list is size 1. */
        if (old) {
            /* Set the current node to the next node value. */
            curr->set_next_node(old->get_next_node());
            curr->set_val(old->get_val());
            /* Delete the old node. */
            old->set_next_node(nullptr);
            delete old;
        }
        else
            this->set_val(0);
    }
    /* Pop_other_place : deleting the current node. */
    else {
        /* Deplacment in the list on the place-th node. */
        for (int i = 0; i < place; i++) {
            prec = this;
            curr = prec->get_next_node();
        }
        prec->set_next_node(nullptr);
        curr->set_next_node(nullptr);
        delete curr;
    }
    return res;
}

void Node::display() {
    std::cout << to_string() << std::endl;
} 

std::string Node::to_string() {
    Node *ptr = this;
    std::string str = "";
    char strtmp[12];
    for (; ptr; ptr = ptr->get_next_node()) {
        sprintf(strtmp, "%d ", ptr->get_val());
        str += strtmp;
    }
    return str;
}

/******************************
*  Class CPile (Stack)       *
******************************/

CPile::CPile(const int val, CPile *next_node) : Node(val, next_node) {
}

CPile::~CPile() {
}

int CPile::pop() {
    return pop_to(0);
}

int CPile::get() {
    return get_to(0);
}

void CPile::push(const int val) {
    push_to(val, 0);
}

void CPile::operator<(const int i) {
    push(i);
}

int CPile::operator>(const CPile &stack) {
    return get();
}

std::ostream& operator<<(std::ostream &output, CPile &stack) {
    return output << stack.to_string();
}

/**********
*  Main  *
**********/

int main(int argc, char* argv[])
{
    CPile pile;
    pile < 0;
    pile < 1; // Empiler deux valeurs dans la pile
    std::cout << pile << std::endl;
    int i = 0;
    pile > i; // Récupérer une valeur de la pile dans i
    std::cout << pile << "i = " << i << std::endl;

    /* Même principe avec une file, sauf qu'on ajout au début et récupère à la
     * fin). */
    return 0;
}
