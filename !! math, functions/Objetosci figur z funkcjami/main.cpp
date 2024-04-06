#include <iostream>

using namespace std;

float prostopadloscianV (float a, float b, float c)
{
    return a*b*c;
}

float kulaV (float PI, float r)
{
    return (4*PI*r*r*r)/3;
}

float stozekV (float PI, float r, float h)
{
    return (PI*r*r*h)/3;
}

float walecV (float PI, float r, float h)
{
    return PI*r*r*h;
}

    int odpowiedz;
    float V, r, h, a, b, c, PI;

int main()
{
        PI=3.1415;

    cout << "Wybierz figure geometryczna, ktorej objetosc chcesz obliczyc (wpisz odpowiednia cyfre):\n1. Prostopadloscian\n2. Kula\n3. Stozek\n4. Walec\nOdpowiedz: ";
    cin>>odpowiedz;

    cout<<"\n";

    if (odpowiedz==1)
    {
        cout<<"Podaj dlugosc a prostopadloscianu: ";
        cin>>a;
        cout<<"Podaj dlugosc b prostopadloscianu: ";
        cin>>b;
        cout<<"Podaj dlugosc c prostopadloscianu: ";
        cin>>c;

        cout<<"\nObjetosc prostopadloscianu o boku a dlugosci = "<<a<<" boku b dlugosci = "<<b<<" boku c dlugosci = "<<c<<" wynosi: " <<prostopadloscianV(a, b, c);
    }

    if (odpowiedz==2)
    {
        cout<<"Podaj promien r kuli: ";
        cin>>r;

        cout<<"\nObjetosc kuli o promieniu = "<<r<<" wynosi: "<<kulaV(PI, r);
    }

    if (odpowiedz==3)
    {
        cout<<"Podaj promien r stozka: ";
        cin>>r;
        cout<<"Podaj wysokosc h stozka: ";
        cin>>h;

        cout<<"\nObjetosc stozka o promieniu = "<<r<<" i wysokosci = "<<h<<" wynosi: "<<stozekV(PI, r, h);
    }

    if(odpowiedz==4)
    {
        cout<<"Podaj promien r walca: ";
        cin>>r;
        cout<<"Podaj wysokosc h walca: ";
        cin>>h;

        cout<<"\nObjetosc walca o promieniu = "<<r<<" i wysokosci = "<<h<<" wynosi: "<<walecV(PI, r, h);
    }

    cout<<"\n\n";

    return 0;
}
