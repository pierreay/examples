#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "exo1.h"

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

CString CString::plus(const char c) {
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

CString CString::operator+(const char c) {
    return this->plus(c);
}

bool CString::operator>(const CString& cstr) {
    return this->plusGrandQue(cstr);
}

bool CString::operator<=(const CString& cstr) {
    return this->infOuEgal(cstr);
}

int main(int argc, char* argv[])
{
    CString s1("toto"), s2('q'), s3;
    std::cout << "Nombre de chaîne : " << CString::nbrChaines() << std::endl;
    std::cout << "s2 = " << s2.getString() << std::endl;

    std::cout << "s1 = " << s1.getString() << std::endl;
    std::cout << "s3 = " << s3.getString() << std::endl;
    //s3 = s1.plus('w');
    s3 = s1 + 'w';
    std::cout << "s1 = " << s1.getString() << std::endl;
    std::cout << "s3 = " << s3.getString() << std::endl;

    //if (s1.plusGrandQue(s2))
    if (s1 > s2)
        std::cout << "s1 plus grand que s2" << std::endl ;

    //if (s1.infOuEgal(s2))
    if (s1 <= s2)
        std::cout << "s1 plus petit que s2" << std::endl ;

    return 0;
}
