#include <iostream>

using namespace std;

int main()
{
    bool koniec = false;
    int i=1;
    int liczba[2];

    cout<<"1. skladnik sumy: ";
    cin>>liczba[1];
    int suma = liczba[1];

    while (koniec == false)
    {
        cout<<i+1<<". skladnik sumy: ";
        cin>>liczba[0];

        suma += liczba[0];

        if (liczba[0] == liczba[1]) koniec = true;
        else
        {
            liczba[1]=liczba[0];
        }

        i++;
    }

    cout<<"Suma wynosi: "<<suma;

    return 0;
}
