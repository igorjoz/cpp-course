#include <iostream>

using namespace std;

// ========================================================================

float *liczba;      // Zmienna uzywana w funkcji do pobierania danych oraz do wypisania ich w funkcji main

int ile;    // Zmienna okreslajaca ile liczb chce wprowadzic uzytkownik
int wybor;  // Zmienna uzywana do stworzenia switch case

// ========================================================================

float f_najwieksza (float *liczba, int ile);

float f_najmniejsza (float *liczba, int ile)
{
    float naj=liczba[0];

    for (int i=1; i<ile; i++)
    {
        if ((liczba[i]>=liczba[i-1]) && (liczba[i-1]<naj))
        {
            naj=liczba[i-1];
        }

        else if ((liczba[i]<liczba[i-1]) && (liczba[i]<naj))
        {
            naj=liczba[i];
        }
    }
    return naj;
}

// ========================================================================

void pobranie_liczb (int ile, float *liczba);

void wypisanie_zbioru (float *liczba, int ile);

// ========================================================================
// ========================================================================

int main()
{
    cout<<"Chcesz znalezc najmniejsza czy najwieksza?"<<endl;
    cout<<"1. Najwieksza"<<endl;
    cout<<"2. Najmniejsza"<<endl;
    cout<<"Wybor (1 lub 2): ";
    cin>>wybor;

    cout<<endl<<endl;

// ========================================================================

    cout<<"Ile liczb chcesz wprowadzic? Odpowiedz: ";
    cin>>ile;

    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!! */
    liczba = new float [ile];
    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!! */

// ========================================================================

    pobranie_liczb (ile, liczba);

    switch (wybor)
    {
    case 1:

        wypisanie_zbioru (liczba, ile);

        cout<<endl<<endl<<"To: "<<f_najwieksza(liczba, ile);

        break;

    case 2:
        wypisanie_zbioru (liczba, ile);

        cout<<endl<<endl<<"To: "<<f_najmniejsza (liczba, ile);

        break;
    }

    delete [] liczba;

    cout<<endl<<endl;
    return 0;
}

// ========================================================================
// ========================================================================

float f_najwieksza (float *liczba, int ile)
{
    float naj=liczba[0];

    for (int i=1; i<ile; i++)
    {
        if (liczba[i]>=liczba[i-1])
        {
            naj=liczba[i];
        }

        else if (liczba[i]<liczba[i-1])
        {
            naj=liczba[i-1];
        }
    }
    return naj;
}

// ========================================================================

void pobranie_liczb (int ile, float *liczba)
{
    for (int i=0; i<ile; i++)
    {
        cout<<"Podaj "<<i+1<<". liczbe: ";
        cin>>liczba[i];
    }

}

// ========================================================================

void wypisanie_zbioru (float *liczba, int ile)
{
    if (wybor==1)
    {
        cout<<"Najwieksza liczba ze zbioru: ";
    }

    else if (wybor==2)
    {
        cout<<"Najmniejsza liczba ze zbioru: ";
    }

    for (int i=0; i<ile; i++)
    {
        cout<<liczba[i];

        if (i+1<ile)
            cout<<", ";
    }
}
