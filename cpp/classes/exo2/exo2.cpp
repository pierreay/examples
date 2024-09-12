#include <iostream>
using namespace std;

void echange_ptr(int* d1, int* d2)
{
    int tmp = *d2;
    *d2 = *d1;
    *d1 = tmp;
    return;
}

void echange_ref(int& d1, int& d2)
{
    int tmp = d2;
    d2 = d1;
    d1 = tmp;
    return;
}

int main(int argc, char* argv[])
{
    int int3 = 3;
    int int5 = 5;
    cout << int3 << int5 << endl;
    echange_ptr(&int3, &int5);
    cout << int3 << int5 << endl;
    echange_ref(int3, int5);
    cout << int3 << int5 << endl;
    return 0;
}
