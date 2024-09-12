#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "exo1.h"

template <typename T> T& GetMax(T &var1, T &var2) {
    return var1 > var2 ? var1 : var2;
} 

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
    //return strcmp(this->str, cstr.str) ? true : false;
    return this->size > cstr.size ? true : false;
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
    int i = 5, j = 6, k;
    float l = 10.0, m = 5.0, n;
    k = GetMax(i, j); // Retourne le plus grand entre i et j.
    n = GetMax(l, m); // Retourne le plus grand entre l et m.
    std::cout << k << std::endl;
    std::cout << n << std::endl;

    CString s1("s"), s2("toto"), s3;
    s3 = GetMax(s1, s2); // Retourne le plus grand entre s1 et s2.
    std::cout << s3.getString() << std::endl;
    return 0;
}
