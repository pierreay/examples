#include <iostream>
#include <cmath>
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
        cout << "Appel au destructeur de Point" << endl;
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

    int getx() {
        return this->x;
    }

    int gety() {
        return this->y;
    }

    private:

    int x;
    int y;
};

class Segment {

    public:

    Segment() {
        return;
    }

    Segment(int p1x, int p1y, int p2x, int p2y) {
        this->p1 = Point(p1x, p1y);
        this->p2 = Point(p2x, p2y);
    }

    Segment(const Point& p1, const Point& p2) {
        this->p1.cloner(p1);
        this->p2.cloner(p2);
    }

    Segment(const Segment& seg) {
        this->p1 = seg.p1;
        this->p2 = seg.p2;
    }

    ~Segment() {
        cout << "Appel au destructeur de Segment" << endl;
    }

    void afficher() {
        this->p1.afficher();
        this->p2.afficher();
    }

    int longueur() {
        return abs((p1.getx() - p2.getx()) + (p1.gety() - p2.gety()));
    }

    bool estVertical() {
        if (p1.getx() == p2.getx())
            return true;
        else
            return false;
    }

    bool estHorizontal() {
        if (p1.gety() == p2.gety())
            return true;
        else
            return false;
    }

    bool estSurDiagonale() {
        if (!(this->estHorizontal()) && !(this->estVertical()))
            return true;
        else
            return false;
    }

    private:
    
    Point p1;
    Point p2;
};

int main(int argc, char* argv[])
{
    Segment seg1;
    seg1.afficher();
    cout << "Longueur : " << seg1.longueur() << endl;

    Segment seg2(100, 200, 100, 400);
    seg2.afficher();
    cout << "Longueur : " << seg2.longueur() << endl;
    if (seg2.estVertical())
        cout << "Vertical : oui" << endl;
    if (!(seg2.estSurDiagonale()))
        cout << "Diagonale : non" << endl;

    Point p1(555, 666), p2(444, 333);
    Segment seg3(p1, p2);
    seg3.afficher();
    cout << "Longueur : " << seg3.longueur() << endl;
    if (!(seg3.estVertical()))
        cout << "Vertical : non" << endl;
    if (seg3.estSurDiagonale())
        cout << "Diagonale : oui" << endl;

    return 0;
}
