#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include "exo3.h"

/*********************
*  CString Classes  *
*********************/

CString::CString(char* str) {
    this->size = strlen(str);
    this->str = (char*) malloc(this->size + 1);
    //this->str = new char[this->size + 1];
    strcpy(this->str, str);
    nb_string++;
}

CString::CString(char c) {
    this->size = 1;
    this->str = (char*) malloc(this->size + 1);
    //this->str = new char[this->size + 1];
    str[0] = c, str[1] = '\0';
    nb_string++;
}

CString::CString() {
    this->size = 0;
    this->str = (char*) malloc(1);
    //this->str = new char;
    str[0] = '\0';
    nb_string++;
}

CString::~CString() {
    free(this->str);
    //size > 0 ? delete[] str : delete str;
    nb_string--;
}

int CString::nb_string = 0;

int CString::nbrChaines() {
    return nb_string;
}

char* CString::getString() {
    return this->str;
}

CString CString::plus(char c) {
    size++;
    str = (char*) realloc(str, size + 1);
    str[size - 1] = c;
    CString new_str(str);
    return new_str;
}

bool CString::plusGrandQue(const CString& cstr) {
    return strcmp(this->str, cstr.str) ? true : false;
}

bool CString::infOuEgal(const CString& cstr) {
    return strcmp(this->str, cstr.str) ? false : true;
}

void CString::operator=(const CString& cstr) {
    size = cstr.size;
    str = (char*) realloc(str, size + 1);
    strcpy(str, cstr.str);
}

/************************
*  Definition Classes  *
************************/

Definition::Definition(char* key, char* def) {
    this->key = new CString(key);
    this->def = new CString(def);
}

Definition::~Definition() {
    delete key;
    delete def;
}

char* Definition::getClef() {
    return key->getString();
}

char* Definition::getDef() {
    return def->getString();
}

bool Definition::operator<(const Definition& def) {
    return *(this->key->getString()) < *(def.key->getString());
}

/**************************
*  Dictionnaire Classes  *
**************************/

Dictionnaire::Dictionnaire() {
}

Dictionnaire::~Dictionnaire() {
}

void Dictionnaire::addDefinition(Definition *def) {
    def_list.push_back(def);
    def_list.sort();
}

Definition* Dictionnaire::getDefinition(int i) {
    if (i >= (int) def_list.size()) {
        fprintf(stderr, "invalid get definition\n");
        return NULL;
    }
    std::list<Definition*>::iterator it = def_list.begin();
    std::advance(it, i);
    return *it;
}

Definition* Dictionnaire::searchDefinition(char *str) {
    std::list<Definition*>::iterator it = def_list.begin();
    for (; it != def_list.end(); it++) {
        if (strcasestr((*it)->getDef(), str))
            return *it;
    }
    return NULL;
}

std::string Dictionnaire::toString() {
    std::string str = "Listing du dictionnaire :\n";
    std::list<Definition*>::iterator it = def_list.begin();
    for (; it != def_list.end(); it++) {
        str.append("Mot : ");
        str.append((*it)->getClef());
        str.append("\n");
        str.append("Définition : ");
        str.append((*it)->getDef());
        str.append("\n");
    }
    return str;
}

/******************
*  Main Program  *
******************/

int main(int argc, char* argv[])
{
    Definition *homer = new Definition("Homer", "Buveur de biere");
    std::cout << "La définition du mot " << homer->getClef() << " est " << homer->getDef() << std::endl;
    Definition *test = new Definition("Test", "Test Def");
    std::cout << "La définition du mot " << test->getClef() << " est " << test->getDef() << std::endl;

    Dictionnaire dic;
    dic.addDefinition(test);
    dic.addDefinition(homer);

    Definition *def_ptr = dic.getDefinition(0);
    if (def_ptr != NULL)
        std::cout << "La définition du mot " << def_ptr->getClef() << " est " << def_ptr->getDef() << std::endl;

    def_ptr = dic.searchDefinition("test");
    if (def_ptr != NULL)
        std::cout << "La définition du mot " << def_ptr->getClef() << " est " << def_ptr->getDef() << std::endl;

    std::cout << dic.toString() << std::endl;

    delete homer;
    delete test;

    return 0;
}
