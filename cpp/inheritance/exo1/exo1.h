/***********
*  Point  *
***********/

class Point 
{
    public:
        Point();
        Point(int x, int y);
        Point(const Point& p);
        ~Point();
        void afficher();
        void cloner(const Point& p);

    protected:
        int x;
        int y;
};

/****************
*  PointColor  *
****************/

class PointColor : public Point
{
    public:
        PointColor();
        PointColor(int x, int y, int coul);
        PointColor(const PointColor& p);
        ~PointColor();
        void afficher();
        void cloner(const PointColor& p);
    protected:
        int couleur;
};
