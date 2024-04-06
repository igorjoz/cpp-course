#include <iostream>

using namespace std;


float V, r, h, a, b, c;
float PI = 3.1415;

float Ostroslup (int a, int b, int c)
{
    V=a*b*c;
    return V;
}

float Walec (int r)
{

}

int main()
{
    int wybor;

    cout<<"Wybierz figure geometryczna, ktorej objetosc chcesz obliczyc (wpisz odpowiednia cyfre):"<<endl;
    cout<<"1. Prostopadloscian"<<endl;
    cout<<"2. Kula"<<endl;
    cout<<"3. Stozek"<<endl;
    cout<<"4. Walec"<<endl
        cout<<"Odpowiedz: ";
    cin>>wybor;

    cout<<endl;

    switch (wybor)
    {
    case 1:
    {
        cout<<"Podaj bok a prostopadloscianu: ";
        cin>>a;
        cout<<"Podaj bok b prostopadloscianu: ";
        cin>>b;
        cout<<"Podaj bok c prostopadloscianu: ";
        cin>>c;

        cout<<endl<<"Objetosc prostopadloscianu o boku a dlugosci = "<<a<<" i boku b dlugosci = "<<b<<" oraz boku c dlugosci = "<<c;
        cout<<" wynosi: " <<V;
    }

    case 2:
    {
        cout<<"Podaj promien r kuli: ";
        cin>>r;

    }

    }

    if (odpowiedz==2)
    {
        V=(4*r*r*r*PI)/3;
        cout<<"\nObjetosc kuli o promieniu = "<<r<<" wynosi: "<<V<<"\n\n";
    }

    if (odpowiedz==3)
    {
        cout<<"\nPodaj promien r stozka: ";
        cin>>r;
        cout<<"Podaj wysokosc h stozka: ";
        cin>>h;

        V=(PI*r*r*h)/3;
        cout<<"\nObjetosc stozka o promieniu = "<<r<<" i wysokosci = "<<h<<" wynosi: "<<V<<"\n\n";
    }

    if(odpowiedz==4)
    {
        cout<<"\nPodaj promien r walca: ";
        cin>>r;
        cout<<"Podaj wysokosc h walca: ";
        cin>>h;

        V=PI*r*r*h;
        cout<<"\nObjetosc walca o promieniu = "<<r<<" i wysokosci = "<<h<<" wynosi: "<<V<<"\n\n";
    }

    cout<<endl<<endl;
    return 0;
}
