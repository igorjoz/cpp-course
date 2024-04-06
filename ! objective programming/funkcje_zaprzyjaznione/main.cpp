#include <iostream>
#include "friends.h"

using namespace std;

void judge(Point pkt, Rectangle p)
{
    cout<<endl;

    if ((pkt.x >= p.x) && (pkt.x <= p.x + p.szerokosc) && (pkt.y >= p.y) && (pkt.y <= p.y + p.wysokosc))
    {
        cout<<"Punkt "<<pkt.nazwa<<" nalezy do prostokata "<<p.nazwa;
    }
    else
    {
        cout<<"Punkt "<<pkt.nazwa<<" NIE nalezy do prostokata "<<p.nazwa;
    }
}

int main()
{
    Point pkt1("A",3,1);
    //pkt1.wczytaj();

    Rectangle p1("Prostokat",3,1,6,4);
    //p1.wczytaj();

    judge(pkt1, p1);

    return 0;
}
