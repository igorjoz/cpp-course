#include <iostream>
#include <time.h>
#include <cstdlib>
#include <studio.h>

int wylosowana_liczba, liczba_uzytkownika, liczba_prob=0;

using namespace std;

int main()
{
    cout<<"Gra w zgadywanie liczby.\nPomyslalem sobie liczbe z przedzialu od 1 do 100";
    srand(time(NULL));
    wylosowana_liczba=rand()%100+1;

    while(wylosowana_liczba!=liczba_uzytkownika)
    {
        cout<<"\n\nPodaj liczbe: ";
        cin>>liczba_uzytkownika;
        liczba_prob++;
        if(wylosowana_liczba==liczba_uzytkownika)
        {
            cout<<"Brawo! Wygrales po "<<liczba_prob<<" probach!";
        }

        if(wylosowana_liczba>liczba_uzytkownika)
        {
            cout<<"To za malo. To twoja "<<liczba_prob<<" proba.";
        }

        if(wylosowana_liczba<liczba_uzytkownika)
        {
            cout<<"To za duzo. To twoja "<<liczba_prob<<" proba.";
        }
    }

    cout<<"\n\n";

    getchar();getchar(;)

    return 0;
}
