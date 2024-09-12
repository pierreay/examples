#include <iostream>
using namespace std;

class Point 
{
    public:

    /* Constructeurs. */

    Point() {
        this->x = 50;
        this->y = 50;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point(const Point& p) {
        this->x = p.x;
        this->y = p.y;
    }

    /* Destructeur. */

    ~Point() {
        cout << "Appel au destructeur" << endl;
    }

    /* Méthodes. */

    void afficher() {
        cout << "x : " << this->x << endl;
        cout << "y : " << this->y << endl;
    }

    void cloner(const Point& p) {
        this->x = p.x;
        this->y = p.y;
    }

    private:

    int x;
    int y;
};

int main(int argc, char* argv[])
{
    Point p1, p2(150, 200);
    p1.afficher();
    p2.afficher();

    Point p3(p2);
    p3.afficher();

    Point p4;
    p4.cloner(p3);
    p4.afficher();

    return 0;
}
