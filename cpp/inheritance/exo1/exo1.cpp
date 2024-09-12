#include <iostream>
#include "exo1.h"

/***********
*  Point  *
***********/

Point::Point() {
    this->x = 50;
    this->y = 50;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point& p) {
    this->x = p.x;
    this->y = p.y;
}


Point::~Point() {
    std::cout << "Appel au destructeur de Point" << std::endl;
}

void Point::afficher() {
    std::cout << "x : " << this->x << std::endl;
    std::cout << "y : " << this->y << std::endl;
}

void Point::cloner(const Point& p) {
    this->x = p.x;
    this->y = p.y;
}

/****************
*  PointColor  *
****************/

PointColor::PointColor() : Point() {
    couleur = 1;
}

PointColor::PointColor(int x, int y, int coul) : Point(x, y) {
    couleur = coul;
}

PointColor::PointColor(const PointColor& p) {
    x = p.x;
    y = p.y;
    couleur = p.couleur;
}

PointColor::~PointColor() {
    std::cout << "Appel au destructeur de PointColor" << std::endl;
}

void PointColor::afficher() {
    std::cout << "x : " << this->x << std::endl;
    std::cout << "y : " << this->y << std::endl;
    std::cout << "couleur : " << this->couleur << std::endl;
}

void PointColor::cloner(const PointColor& p) {
    x = p.x;
    y = p.y;
    couleur = p.couleur;
}


int main(int argc, char* argv[])
{
    PointColor p1, p2(150, 200, 3);
    p1.afficher();
    p2.afficher();

    PointColor p3(p2);
    p3.afficher();

    PointColor p4;
    p4.cloner(p3);
    p4.afficher();

    return 0;
}
