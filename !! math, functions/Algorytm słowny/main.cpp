#include <iostream>

using namespace std;

float a1, a2, b1, b2, c1, c2, wyznacznikglowny, wyznacznikpomocniczyx, wyznacznikpomocniczyy, x, y;

int main()
{
    cout << "Podaj wspolczynnik a1: ";
    cin>>a1;
    cout<<"\n";

    cout << "Podaj wspolczynnik a1: ";
    cin>>a2;
    cout<<"\n";

    cout << "Podaj wspolczynnik b1: ";
    cin>>b1;
    cout<<"\n";

    cout << "Podaj wspolczynnik b2: ";
    cin>>b2;
    cout<<"\n";

    cout << "Podaj wspolczynnik c1: ";
    cin>>c1;
    cout<<"\n";

    cout << "Podaj wspolczynnik c2: ";
    cin>>c2;
    cout<<"\n\n";

    wyznacznikglowny=a1*b2-b1*a2;
    wyznacznikpomocniczyx=c1*b2-b1*c2;
    wyznacznikpomocniczyy=a1*c2-c1*a2;

    if (wyznacznikglowny!=0)
    {
        cout<<"Wyznacznik glowny jest rozny od zera\n";
        x=wyznacznikpomocniczyx/wyznacznikglowny;
        y=wyznacznikpomocniczyy/wyznacznikglowny;

        cout<<"Wartosc x = "<<x<<"\n";
        cout<<"Wartosc y = "<<y;
    }

    if (wyznacznikglowny==0)
    {
        if (wyznacznikpomocniczyx*wyznacznikpomocniczyx+wyznacznikpomocniczyy*wyznacznikpomocniczyy==0)
    {
        cout<<"Wyznacznik glowny = 0\nWx*Wx+Wy*Wy rowna sie 0\nTen uklad rownan jest tozsamosciowy i posiada nieskonczenie wiele rozwiazan";
    }

    if(wyznacznikpomocniczyx*wyznacznikpomocniczyx+wyznacznikpomocniczyy*wyznacznikpomocniczyy!=0)
    {
        cout<<"Wyznacznik glowny = 0\nWx*Wx+Wy*Wy nie rowna sie 0\nTen uklad rownan jest sprzeczny i nie posada zadnego rozwiazania";
    }
    }

    cout<<"\n\n";

    return 0;
}
