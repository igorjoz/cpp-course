#include <iostream>

using namespace std;
int a, b, c, d, sumakatow;

int main()
{

    cout << "Witaj w programie, ktory odpowie Ci o jakiej figurze geometrycznej myslisz\nTa wersja programu rozpoznaje: kwadrat, prostokat, trojkat i kolo.\n\n";
    cout<<"Podaj dlugosc bokow.\nJesli dlugosc bokow nie dotyczy figury, o ktorej myslisz,\npodaj w pierwszej rubryce promien okregu, a w reszcie zera\n";

    cout<<"\nDlugosc pierwszego boku (lub promien okregu): ";
    cin>>a;

    cout<<"\nDlugosc drugiego boku: ";
    cin>>b;

    cout<<"\nDlugosc trzeciego boku: ";
    cin>>c;

    cout<<"\nDlugosc czwartego boku: ";
    cin>>d;

    cout<<endl;

{
        if (a==b && a==c && a==d) cout<<"Figura, o ktorej myslisz to kwadrat\n";
    else
        if (/*a!=b || a!=c || a!=d && */b!=0 && c!=0 && d!=0) cout<<"Figura, o ktorej myslisz to prostokat\n";
    else
        if (b==0 && c==0 && d==0) cout<<"Figura o ktorej myslisz to kolo\n";
}
    return 0;
}
