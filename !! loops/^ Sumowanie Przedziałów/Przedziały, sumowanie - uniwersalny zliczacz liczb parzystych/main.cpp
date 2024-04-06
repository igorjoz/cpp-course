/*
Przedzialy i sumowanie
*/

#include <iostream>

using namespace std;

int i, suma, liczba, a, b, c;

int main()
{
    cout<<"Podaj liczby. Tylko liczby parzyste z podanych zostana zsumowane.\nLiczby: ";
    cin>>a;
    cin>>b;
{
    if (a%2==0 && b%2==0) suma=a+b;
    if (a%2!=0 && b%2!=0) suma=0;
    if (a%2==0 && b%2!=0) suma=a;
    if (a%2!=0 && b%2==0) suma=b;
}
cout<<"Suma liczb parzystych wynosi: " <<suma;

    return 0;
}
