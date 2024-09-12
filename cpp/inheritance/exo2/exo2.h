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
        Point operator=(const Point& p);
        void set_x(int x);
        int get_x();
        void set_y(int y);
        int get_y();

    protected:
        int x;
        int y;
};

/***********
*  Forme  *
***********/

class Forme
{
    public:
        Forme();
        ~Forme();
        virtual void display() = 0;
        virtual void move(int x, int y) = 0;
};

/*************
*  Segment  *
*************/

class Segment : public Forme
{
    public:
        Segment();
        Segment(Point p1, Point p2);
        ~Segment();
        virtual void display();
        virtual void move(int x, int y);

    protected:
        Point p1;
        Point p2;
};

/**************
*  Triangle  *
**************/

class Triangle : public Forme
{
    public:
        Triangle();
        Triangle(Point p1, Point p2, Point p3);
        ~Triangle();
        virtual void display();
        virtual void move(int x, int y);
    protected:
        Point p1;
        Point p2;
        Point p3;
};
