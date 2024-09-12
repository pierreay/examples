#include <iostream>
#include <string>
using namespace std;

#define TAB_SIZE 3

int main()
{
    /* Tableau d'entier. */
    int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int* p = tab;
    for (int i = 0; i < 10; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;

    /* Tableau de chaînes de caractères. */
    string* str[TAB_SIZE] = {0};
    for (int i = 0; i < TAB_SIZE; i++) {
        str[i] = new string;
    }
    *(str[0]) = "truc";
    *(str[1]) = "machin";
    *(str[2]) = "chose";
    for (int i = 0; i < TAB_SIZE; i++) {
        cout << *(str[i]) << endl;
        delete str[i];
    }

    return 0;
}
