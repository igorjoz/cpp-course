#include <iostream>

using namespace std;

int main()
{
    int const ilosc_liczb=3;
    float liczby[ilosc_liczb];

    for (int i=0; i<ilosc_liczb; i++)
    {
        cout<<i+1<<". liczba: ";
        cin>>liczby[i];
    }

    // Sortowanie babelkowe, rosnace
    for (int i=0; i<ilosc_liczb; i++)
    {
        for (int k=1; k<ilosc_liczb; k++)
        {
            if (liczby[k] < liczby[k-1])
            {
                int temp=liczby[k];
                liczby[k]=liczby[k-1];
                liczby[k-1]=temp;
            }
        }
    }

    cout<<endl<<"Posortowane liczby:"<<endl;
    for (int i=0; i<ilosc_liczb; i++)
    {
        cout<<i+1<<".: "<<liczby[i]<<endl;
    }

    return 0;
}
