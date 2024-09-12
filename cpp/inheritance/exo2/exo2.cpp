#include <iostream>
#include "exo2.h"

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

Point Point::operator=(const Point& p) {
    this->cloner(p);
    return *this;
}

void Point::set_x(int x) {
    this->x = x;
}

int Point::get_x() {
    return this->x;
}

void Point::set_y(int y) {
    this->y = y;
}

int Point::get_y() {
    return this->y;
}

/***********
*  Forme  *
***********/

Forme::Forme() {
    std::cout << "Construction of class Forme" << std::endl;
}

Forme::~Forme() {
    std::cout << "Destruction of class Forme" << std::endl;
}

/*************
*  Segment  *
*************/

Segment::Segment() {
    std::cout << "Construction of class Segment" << std::endl;
    p1 = Point(10, 10);
    p2 = Point(10, 20);
}

Segment::Segment(Point p1, Point p2) {
    std::cout << "Construction of class Segment" << std::endl;
    this->p1 = p1;
    this->p2 = p2;
}

Segment::~Segment() {
    std::cout << "Destruction of class Segment" << std::endl;
}

void Segment::display() {
    std::cout << "Segment :\n";
    p1.afficher();
    p2.afficher();
}

void Segment::move(int x, int y) {
    p1.set_x(p1.get_x() + x);
    p1.set_y(p1.get_y() + y);
    p2.set_x(p2.get_x() + x);
    p2.set_y(p2.get_y() + y);
}

/**************
*  Triangle  *
**************/

Triangle::Triangle() {
    p1 = Point(10, 10);
    p2 = Point(20, 30);
    p3 = Point(30, 50);
}

Triangle::Triangle(Point p1, Point p2, Point p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Triangle::~Triangle() {
    std::cout << "Destruction of class Triangle" << std::endl;
}

void Triangle::display() {
    std::cout << "Triangle :\n";
    p1.afficher();
    p2.afficher();
    p3.afficher();
}

void Triangle::move(int x, int y) {
    p1.set_x(p1.get_x() + x);
    p1.set_y(p1.get_y() + y);
    p2.set_x(p2.get_x() + x);
    p2.set_y(p2.get_y() + y);
    p3.set_x(p3.get_x() + x);
    p3.set_y(p3.get_y() + y);
}

/**********
*  Main  *
**********/


int main(int argc, char* argv[])
{
    //Segment S1;
    //S1.display();
    //S1.move(10, 20);
    //S1.display();
    //Point p1 = Point(200, 210);
    //Point p2 = Point(300, 310);
    //Segment S2 = Segment(p1, p2);
    //S2.display();

    Triangle S1;
    S1.display();
    S1.move(10, 20);
    S1.display();
    Point p1 = Point(200, 210);
    Point p2 = Point(300, 310);
    Point p3 = Point(250, 260);
    Triangle S2 = Triangle(p1, p2, p3);
    S2.display();

    return 0;
}
