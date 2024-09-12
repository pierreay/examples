#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "exo7.h"

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

/******************
*  Main Program  *
******************/

int main(int argc, char* argv[])
{
    Definition homer("Homer", "Buveur de biere");
    std::cout << "La définition du mot " << homer.getClef() << " est " << homer.getDef() << std::endl;
    return 0;
}
