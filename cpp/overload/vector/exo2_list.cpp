#include <iostream>
#include <string>
#include "exo2_list.h"

using namespace std;

/*******************
*  Class Vecteur  *
*******************/

Vecteur::Vecteur(const int size) {
    list = new Node();
    Node *tmp = list, *tmp_pred;
    for (int i = 0; i < size ; i++) {
        tmp_pred = tmp;
        tmp = new Node();
        tmp_pred->set_next_node(tmp);
    }
    list_size = size;
}

Vecteur::Vecteur(const Vecteur& vec) : Vecteur(vec.list_size) {
    this->copy(vec.list, vec.list_size);
}

Vecteur::~Vecteur() {
    delete list;
}

void Vecteur::copy(Node *node, const int size) {
    for (int i = 0; i <= size; i++) {
        this->add(node->get_val(), i);
        node = node->get_next_node();
    }
}

string Vecteur::to_string() {
    string str;
    char str_tmp[12];
    Node *tmp = list;
    for (int i = 0; i <= list_size; i++) {
        sprintf(str_tmp, "%d", tmp->get_val());
        str += str_tmp;
        str += ", ";
        tmp = tmp->get_next_node();
    }
    return str;
}

void Vecteur::add(const int x, const int ind) {
    Node *tmp = list, *tmp_pred = nullptr;
    if (list_size > ind) {
        for (int i = 0; i < ind; i++)
            tmp = tmp->get_next_node();
    }
    else {
        for (int i = 0; i < list_size; i++)
            tmp = tmp->get_next_node();
        for (int i = 0; i < ind - list_size ; i++) {
            tmp_pred = tmp;
            tmp = new Node();
            tmp_pred->set_next_node(tmp);
        }
        list_size = ind;
    }
    tmp->set_val(x);
}

int Vecteur::get_int(const int ind) {
    Node *node = list;
    for (int i = 0; i < ind; i++)
        node = node->get_next_node();
    return node->get_val();
}

void Vecteur::operator=(const Vecteur& vec) {
    this->copy(vec.list, vec.list_size);
    list_size = vec.list_size;
}

int Vecteur::operator[](const int i) {
    return this->get_int(i);
}

void Vecteur::operator+=(const int i) {
    this->add(i, list_size + 1);
}

ostream& operator<<(ostream &output, Vecteur& vec) {
    return output << vec.to_string();
}

/******************************
*  Class Node (Linked list)  *
******************************/

Node::Node(const int val, Node *next_node) {
    this->val = val;
    this->next_node = next_node;
}

Node::~Node() {
    if (next_node != nullptr)
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

/**********
*  Main  *
**********/


int main(int argc, char* argv[])
{
    Vecteur vec1;
    Vecteur vec2(20);

    vec1.add(1, 0);
    vec1.add(2, 1);
    cout << "Vecteur 1 : " << vec1.to_string() << endl;

    vec2.add(1, 0);
    vec2.add(2, 9);
    cout << "Vecteur 2 : " << vec2.to_string() << endl;

    Vecteur vec3(vec2);
    cout << "Vecteur 3 : " << vec3.to_string() << endl;

    vec1.add(3, 14);
    vec1.add(4, 27);
    cout << "Vecteur 1 : " << vec1.to_string() << endl;

    vec2 = vec1;
    cout << "Vecteur 2 : " << vec2.to_string() << endl;
    cout << "Vecteur 2 indice 2 : " << vec2[1] << endl;

    vec1 += 3;
    cout << "Vecteur 1 : " << vec1.to_string() << endl;
    return 0;
}
