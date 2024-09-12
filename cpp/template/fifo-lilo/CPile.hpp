#ifndef CPile_hpp
#define CPile_hpp

#include <stdio.h>
#include "CList.hpp"


template <typename T>
class CPile : public CList<T> {
    public :
    CPile(){ this->name=__func__;};
    ~CPile() {};
    CList<T>& operator>(T& i){
        if (this->elt==NULL) {
            cout << "Pile vide" << endl;
            exit(1);
        }
        else {
            element<T>* tmp= this->elt->next;
            i = this->elt->value;
            this->elt= this->elt->next;
            delete tmp;
            return *this;
        };
    };
};
#endif /* CPile_hpp */
