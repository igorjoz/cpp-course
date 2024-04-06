#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <windows.h>

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
int obliczenia_lok_A_stopnie, obliczenia_lok_B_stopnie; // Zmienne stopni (polozenie geograficzne - dlugosc geograficzna) do obliczen (aby nie zmieniac wartosci pierwotnych danych wprowadzonych przez uzytkownika
int obliczenia_lok_A_minuty, obliczenia_lok_B_minuty;   // Zmienne minut (polozenie geograficzne - dlugosc geograficzna) do obliczen (aby nie zmieniac wartosci pierwotnych danych wprowadzonych przez uzytkownika

int sekundy_zmiany, sekundy_zmiany_obliczenia;      //  Zmienna reprezentujaca roznice czasu miedzy punktami w sekundach oraz jej klon do obliczen
int minuty_zmiany;       //  Zmienna reprezentujaca roznice czasu miedzy punktami w minutach
int godziny_zmiany;      // Zmienna reprezentujaca roznice czasu miedzy punktami w godzinach

int godzina_A, minuta_A, sekunda_A;                         // Zmienna potrzebna do obliczenia czasu w punkcie A
int calkowita_suma_sekund, calkowita_roznica_sekund;        // Zmienna uzywana do ulatwienia zapisow i obliczen (unifikacja dzialan an zmiennych)
int czy_kolejny_dzien, czy_poprzedni_dzien;                 // Zmienne potrzebne do sprawdzenia prawdziwosci przesuniecia sie daty o jeden dzien do przodu lub do tylu

//                  Inne zmienne
bool blad;                  // Zmienna sluzaca do zasygnalizowania bledu, jesli blad==true switch case zostaje zerwany
bool wyjscie;               // Zmienna sluzuzoca do zapytania uzytkownika czy chce wyjsc czy tez uzyc programu ponownie
string odpowiedz_wyjscie;   // Zmienna do magazynowania odpowiedz uzytkownika w postaci tak lub nie (true lub false)
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

//             Funkcja zamieniajaca roznice czasu w sekundach na minuty i godziny (jesli sekund zmiany jest wiecej niz 60)
void zamiana_sekund_na_minuty_i_godziny (int sekundy_zmiany_obliczenia)
{
    sekundy_zmiany_obliczenia=sekundy_zmiany;

    while (sekundy_zmiany_obliczenia>=60)
    {
        if (sekundy_zmiany_obliczenia>=60 && sekundy_zmiany_obliczenia<3600)
        {
            sekundy_zmiany_obliczenia=sekundy_zmiany_obliczenia-60;
            minuty_zmiany=minuty_zmiany+1;
        }

        if (sekundy_zmiany_obliczenia>=3600)
        {
            sekundy_zmiany_obliczenia=sekundy_zmiany_obliczenia-3600;
            godziny_zmiany=godziny_zmiany+1;
        }
    }

    sekundy_zmiany=sekundy_zmiany_obliczenia;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

//                                      Funkcja sprawdzajaca poprawnosc wprowadzanych danych
void poprawnosc (int lok_A_stopnie, int lok_B_stopnie, string polkula_A, string polkula_B, int lok_A_minuty, int lok_B_minuty, int godzina_B, int minuta_B, int sekunda_B)
{
    if (lok_A_stopnie>180 || lok_B_stopnie>180)
    {
        cout<<"\nBledna wartosc! Dlugosc geograficzna nie moze byc wieksza niz 180 stopni!";
        blad=true;
    }

    if (lok_A_minuty>59 || lok_B_minuty>59)
    {
        cout<<"\nBledna wartosc! Jesli wartosc minut jest wieksza niz 59 to powinienes zamienic je na stopnie.";
        blad=true;
    }

    if ((polkula_B!="E" && polkula_B!="W" && polkula_B.length()!=0) || (polkula_A!="E" && polkula_A!="W" && polkula_A.length()!=0))
    {
        cout<<"\nBledny kierunek! Musisz wpisac E lub W.";
        blad=true;
    }

    if (godzina_B>23)
    {
        cout<<"\nBledna wartosc godziny! Wartosc godziny nie moze byc wieksza niz 23.";
        blad=true;
    }

    if (minuta_B>59)
    {
        cout<<"\nBledna wartosc minuty! Wartosc minuty nie moze byc wieksza niz 59.";
        blad=true;
    }

    if (sekunda_B>59)
    {
        cout<<"\nBledna wartosc sekundy! Wartosc sekundy nie moze byc wieksza niz 59.";
        blad=true;
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

    kod_informacyjny[1]="1"; //Druga cyfra (od lewej) w kodzie informacyjnym bedzie wynosila 1 gdy zostanie uruchomiona funkcja obliczania czasu w punkcie A (funkcja z dodawaniem)
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

    kod_informacyjny[1]="2"; //Druga cyfra (od lewej) w kodzie informacyjnym bedzie wynosila 2 gdy zostanie uruchomiona funkcja obliczania czasu w punkcie A (funkcja z odejmowaniem)
}

void pobranie_lokalizacja_A_stopnie ()
{
    cout<<"Podaj lokalizacje punktu A:\n";
    cout<<"Podaj dlugosc geograficzna:\n";
    cout<<"w stopniach: ";
    cin>>lok_A_stopnie;
}

void pobranie_lokalizacja_A_minuty ()
{
    cout<<"w minutach: ";
    cin>>lok_A_minuty;
}

void pobranie_A_polkula ()
{
    cout<<"\n";
    cout<<"Podaj polkule na ktorej znajduje sie punkt A (W lub E): ";
    cin>>polkula_A;
}

void pobranie_lokalizacja_B_stopnie ()
{
    cout<<"\n\n";
    cout<<"Podaj lokalizacje punktu B:\n";
    cout<<"Podaj dlugosc geograficzna:\n";
    cout<<"w stopniach: ";
    cin>>lok_B_stopnie;
}

void pobranie_lokalizacja_B_minuty ()
{
    cout<<"w minutach: ";
    cin>>lok_B_minuty;
}

void pobranie_B_polkula ()
{
    cout<<"\n";
    cout<<"Podaj polkule na ktorej znajduje sie punkt B (W lub E): ";
    cin>>polkula_B;
}

void pobranie_godzina_B ()
{
    cout<<"\n";
    cout<<"Podaj godzine w punkcie B (GODZINA:MINUTA:SEKUNDA, format 24 godzinny)\n";
    cout<<"Wprowadz godzine: ";
    cin>>godzina_B;
}

void pobranie_minuta_B ()
{
    cout<<"Wprowadz minute: ";
    cin>>minuta_B;
}

void pobranie_sekunda_B ()
{
    cout<<"Wprowadz sekunde: ";
    cin>>sekunda_B;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    do
    {

    do //Rozpoczecie petli z warunkiem blad==true
    {
    blad=false; //Wyzerowanie wartosci bledu

// ---------------------------------------------------------------------------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------------------------------------------------------------------------

// Realizacja odpowiedniej opcji wybranej w menu
    switch (wybor)
    {

//             PIERWSZA OPCJA - ROZNICA CZASU
case 1:

    kod_informacyjny[0]="1";

    pobranie_lokalizacja_A_stopnie();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_lokalizacja_A_minuty();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_A_polkula();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_lokalizacja_B_stopnie();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_lokalizacja_B_minuty();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_B_polkula();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    cout<<"\n\n\n";

    cout<<"Roznica czasu miedzy:\npunktem A o wpolrzednych: "<<lok_A_stopnie<<" stopni, "<<lok_A_minuty<<" minut "<<polkula_A<<",";
    cout<<"\na punktem B o wspolrzednych "<<lok_B_stopnie<<" stopni, "<<lok_B_minuty<<" minut "<<polkula_B<<"\nwynosi: ";

    roznica_sekund (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, obliczenia_lok_A_stopnie, obliczenia_lok_B_stopnie, obliczenia_lok_A_minuty, obliczenia_lok_B_minuty);

    zamiana_sekund_na_minuty_i_godziny (sekundy_zmiany);

    cout<<godziny_zmiany<<" godzin, "<<minuty_zmiany<<" minut i "<<sekundy_zmiany<<" sekund";

break;

// --------------------------------------------------------------------------------------------------------------------------------------------------
//                 DRUGA OPCJA - KONKRETNA GODZINA - CZAS SLONECZNY
case 2:

    kod_informacyjny[0]="2";

    pobranie_lokalizacja_A_stopnie();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_lokalizacja_A_minuty();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_A_polkula();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_lokalizacja_B_stopnie();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_lokalizacja_B_minuty ();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_B_polkula();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_godzina_B ();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_minuta_B ();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    pobranie_sekunda_B ();
    poprawnosc (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, godzina_B, minuta_B, sekunda_B);
    if (blad==true) break;

    roznica_sekund (lok_A_stopnie, lok_B_stopnie, polkula_A, polkula_B, lok_A_minuty, lok_B_minuty, obliczenia_lok_A_stopnie, obliczenia_lok_B_stopnie, obliczenia_lok_A_minuty, obliczenia_lok_B_minuty);

    if (polkula_A=="W" && polkula_B=="W") //Oba punkty leza na polkuli W
    {
        if ((lok_A_stopnie>lok_B_stopnie) || (lok_A_stopnie==lok_B_stopnie && lok_A_minuty>lok_B_minuty)) //Punkt A lezy dalej na zachod od punktu B
        {
            czas_w_A_odejmowanie (sekundy_zmiany, godzina_B, minuta_B, sekunda_B);
        }

        if ((lok_A_stopnie<lok_B_stopnie) || (lok_A_stopnie==lok_B_stopnie && lok_A_minuty<lok_B_minuty)) //Punkt B lezy dalej na zachod od punktu A
        {
            czas_w_A_dodawanie (sekundy_zmiany, godzina_B, minuta_B, sekunda_B);
        }
    }

    if (polkula_A=="E" && polkula_B=="E") //Oba punkty leza na polkuli W
    {
        if ((lok_A_stopnie>lok_B_stopnie) || (lok_A_stopnie==lok_B_stopnie && lok_A_minuty>lok_B_minuty)) //Punkt A lezy dalej na wschod od punktu B
        {
            czas_w_A_dodawanie (sekundy_zmiany, godzina_B, minuta_B, sekunda_B);
        }

        if ((lok_A_stopnie<lok_B_stopnie) || (lok_A_stopnie==lok_B_stopnie && lok_A_minuty<lok_B_minuty)) //Punkt B lezy dalej na wschod od punktu A
        {
            czas_w_A_odejmowanie (sekundy_zmiany, godzina_B, minuta_B, sekunda_B);
        }
    }

    if (polkula_A=="W" && polkula_B=="E") //Punkt A lezy na polkuli W, a punkt B lezy na polkuli E
    {
            czas_w_A_odejmowanie (sekundy_zmiany, godzina_B, minuta_B, sekunda_B);
    }

    if (polkula_A=="E" && polkula_B=="W") //Punkt A lezy na polkuli E, a punkt B lezy na polkuli W
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
    wyjscie=true;

        break;

//                 GDY W MENU NIE ZOSTANIE WYBRANA ZADNA LICZBA
default:
    kod_informacyjny[0]="0";
    cout<<"Blad! Nie ma takiej opcji w menu!";
    blad=true;
    break;
}

if (blad==true)
{
    cout<<"\nWPROWADZ POPRAWNE DANE!\n";
    cout<<"Restart programu za: ";

    for (int k=8; k>=0; k--) //Odliczanie do restartu programu
    {
        if (k>0) cout<<k<<", ";
        if (k==0) cout<<k;
        Sleep(1000);
    }

    system("cls"); //Wyczyszczenie ekranu
}

} while (blad==true); //Petla powtarzajaca sie dopoki wystopil jakis blad

if (wyjscie!=true)
{
cout<<"\n\nCzy chcesz uzyc programu jeszcze raz?\nOdpowiedz (tak lub nie): ";
cin>>odpowiedz_wyjscie;
cout<<"\n\n";
}

if (odpowiedz_wyjscie=="tak" || odpowiedz_wyjscie=="Tak" || odpowiedz_wyjscie=="TAK")
{
    wyjscie=false;
    system("cls");
}

if (odpowiedz_wyjscie=="nie" || odpowiedz_wyjscie=="Nie" || odpowiedz_wyjscie=="NIE")
{
    wyjscie=true;
}

} while (wyjscie==false);
    cout<<"\n\n\n-------------KONIEC PROGRAMU-------------\n";

    cout<<"Kod informacyjny: ";
    for (int k=0; k<i; k++)
    {
        cout<<kod_informacyjny[k];
    }
        cout<<"\n\n";

    system("PAUSE");

    return 0;
}
