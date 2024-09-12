#ifndef CList_hpp
#define CList_hpp

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cxxabi.h>
using namespace std;

template<typename T>    // recupération du type T dans chaine lisible
string type_name(){
    int status;
    string tname = typeid(T).name();
    char *demangled_name = abi::__cxa_demangle(tname.c_str(), NULL, NULL, &status);
    if(status == 0) {
        tname = demangled_name;
        free(demangled_name);
    }
    return tname;
}

template <typename T>
struct element {
    T value;
    element* next;};

template <typename T>
class CList {
    protected :
    element<T>* elt;
    string generic;
    const char* name;
    public :
    typedef T data_t;
    CList(){
        this->elt=NULL;
        this->generic = type_name<T>();
        this->name=__func__;  // récupère le nom de la classe
    };
    ~CList(){
        if (this->elt != NULL) {
            while (this->elt->next!=NULL) {
                element<T>* tmp = this->elt;
                this->elt = this->elt->next;
                delete tmp;
            };
            delete this->elt;
            this->elt = NULL;
        };
    };
    CList& operator<(T i){
        element<T>* tmp = new element<T>;
        tmp->value=i;
        if (elt==NULL) {elt = tmp; tmp->next=NULL;}
        else {tmp->next=elt; elt=tmp;}
        return *this;
    };
    virtual CList& operator>(T& i){
        cout << "i don't know how to remove an elt" << endl;
        return *this;
    };
    
    T& operator[](int i){
        element<T>* tmp= elt;
        int j = 1;
        while (tmp != NULL && j < i) {
            tmp=tmp->next;
            j++;
        };
        if (tmp == NULL) {
            cout << "index of range " << endl;
            exit(1);
        }
        else return tmp->value;
    };
    
    friend ostream& operator<<(ostream& flux, CList& l){
        flux << l.name << " -- Voici une " << l.name << " de " << l.generic << " : " << endl ;
        if (l.elt == NULL) flux << "empty list" << endl;
        else {
            element<T>* tmp = l.elt;
            while (tmp != NULL) {
                flux << " " << tmp->value ;
                tmp= tmp->next;
            };
            flux << endl;
        };
        return flux;
    };
};
#endif /* CList_hpp */
