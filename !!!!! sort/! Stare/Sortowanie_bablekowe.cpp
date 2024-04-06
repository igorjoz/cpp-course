#include <iostream>

using namespace std;

int ilosc, ilosc_kopia;

int main()
{
    cout<<"Podaj ilosc liczb w tablicy: ";
    cin>>ilosc;

    ilosc_kopia=ilosc;

    cout<<endl;

    int liczby[ilosc];

    for (int i=0; i<ilosc; i++)
    {
        cout<<i<<" miejsce w tablicy: ";
        cin>>liczby[i];
    }

    for (int i=0; i<ilosc; i++)
    {
        for (int k=0; k<ilosc_kopia; k++)
        {
            if (liczby[k]>liczby[k+1])
            {
                int bufor=liczby[k+1];

                liczby[k+1]=liczby[k];
                liczby[k]=bufor;

                //ilosc_kopia-=1;
            }
        }
    }

    cout<<endl<<endl;

    // Wypisanie posortowanej tablicy
    for (int i=0; i<ilosc; i++)
    {
        cout<<liczby[i]<<endl;
    }

    cout<<endl<<endl;
    return 0;
}
