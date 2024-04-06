#include <iostream>

using namespace std;

class Rectangle;

class Point
{
    string nazwa;
    float x, y;

public:
    Point(string="A", float=0, float=0);
    void wczytaj();

    friend void judge(Point pkt, Rectangle p);
};

class Rectangle
{
    string nazwa;
    float x, y, szerokosc, wysokosc;

public:
    Rectangle(string="brak", float=0, float=0, float=1, float=1);
    void wczytaj();

    friend void judge(Point pkt, Rectangle p);
};
