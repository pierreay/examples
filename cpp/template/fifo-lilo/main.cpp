#include <iostream>
#include "CList.hpp"
#include "CFile.hpp"
#include "CPile.hpp"

int main(int argc, const char * argv[]) {
    CPile<int> pile;
    CFile<char> file;

    CList<char>* ptList1 = &file; // test sur les files
    char c;
    *ptList1 < 'a' < 'b' < 'c'; // ajouter des eléments
    cout << *ptList1;  // afficher le contenu
    cout << " 2e elt liste : " << (*ptList1)[2] << endl;
    //    cout << " 4e elt liste : " << (*ptList)[4] << endl;

    *ptList1 > c;
    cout << " file out 1 : " << c << endl;
    *ptList1 > c;
    cout << " file out 2 : " << c << endl;
    
    CList<int>* ptList2 = &pile; // test sur les piles
    int i;
    *ptList2 < 1 < 2 < 3;
    cout << *ptList2;
    (*ptList2)[2] = 200;
    cout << *ptList2;
    *ptList2 > i;
    cout << " pile out 1: " << i << endl;
    *ptList2 > i;
    cout << " pile out 2: " << i << endl;
    *ptList2 > i;
    cout << " pile out 3: " << i << endl;
    cout << *ptList2;
   //  *ptList2 > i;  // test de la pile vide
 
    cout << "test sur les chaines" << endl;
    CPile<string> pile_chaine;
    CList<string>* ptList3 = &pile_chaine; // test sur les piles
    string chaine;
    *ptList3 < "hello" < "world" < "!..";
    cout << *ptList3;
    (*ptList3)[2] = "planet";
    cout << *ptList3;
    *ptList3 > chaine;
    cout << " pile out 1: " << chaine << endl;
    *ptList3 > chaine;
    cout << " pile out 2: " << chaine << endl;
    *ptList3 > chaine;
    cout << " pile out 3: " << chaine << endl;
    cout << *ptList3;
    
    return 0;
}
