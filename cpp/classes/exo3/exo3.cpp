#include <iostream>
using namespace std;

#define TAB_SIZE 5

void tableauEcriture(int tab[], int tab_size) {
    for (int i = 0; i < tab_size; i++) {
        tab[i] = i;
    }
    return;
}

void tableauLecture(const int tab[], int tab_size) {
    for (int i = 0; i < tab_size ; i++) {
        cout << tab[i] << endl;
    }
    return;
}

int main(int argc, char* argv[])
{
    int tab[TAB_SIZE] = {0};
    tableauEcriture(tab, TAB_SIZE);
    tableauLecture(tab, TAB_SIZE);
    return 0;
}
