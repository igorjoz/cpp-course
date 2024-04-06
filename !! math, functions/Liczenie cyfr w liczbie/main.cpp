#include <iostream>

using namespace std;

int main()
{
    float liczba;
    int ilosc_dzielen=0;

    cout <<"Program liczacy ilosc cyfr w liczbie."<<endl<<endl;

    cout<<"Podaj liczbe: ";
    cin>>liczba;

    while (liczba>=1)
    {
        ilosc_dzielen++;
        liczba=liczba/10;
    }

    cout<<"Ilosc cyfr w liczbie, ktora podales wynosi: "<<ilosc_dzielen;

    cout<<endl<<endl;
    return 0;
}
