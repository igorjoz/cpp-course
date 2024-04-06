/*
Program sprawdzajacy czy stworzenie trojkata o podanych bokach jest mozliwe
*/

#include <iostream>

using namespace std;

int a, b, c;

int main()
{
    cout << "Podaj dlugosc najkrotszego boku: ";
    cin>>a;
    cout << "\nPodaj dlugosc najdluzszego boku: ";
    cin>>c;
    cout << "\nPodaj dlugosc pozostalego boku: ";
    cin>>b;
    if (a+b>=c) (cout<<"\nStworzenie takiego trojkata nie jest mozliwe\n"); //Obliczenie + warunek niemoznoszci zbudowania trojkata
    else (cout<<"\nStworzenie takiego trojkata jest mozliwe\n"); //warunek moznosci zbudowania trojkata

    return 0;
}
