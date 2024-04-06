#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>

// -----------------------------------------------------------------------------------------------------------------------------------

using namespace std;

// -----------------------------------------------------------------------------------------------------------------------------------

//                  Zmienne pobierane od uzytkownika
int wybor;                          // Zmienna wyboru (aby stworzyc switch case)

int lok_A_stopnie, lok_B_stopnie;   // Zmienne stopni (polozenie geograficzne - dlugosc geograficzna) (1. i 2. wybor)
int lok_A_minuty, lok_B_minuty;     // Zmienne minut (polozenie geograficzne - dlugosc geograficzna)  (1. i 2. wybor)
string polkula_A, polkula_B;        // Zmienne polkuli na jakiej znajduja sie punkty A i B            (1. i 2. wybor)

int godzina_B, minuta_B, sekunda_B; // Zmienne potrzebne do okreslenia czasu w punkcie B              (2. wybor)

//                  Zmienna uzywane do obliczen
int obliczenia_lok_A_stopnie, obliczenia_lok_B_stopnie; // Zmienne stopni (polozenie geograficzne - dlugosc geograficzna)
int obliczenia_lok_A_minuty, obliczenia_lok_B_minuty;   // Zmienne minut (polozenie geograficzne - dlugosc geograficzna)

int sekundy_zmiany, zamiana_sekundy_zmiany;    //  Zmienna reprezentujaca roznice czasu miedzy punktami w sekundach oraz jej kopia potrzebna do zamiany jednostek
float minuty_zmiany, zamiana_minuty_zmiany;    //  Zmienna reprezentujaca roznice czasu miedzy punktami w minutach
int zm_minuty_zmiany;                          //
float godziny_zmiany;                          // Zmienna reprezentujaca roznice czasu miedzy punktami w godzinach

int godzina_A, minuta_A, sekunda_A;                         // Zmienna potrzebna do obliczenia czasu w punkcie A
int calkowita_suma_sekund, calkowita_roznica_sekund;        // Zmienna uzywana do ulatwienia zapisow i obliczen (unifikacja dzialan an zmiennych)
int czy_kolejny_dzien, czy_poprzedni_dzien;                 // Zmienne potrzebne do sprawdzenia prawdziwosci przesuniecia sie daty o jeden dzien do przodu lub do tylu

//                  Inne zmienne
int blad;                   // Zmienna sluzaca do zasygnalizowania bledu, jesli blad==1 switch case zostaje zerwany
int const i=10;             // Stala zmienna okreslajaca dlugosc kodu informacyjnego
string kod_informacyjny[i]; // Kod uzywany do debuggowania

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
void poprawnosc (int lok_A_stopnie, int lok_B_stopnie, string polkula_A, string polkula_B, int lok_A_minuty, int lok_B_minuty, int godzina_B, int minuta_B, int sekunda_B)
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

    if (godzina_B>23)
    {
        cout<<"\nBledna wartosc godziny! Wartosc godziny nie moze byc wieksza niz 23.";
        blad=1;
    }

    if (minuta_B>59)
    {
        cout<<"\nBledna wartosc minuty! Wartosc minuty nie moze byc wieksza niz 59.";
        blad=1;
    }

    if (sekunda_B>59)
    {
        cout<<"\nBledna wartosc sekundy! Wartosc sekundy nie moze byc wieksza niz 59.";
        blad=1;
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------
// Funkcja obliczania czasu w punkcie A, kiedy nalezy dodac do czasu w punkcie A wartosc roznicy czasu miedzy punktem A, a punktem B - zamiana jednostek
void czas_w_A_dodawanie (int sekundy_zmiany, int godzina_B, int minuta_B, int sekunda_B)
{
    calkowita_suma_sekund=sekunda_B+sekundy_zmiany; //Ujednolicenie dzialania sumy w jedna zmienna dla ulatwienia obliczen

    godzina_A=godzina_B;                  //Przypisanie wartosci podstawowej godzinom w punkcie A
    minuta_A=minuta_B;                    //Przypisanie wartosci podstawowej minutom w punkcie A

    while (calkowita_suma_sekund>=60)     //Zamiana jednostek, az do czasu kiedy wartosc sekund w punkcie A bedzie mniejsza od 60
    {
        if (minuta_A<60)                  //Zamiana sekund na minuty
        {
            minuta_A=minuta_A+1;
            calkowita_suma_sekund=calkowita_suma_sekund-60;
        }

        if (minuta_A==60 && godzina_A<24) //Zamiana minut na godziny
        {
            godzina_A=godzina_A+1;
            minuta_A=minuta_A-60;
        }

        if (godzina_A==24)                //Zamiana godzin na dzien
        {
            czy_kolejny_dzien=1;
            godzina_A=godzina_A-24;
        }
    }

    sekunda_A=calkowita_suma_sekund;      //Przypisanie do sekund w punkcie A pozostalych sekund po procesie zamiany na wieksze jednostki

    kod_informacyjny[1]="1"; //Liczba setek w kodzie informacyjnym bedzie wynosila 1 gdy zostanie uruchomiona funkcja obliczania czasu w punkcie A (funkcja z dodawaniem)
}

//---------------------------------------------------------------------------------------------------------------------------------------------
// Funkcja obliczania czasu w punkcie A, kiedy nalezy odjac od czasu w punkcie A wartosc roznicy czasu miedzy punktem A, a punktem B - zamiana jednostek
void czas_w_A_odejmowanie (int sekundy_zmiany, int godzina_B, int minuta_B, int sekunda_B)
{
    calkowita_roznica_sekund=sekunda_B-sekundy_zmiany; //Ujednolicenie dzialania roznicy w jedna zmienna dla ulatwienia obliczen

    godzina_A=godzina_B;                  //Przypisanie wartosci podstawowej godzinom w punkcie A
    minuta_A=minuta_B;                    //Przypisanie wartosci podstawowej minutom w punkcie A

    while (calkowita_roznica_sekund<0)    //Zamiana jednostek do momentu, az sekundy w punkcie A beda na plusie
                {
                    if (minuta_A>=0)       //Zamiana minut na sekundy
                    {
                    minuta_A=minuta_A-1;
                    calkowita_roznica_sekund=calkowita_roznica_sekund+60;
                    kod_informacyjny[2]="2";
                    }

                    if (minuta_A<0 && godzina_A>0)       //Zamiana godzin na minuty
                    {
                        godzina_A=godzina_A-1;
                        minuta_A=minuta_A+60;
                        kod_informacyjny[3]="2";
                    }

                    if (godzina_A==0 && minuta_A==0) //Zamiana dnia na godziny
                    {
                        czy_poprzedni_dzien=1;
                        godzina_A=godzina_A+24;
                        kod_informacyjny[4]="2";
                    }
                }

    sekunda_A=calkowita_roznica_sekund;      //Przypisanie do sekund w punkcie A pozostalych sekund po procesie zamiany na wieksze jednostki

    kod_informacyjny[1]="2"; //Liczba setek w kodzie informacyjnym bedzie wynosila 2 gdy zostanie uruchomiona funkcja obliczania czasu w punkcie A (funkcja z odejmowaniem)
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    for (int k=0; k<i; k++) //Wyzerowanie kodu informacyjnego
    {
        kod_informacyjny[k]="0";
    }

// ---------------------------------------------------------------------------------------------------------------------------------------------------

    cout << "Program obliczajacy roznice w czasie slonecznym miedzy dwoma punktami\n\n" << endl;

//                           MENU WYBORU
    cout<<"Podaj cyfre opcji, ktora odpowiada twojej sytuacji:  \n";
    cout<<"1. Znam polozenie punktu A i punktu B - OBLICZANIE ROZNICY CZASU SLONECZNEGO\n";
    cout<<"2. Znam polozenie punktu A i punktu B oraz godzine w punkcie B - OBLICZANIE KONKRETNEJ GODZINY W PUNKCIE A\n";
    cout<<"3. Znam roznice czasu miedzy punktem A i punktem B - OBLICZANIE ROZNICY ODLEGLOSCI KATOWEJ\n";
    cout<<"4. Wyjscie z programu\n";
    cout<<"Twoj wybor (cyfra): ";
    cin>>wybor;

    cout<<"\n\n";

    // TUTAJ POWINNA BYC PETLA - JESLI KTOS POPELNI BLAD TO PROGRAM POWINIEN WRACAC DO POCZATKU LUB MOMENTU WPROWADZANIA WCZESNIEJ ZLE PODANEJ DANEJ

// --------------------------------------------------------------------------------------------------------------------------------------------------

// Realizacja odpowiedniej opcji wybranej w menu
    switch (wybor)
    {

//             PIERWSZA OPCJA - ROZNICA CZASU
case 1:

    kod_informacyjny[0]="1";

    cout<<"Podaj lokalizacje punktu A:\n";
    cout<<"Podaj dlugosc geograficzna:\n";
    cout<<"w stopniach: ";
    cin>>lok_A_stopnie;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;


    cout<<"w minutach: ";
    cin>>lok_A_minuty;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;


    cout<<"\n";
    cout<<"Podaj polkule na ktorej znajduje sie punkt A (W lub E): ";
    cin>>polkula_A;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;


    cout<<"\n\n";
    cout<<"Podaj lokalizacje punktu B:\n";
    cout<<"Podaj dlugosc geograficzna:\n";
    cout<<"w stopniach: ";
    cin>>lok_B_stopnie;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;


    cout<<"w minutach: ";
    cin>>lok_B_minuty;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;


    cout<<"\n";
    cout<<"Podaj polkule na ktorej znajduje sie punkt B (W lub E): ";
    cin>>polkula_B;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
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

// --------------------------------------------------------------------------------------------------------------------------------------------------
//                 DRUGA OPCJA - KONKRETNA GODZINA - CZAS SLONECZNY
case 2:

    kod_informacyjny[0]="2";

    cout<<"Podaj lokalizacje punktu A:\n";
    cout<<"Podaj dlugosc geograficzna:\n";
    cout<<"w stopniach: ";
    cin>>lok_A_stopnie;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;


    cout<<"w minutach: ";
    cin>>lok_A_minuty;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;


    cout<<"\n";
    cout<<"Podaj polkule na ktorej znajduje sie punkt A (W lub E): ";
    cin>>polkula_A;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;


    cout<<"\n\n";
    cout<<"Podaj lokalizacje punktu B:\n";
    cout<<"Podaj dlugosc geograficzna:\n";
    cout<<"w stopniach: ";
    cin>>lok_B_stopnie;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;


    cout<<"w minutach: ";
    cin>>lok_B_minuty;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;


    cout<<"\n";
    cout<<"Podaj polkule na ktorej znajduje sie punkt B (W lub E): ";
    cin>>polkula_B;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;

    cout<<"\n";
    cout<<"Podaj godzine w punkcie B (GODZINA:MINUTA:SEKUNDA, format 24 godzinny)\n";
    cout<<"Wprowadz godzine: ";
    cin>>godzina_B;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;

    cout<<"Wprowadz minute: ";
    cin>>minuta_B;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;

    cout<<"Wprowadz sekunde: ";
    cin>>sekunda_B;

    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==1) break;

    roznica_sekund (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, obliczenia_lok_A_stopnie, obliczenia_lok_B_stopnie, obliczenia_lok_A_minuty, obliczenia_lok_B_minuty);

    if (polkula_A=="W" && polkula_B=="W") //1. POZIOM IF - Oba punkty leza na polkuli W
    {
        if ((lok_A_stopnie>lok_B_stopnie) || (lok_A_stopnie==lok_B_stopnie && lok_A_minuty>lok_B_minuty)) //2. POZIOM IF - Punkt A lezy dalej na zachod od punktu B
        {
            czas_w_A_odejmowanie (sekundy_zmiany, godzina_B, minuta_B, sekunda_B);
        }

        if ((lok_A_stopnie<lok_B_stopnie) || (lok_A_stopnie==lok_B_stopnie && lok_A_minuty<lok_B_minuty)) //2. POZIOM IF - Punkt B lezy dalej na zachod od punktu A
        {
            czas_w_A_dodawanie (sekundy_zmiany, godzina_B, minuta_B, sekunda_B);
        }
    }

    if (polkula_A=="E" && polkula_B=="E") //1. POZIOM IF - Oba punkty leza na polkuli W
    {
        if ((lok_A_stopnie>lok_B_stopnie) || (lok_A_stopnie==lok_B_stopnie && lok_A_minuty>lok_B_minuty)) //2. POZIOM IF - Punkt A lezy dalej na wschod od punktu B
        {
            czas_w_A_dodawanie (sekundy_zmiany, godzina_B, minuta_B, sekunda_B);
        }

        if ((lok_A_stopnie<lok_B_stopnie) || (lok_A_stopnie==lok_B_stopnie && lok_A_minuty<lok_B_minuty)) //2. POZIOM IF - Punkt B lezy dalej na wschod od punktu A
        {
            czas_w_A_odejmowanie (sekundy_zmiany, godzina_B, minuta_B, sekunda_B);
        }
    }

    if (polkula_A=="W" && polkula_B=="E") //1. POZIOM IF - Punkt A lezy na polkuli W, a punkt B lezy na polkuli E
    {
            czas_w_A_odejmowanie (sekundy_zmiany, godzina_B, minuta_B, sekunda_B);
    }

    if (polkula_A=="E" && polkula_B=="W") //1. POZIOM IF - Punkt A lezy na polkuli E, a punkt B lezy na polkuli W
    {
            czas_w_A_dodawanie (sekundy_zmiany, godzina_B, minuta_B, sekunda_B);
    }

    cout<<"\nDane punktu A:\nWspolrzedne: "<<lok_A_stopnie<<" stopni, "<<lok_A_minuty<<" minut "<<polkula_A<<"\n\n";
    cout<<"Dane punktu B:\nWspolrzedne: "<<lok_B_stopnie<<" stopni, "<<lok_B_minuty<<" minut "<<polkula_B<<"\n";
    cout<<"Godzina w punkcie B: ";

    if (godzina_B<10) cout<<"0";
    cout<<godzina_B<<":";

    if (minuta_B<10) cout<<"0";
    cout<<minuta_B<<":";

    if (sekunda_B<10) cout<<"0";
    cout<<sekunda_B;

    cout<<"\n\n\n";


    cout<<"Godzina w punkcie A to: ";

    if (godzina_A<10) cout<<"0";
    cout<<godzina_A<<":";

    if (minuta_A<10) cout<<"0";
    cout<<minuta_A<<":";

    if (sekunda_A<10) cout<<"0";
    cout<<sekunda_A;

    if (czy_poprzedni_dzien==1) cout<<" DNIA POPRZEDNIEGO (w porownaniu z czasem w punkcie B)";
    if (czy_kolejny_dzien==1) cout<<" DNIA KOLEJNEGO (w porownaniu z czasem w punkcie B)";

        break;

// --------------------------------------------------------------------------------------------------------------------------------------------------
//                 TRZECIA OPCJA - ODLEGLOSC KATOWA
case 3:

    kod_informacyjny[0]="3";

    cout<<"Ta opcja nie jest jeszcze gotowa";
    break;

//                 CZWARTA OPCJA - ZAKONCZENIE PROGRAMU
case 4:

    kod_informacyjny[0]="4";

        break;

//                 GDY W MENU NIE ZOSTANIE WYBRANA ZADNA LICZBA
default:
    kod_informacyjny[0]="0";
    cout<<"Blad! Nie ma takiej opcji w menu!";
    break;

}

    cout<<"\n\n\n-------------KONIEC PROGRAMU-------------\n";

    cout<<"Kod informacyjny: ";
    for (int k=0; k<i; k++)
    {
        cout<<kod_informacyjny[k];
    }
        cout<<"\n\n";

    system( "PAUSE" );

    return 0;
}
