#ifndef CFile_hpp
#define CFile_hpp

#include <stdio.h>
#include "CList.hpp"


template <typename T>
class CFile : public CList<T> {
    public :
    CFile(){ this->name=__func__;};
    ~CFile(){};
    CList<T>& operator>(T& i){
        if (this->elt==NULL) {
            cout << "File vide" << endl;
            exit(1);
        }
        else {
            element<T>* tmp= this->elt->next;
            if (tmp == NULL) { // la file contient 1 seul elt
                i= this->elt->value;
                this->elt=NULL;
                delete tmp;
                return *this;
            }
            else {
                element<T>* aux = tmp;
                while (tmp->next != NULL) {
                    aux=tmp;
                    tmp = tmp->next; };
                i = tmp->value;
                delete aux->next;
                aux->next= NULL;
                return *this;
            };
        };
    };
};
#endif /* CFile_hpp */
