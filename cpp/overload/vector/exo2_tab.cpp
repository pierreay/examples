#include <iostream>
#include <string>
#include "exo2_tab.h"

using namespace std;

Vecteur::Vecteur(const int size) {
    tab = new int[size];
    tab_size = size;
    for (int i = 0; i < tab_size; i++) {
        tab[i] = 0;
    }
}

Vecteur::Vecteur(const Vecteur& vec) : Vecteur(vec.tab_size) {
    this->copy(vec.tab, vec.tab_size);
}

Vecteur::~Vecteur() {
    delete[] tab;
}

void Vecteur::copy(const int tab[], const int size) {
    for (int i = 0; i < size; i++)
        this->tab[i] = tab[i];
}

string Vecteur::to_string() {
    string str;
    char str_tmp[12];
    for (int i = 0; i < tab_size; i++) {
        sprintf(str_tmp, "%d", tab[i]);
        str += str_tmp;
        str += ", ";
    }
    str.erase((tab_size * 3) - 2, 2);
    return str;
}

void Vecteur::add(const int x, const int ind) {
    if (tab_size <= ind) {
        int tab_size_new = ind * 2;
        int *tab_new = new int[tab_size_new];
        for (int i = 0; i < tab_size; i++)
            tab_new[i] = tab[i];
        for (int i = tab_size; i < tab_size_new; i++)
            tab_new[i] = 0;
        delete[] tab;
        tab = tab_new;
        tab_size = tab_size_new;
    }
    tab[ind] = x;
}

int Vecteur::get_int(const int i) {
    return tab[i];
}

void Vecteur::operator=(const Vecteur& vec) {
    this->copy(vec.tab, vec.tab_size);
    tab_size = vec.tab_size;
}

int Vecteur::operator[](const int i) {
    return this->get_int(i);
}

void Vecteur::operator+=(const int i) {
    this->add(i, tab_size);
}

ostream& operator<<(ostream &output, Vecteur& vec) {
    return output << vec.to_string();
}

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

    //vec1.add(3, 14);
    //vec1.add(4, 27);
    //cout << "Vecteur 1 : " << vec1.to_string() << endl;

    vec2 = vec1;
    cout << "Vecteur 2 : " << vec2.to_string() << endl;
    cout << "Vecteur 2 indice 2 : " << vec2[1] << endl;

    vec1 += 3;
    cout << "Vecteur 1 : " << vec1.to_string() << endl;
    return 0;
}
