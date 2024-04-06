#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Tablica nazw miesiecy; Uwaga! styczen == 0, a nie 1
string miesiace [12] = {"styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec", "sierpien", "wrzesien", "pazdziernik",     "listopad", "grudzien"};

// Tablica nazw dni tygodnia; Uwaga! poniedzialek == 0, a nie 1
string dni [7] = {"poniedzialek", "wtorek", "sroda", "czwartek", "piatek", "sobota", "niedziela"};

int wybor1, wybor2;
int teraz, przesuniecie;
int po_przesunieciu;

void pobranie_wybor2 ()
{
    cout<<endl;

    if (wybor1==1)
    {
        cout<<endl<<"Jaka akcje chcesz wykonac:"<<endl;
        cout<<"1. Odjecie dni tygodnia"<<endl;
        cout<<"2. Dodanie dni tygodnia"<<endl;
        cout<<"Twoj wybor: ";
        cin>>wybor2;
    }

    if (wybor1==2)
    {
        cout<<"Jaka akcje chcesz wykonac:"<<endl;
        cout<<"1. Odjecie miesiecy"<<endl;
        cout<<"2. Dodanie miesiecy"<<endl;
        cout<<"Twoj wybor: ";
        cin>>wybor2;
    }
}

void pobranie_przesuniecia ()
{
    if (wybor1==1)
    {
        cout<<endl<<"Ile dni chcesz sie przesunac? (liczba): ";
        cin>>przesuniecie;
    }

    if (wybor1==2)
    {
        cout<<endl<<"Ile miesiecy chcesz sie przesunac? (liczba): ";
        cin>>przesuniecie;
    }
}

void funkcja_dni_tygodnia (int teraz, int przesuniecie)
{
    if (wybor2 == 1)
    {
        po_przesunieciu = abs(teraz-przesuniecie);
        po_przesunieciu = po_przesunieciu % 7;
    }

    if (wybor2 == 2)
    {
        po_przesunieciu = ((teraz+przesuniecie) % 7);
    }

}

void funkcja_miesiace (int teraz, int przesuniecie)
{
    if (wybor2 == 1)
    {
        po_przesunieciu = abs(teraz-przesuniecie);
        po_przesunieciu = po_przesunieciu % 12;
    }

    if (wybor2 == 2)
    {
        po_przesunieciu = ((teraz+przesuniecie) % 12);
    }
}

void wypisanie_wyniku (int wynik)
{
    cout<<endl<<endl<<"Wynik: ";
    if (wybor1==1)
    {
        cout<<dni[wynik-1];
    }

    if (wybor1==2)
    {
        cout<<miesiace[wynik-1];
    }
}

int main()
{
    cout<<"Program do odejmowania i dodawania dni tygodnia lub miesiecy"<<endl<<endl;

    cout<<"Podaj jaka czynnosc chcialbys wykonac:"<<endl;
    cout<<"1. DNI TYGODNIA"<<endl;
    cout<<"2. MIESIACE"<<endl;
    cout<<"Twoj wybor: ";
    cin>>wybor1;

    switch (wybor1)
    {
    case 1:
        cout<<endl<<"Podaj aktualny dzien tygodnia (numerowo; 1-7): ";
        cin>>teraz;
        pobranie_wybor2 ();
        pobranie_przesuniecia ();
        funkcja_dni_tygodnia (teraz, przesuniecie);
        wypisanie_wyniku (po_przesunieciu);
        break;

    case 2:
        cout<<endl<<"Podaj aktualny miesiac (numerowo; 1-12): ";
        cin>>teraz;
        pobranie_wybor2 ();
        pobranie_przesuniecia ();
        funkcja_miesiace (teraz, przesuniecie);
        wypisanie_wyniku (po_przesunieciu);
        break;

    default:
        cout<<endl<<endl<<"Blad! Nie ma takiej opcji";
        exit(0);
    }


    cout<<endl<<endl;
    return 0;
}
