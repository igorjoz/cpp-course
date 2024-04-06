#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

//                  Zmienne pobierana od uzytkownika
int wybor;                         // Zmienna wyboru (aby stworzyc switch case)
int lok_A_stopnie, lok_B_stopnie;  // Zmienna stopni (polozenie geograficzne)
int lok_A_minuty, lok_B_minuty;    // Zmienna minut (polozenie geograficzne)
string polkula_A, polkula_B;       // Zmienna polkuli na jakiej znajduja sie punkty

//                  Zmienna uzywane do obliczen
int obliczenia_lok_A_stopnie, obliczenia_lok_B_stopnie; //zmienna stopni (polozenie geograficzne)
int obliczenia_lok_A_minuty, obliczenia_lok_B_minuty;

int sekundy_zmiany, zamiana_sekundy_zmiany;   //  Zmienna reprezentujaca roznice czasu miedzy punktami w sekundach oraz jej kopia
float minuty_zmiany, zamiana_minuty_zmiany;    //  Zmienna reprezentujaca roznice czasu miedzy punktami w minutach
int zm_minuty_zmiany;
float godziny_zmiany;   //  Zmienna reprezentujaca roznice czasu miedzy punktami w godzinach
int blad;                          //Zmienna sluzaca do zerwania switch case

// -----------------------------------------------------------------------------------------------------------------------------------

//                              Funkcja obliczjaca sekundy roznicy czasu miedzy punktem A i B
void roznica_sekund (int lok_A_stopnie, int lok_B_stopnie, string polkula_A, string polkula_B, int lok_A_minuty, int lok_B_minuty, int obliczenia_lok_A_stopnie, int obliczenia_lok_B_stopnie, int obliczenia_lok_A_minuty, int obliczenia_lok_B_minuty)
{
    obliczenia_lok_A_stopnie=lok_A_stopnie; //  Przypisanie wartosci zmiennej stopni do obliczen
    obliczenia_lok_B_stopnie=lok_B_stopnie; //  -||-

    obliczenia_lok_A_minuty=lok_A_minuty+(60*lok_A_stopnie);  //  Zamiana stopni na minuty oraz dodanie wczesniej pobranych od uzytkownika minut
    obliczenia_lok_B_minuty=lok_B_minuty+(60*lok_B_stopnie);  //  -||-


    if ((polkula_A=="E" && polkula_B=="E") || (polkula_A=="W" && polkula_B=="W")) // Dla sytuacji kiedy punkty znajduja sie na tej samej polkuli
    {
        sekundy_zmiany=4*(obliczenia_lok_A_minuty-obliczenia_lok_B_minuty);
    }

    if ((polkula_A=="E" && polkula_B=="W") || (polkula_A=="W" && polkula_B=="E")) // Dla sytuacji kiedy punkty znajduja sie na roznych polkulach
    {
        sekundy_zmiany=4*(obliczenia_lok_A_minuty+obliczenia_lok_B_minuty);
    }

//  Funkcja wartosci bezwzglednej [zastepuje abs()]
    if (sekundy_zmiany<0)
    {
        sekundy_zmiany=-sekundy_zmiany;
    }
}

// ----------------------------------------------------------------------------------------------------------------------------------------

//                                    Funkcja zamieniajaca roznice czasu w sekundach na minuty
void zamiana_na_minuty (int sekundy_zmiany)
{
    minuty_zmiany=sekundy_zmiany/60;
    minuty_zmiany=round(minuty_zmiany);

    zamiana_sekundy_zmiany=sekundy_zmiany%60;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------

//                                          Funkcja zamieniajaca roznice czasu w sekundach na minuty
void zamiana_na_godziny (int sekundy_zmiany, float minuty_zmiany)
{
    godziny_zmiany=sekundy_zmiany/3600;
    godziny_zmiany=round(godziny_zmiany);

    minuty_zmiany=round(minuty_zmiany);
    zm_minuty_zmiany=minuty_zmiany;

    zamiana_minuty_zmiany=zm_minuty_zmiany%60;
    zamiana_minuty_zmiany=round(zamiana_minuty_zmiany);

    zamiana_sekundy_zmiany=sekundy_zmiany%60;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

//                                      Funkcja sprawdzajaca poprawnosc wprowadzanych danych
void poprawnosc (int lok_A_stopnie, int lok_B_stopnie, string polkula_A, string polkula_B, int lok_A_minuty, int lok_B_minuty)
{
    if (lok_A_stopnie>180 || lok_B_stopnie>180)
    {
        cout<<"\nBledna wartosc! Dlugosc geograficzna nie moze byc wieksza niz 180 stopni!";
        blad=1;
    }

    if (lok_A_minuty>59 || lok_B_minuty>59)
    {
        cout<<"\nBledna wartosc! Jesli wartosc minut jest wieksza niz 59 to powinienes zamienic je na stopnie.";
        blad=1;
    }

    if ((polkula_B!="E" && polkula_B!="W" && polkula_B.length()!=0) || (polkula_A!="E" && polkula_A!="W" && polkula_A.length()!=0))
    {
        cout<<"\nBledny kierunek! Musisz wpisac E lub W.";
        blad=1;
    }
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    cout << "Program obliczajacy roznice w czasie slonecznym miedzy dwoma punktami\n\n" << endl;

//                           MENU
    cout<<"Podaj cyfre opcji, ktora odpowiada twojej sytuacji:  \n";
    cout<<"1. Znam polozenie punktu A i punktu B - OBLICZANIE ROZNICY CZASU\n";
    cout<<"2. Znam polozenie punktu A i punktu B oraz godzine w punkcie B - OBLICZANIE KONKRETNEJ GODZINY W PUNKCIE A\n";
    cout<<"3. Znam roznice czasu miedzy punktem A i punktem B - OBLICZANIE ROZNICY ODLEGLOSCI KATOWEJ\n";
    cout<<"4. Wyjscie z programu\n";
    cout<<"Twoj wybor (cyfra): ";
    cin>>wybor;

    cout<<"\n\n";

    // TUTAJ POWINNA BYC PETLA - JESLI KTOS POPELNI BLAD TO PROGRAM POWINIEN WRACAC DO POCZATKU

// --------------------------------------------------------------------------------------------------------------------------------------------------

// Realizacja odpowiedniej opcji wybranej w menu
    switch (wybor)
    {

//             PIERWSZA OPCJA - ROZNICA CZASU
case 1:

    cout<<"Podaj lokalizacje punktu A:\n";
    cout<<"Podaj dlugosc geograficzna:\n";
    cout<<"w stopniach: ";
    cin>>lok_A_stopnie;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty);
    if (blad==1) break;


    cout<<"w minutach: ";
    cin>>lok_A_minuty;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty);
    if (blad==1) break;


    cout<<"\n";
    cout<<"Podaj polkule na ktorej znajduje sie punkt A (E lub W): ";
    cin>>polkula_A;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty);
    if (blad==1) break;


    cout<<"\n\n";
    cout<<"Podaj lokalizacje punktu B:\n";
    cout<<"Podaj dlugosc geograficzna:\n";
    cout<<"w stopniach: ";
    cin>>lok_B_stopnie;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty);
    if (blad==1) break;


    cout<<"w minutach: ";
    cin>>lok_B_minuty;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty);
    if (blad==1) break;


    cout<<"\n";
    cout<<"Podaj polkule na ktorej znajduje sie punkt A (E lub W): ";
    cin>>polkula_B;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty);
    if (blad==1) break;


    cout<<"\n\n\n";

    cout<<"Roznica czasu miedzy:\npunktem A o wpolrzednych: "<<lok_A_stopnie<<" stopni, "<<lok_A_minuty<<" minut "<<polkula_A<<",";
    cout<<"\na punktem B o wspolrzednych "<<lok_B_stopnie<<" stopni, "<<lok_B_minuty<<" minut "<<polkula_B<<"\nwynosi: ";

    roznica_sekund (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, obliczenia_lok_A_stopnie, obliczenia_lok_B_stopnie, obliczenia_lok_A_minuty, obliczenia_lok_B_minuty);

    if (sekundy_zmiany<60) cout<<sekundy_zmiany<<" sekund";

    if (sekundy_zmiany>=60 && sekundy_zmiany<3600)
    {
        zamiana_na_minuty (sekundy_zmiany);
        cout<<minuty_zmiany<<" minut i "<<zamiana_sekundy_zmiany<<" sekund";
    }

    if (sekundy_zmiany>=3600)
    {
        zamiana_na_minuty (sekundy_zmiany);
        zamiana_na_godziny (sekundy_zmiany, minuty_zmiany);
        cout<<godziny_zmiany<<" godzin, "<<zamiana_minuty_zmiany<<" minut i "<<zamiana_sekundy_zmiany<<" sekund";
    }

break;

//                 DRUGA OPCJA - KONKRETNA GODZINA - CZAS SLONECZNY
case 2:
        cout<<"Ta opcja nie jest jeszcze gotowa";
        break;

//                 TRZECIA OPCJA - ODLEGLOSC KATOWA
case 3:
    cout<<"Ta opcja nie jest jeszcze gotowa";
    break;

//                 CZWARTA OPCJA - ZAKONCZENIE PROGRAMU
case 4:
        break;

//                 GDY W MENU NIE ZOSTANIE WYBRANA ZADNA LICZBA
default:
    cout<<"Blad! Nie ma takiej opcji w menu!";
    break;

}

    cout<<"\n\n\n-------------KONIEC PROGRAMU-------------\n\n";
    system( "PAUSE" );
    return 0;
}
