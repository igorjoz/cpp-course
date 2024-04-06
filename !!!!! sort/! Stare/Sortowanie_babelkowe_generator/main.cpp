#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int ilosc;

int main()
{
    cout<<"Podaj ilosc liczb do wygenerowania: ";
    cin>>ilosc;

    int liczby[ilosc]; // Tablica

    srand((unsigned)time(NULL)); // Generator

    // Losowanie liczb do tablicy
    for (int i=0; i<ilosc; i++)
    {
        liczby[i]=rand()%101;

        cout<<liczby[i]<<endl; // Wypisanie wylosowanych liczb
    }

    cout<<endl;

    for (int i=0; i<ilosc; i++)
    {
        for (int k=1; k<ilosc-i; k++)
        {
            if (liczby[k-1]>liczby[k])
            {
                int bufor=liczby[k];

                liczby[k]=liczby[k-1];
                liczby[k-1]=bufor;
            }
        }
    }

    cout<<endl<<endl;

    cout<<"Posortowana tablica:"<<endl;
    // Wypisanie posortowanej tablicy
    for (int i=0; i<ilosc; i++)
    {
        cout<<liczby[i]<<endl;
    }

    cout<<endl<<endl;
    return 0;
}
