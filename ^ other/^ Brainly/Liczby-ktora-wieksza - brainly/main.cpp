#include <iostream>

using namespace std;

int main()
{
    int const ilosc_liczb=4;
    float liczby[ilosc_liczb];
    int najwieksza, najmniejsza;

    for (int i=0; i<ilosc_liczb; i++)
    {
        cout<<i+1<<". liczba: ";
        cin>>liczby[i];
    }

    najwieksza = 0;
    najmniejsza = 0;
    for (int i=1; i<ilosc_liczb; i++)
    {
        if (liczby[i] > liczby[i-1]) najwieksza = i;
        if (liczby[i] < liczby[i-1]) najmniejsza = i;
    }

    cout<<endl<<"Liczba najmniejsza to: "<<liczby[najmniejsza]<<endl;
    cout<<"Liczba najwieksza to: "<<liczby[najwieksza];

    return 0;
}
