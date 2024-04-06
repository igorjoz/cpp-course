#include <iostream>
#include "friends.h"

using namespace std;

Point::Point(string n, float xx, float yy)
{
    nazwa = n;
    x=xx;
    y=yy;
}

void Point::wczytaj()
{
    cout<<"Podaj x: ";
    cin>>x;
    cout<<"Podaj y: ";
    cin>>y;

    cout<<"Nazwa punktu: ";
    cin>>nazwa;
}

Rectangle::Rectangle(string n, float xx, float yy, float s, float w)
{
    nazwa = n;
    x=xx;
    y=yy;
    szerokosc=s;
    wysokosc=w;
}

void Rectangle::wczytaj()
{
    cout<<"Podaj x lewego dolnego naroznika: ";
    cin>>x;
    cout<<"Podaj y lewego dolnego naroznika: ";
    cin>>y;

    cout<<"Podaj szerokosc: ";
    cin>>szerokosc;
    cout<<"Podaj wysokosc: ";
    cin>>wysokosc;

    cout<<"Podaj nazwe prostokata: ";
    cin>>nazwa;
}
