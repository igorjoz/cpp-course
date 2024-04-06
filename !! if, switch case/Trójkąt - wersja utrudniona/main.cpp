/*
Program sprawdzajacy czy stworzenie trojkata o podanych bokach jest mozliwe
WERSJA 2
*/

#include <iostream>

using namespace std;

int a, b, c;

int main()
{
    cout << "Podaj dlugosc pierwszego boku: ";
    cin>>a;
    cout << "\nPodaj dlugosc drugiego boku: ";
    cin>>b;
    cout<<"\nPodaj dlugosc trzeciego boku: ";
    cin>>c;
    if (a+b>c)
    {
    cout<<"\nStworzenie takiego trojkata jest mozliwe\n";
    }
    if (b+c>a)
    {
    cout<<"\nStworzenie takiego trojkata jest mozliwe\n";
    }
    if (a+c>b)
    {
    cout<<"\nStworzenie takiego trojkata jest mozliwe\n";
    }
    else cout<<"Stworzenie takiego trojkata nie jest mozliwe";

    return 0;
}
