#include <iostream>

using namespace std;

int a, b, c;

int main()
{
cout<<"Program sprawdzajacy, czy trojkat o danych bokach jest mozliwy do zbudowania";
cout<<"\nWAZNA INFORMACJA: Aby zbudowanie trojkata bylo mozliwe WSZYTSKIE TRZY komunikaty musza mowic, \nze stworzenie danego trojkata jest mozliwe\n\n";

cout<<"Podaj dlugosc pierwszego boku: ";
cin>>a;

cout<<"\nPodaj dlugosc drugiego: ";
cin>>b;

cout<<"\nPodaj trzeciego: ";
cin>>c;

{
{
if ((a>b) && (a>c));
if (b+c>a) cout<<"\n\nStworzenie takiego trojkata JEST mozliwe";
if (b+c<a) cout<<"\n\nStowrzenie takieog trojkate NIE JEST mozliwe";
}

{
if ((b>a) && (b>c));
if (a+c>b) cout<<"\n\nStworzenie takiego trojkata JEST mozliwe";
if (a+c<b) cout<<"\n\nStowrzenie takieog trojkate NIE JEST mozliwe";
}

{
if ((c>a) && (c>b));
if (a+b>c) cout<<"\n\nStworzenie takiego trojkata JEST mozliwe";
if (a+b<c) cout<<"\n\nStowrzenie takiego trojkate NIE JEST mozliwe";
}
}

cout<<"\n\n";
    return 0;
}
