#include <iostream>

using namespace std;

float a, b, wynik;
int dzialanie;

int main()
{
    cout << "Wpisz liczbe a: ";
    cin>>a;
    cout<<"\nWpisz liczbe b: ";
    cin>>b;
    cout<<"\n\nJesli chcesz uzyskac sume tych dwoch liczb wpisz: 1";
    cout<<"\nJesli chcesz uzyskac roznice tych dwoch liczb wpisz: 2";
    cout<<"\nJesli chcesz uzyskac iloczyn tych dwoch liczb wpisz: 3";
    cout<<"\nJesli chcesz uzyskac iloraz tych dwoch liczb wpisz: 4";
    cout<<"\nOdpowiedz: ";
    cin>>dzialanie;

    if (dzialanie==1) wynik=a+b;
    if (dzialanie==2) wynik=a-b;
    if (dzialanie==3) wynik=a*b;
    if (dzialanie==4) wynik=a/b;

    cout<<"\n\nWynik tego dzialania wynosi: " <<wynik;

    return 0;
}
