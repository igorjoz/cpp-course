#include <iostream>
#include <cstdlib>

using namespace std;

int stopnie, minuty, sekundy;    // Zmienna szerokosci geograficznej punktu dla ktorego ma byc obliczone gorowanie slonca pobierana od uzytkownika
string polkula;                  // Zmienna polkuli pobierana od uzytkownika
int wybor;                       // Zmienna pobierana od uzytkownika wyboru co do daty

int stopnie_zen, minuty_zen, sekundy_zen; // Zmienne szerokosci geograficznej punktu, gdzie slonce goruje w zenicie
string polkula_zen;                         // Zmienna polkuli punktu, gdzie slonce goruje w zenicie

int wynik_stopnie, wynik_minuty, wynik_sekundy; // Zmienne wyniku obliczen - wysokosci gorowania Slonca

bool blad=false; // Zmienna do kontroli poprawnosci danych pobieranych od uzytkownika

int const n=3;              // Stala okreslajaca dlugosc kodu informacyjnego
string kod_informacyjny[n]; // Kod wyswietlany na koncu programu, pomaga w debugowaniu

// ===================================================================================

void obliczenia (int stopnie, int minuty, int sekundy, string polkula, int wybor, int stopnie_zen, int minuty_zen, int sekundy_zen, string polkula_zen);

void regulacja_wynikow (int &wynik_stopnie, int &wynik_minuty, int &wynik_sekundy);

void poprawnosc_stopnie_minuty_sekundy (int stopnie, int minuty, int sekundy, int wybor, int stopnie_zen, int minuty_zen, int sekundy_zen);

void poprawnosc_wybor (int wybor);

void poprawnosc_polkule (string polkula);

void poprawnosc_polkule_zen(string polkula_zen);

void noc_polarna (int wynik_stopnie, int wynik_minuty, int wynik_sekundy);

// ===================================================================================
// ===================================================================================

int main()
{
    //Wyzerowanie kodu informacyjnego
    for (int k=0; k<n; k++)
    {
        kod_informacyjny[k]="0";
    }

    // ===================================================================================

    cout<<"Program obliczajacy wysokosc gorowania Slonca"<<endl<<endl;

    cout<<"Podaj wspolrzedne punktu dla ktorego chcialbys obliczyc wysokosc gorowania Slonca"<<endl<<endl;

    cout<<"W stopniach: ";
    cin>>stopnie;
    poprawnosc_stopnie_minuty_sekundy (stopnie, minuty, sekundy, wybor, stopnie_zen, minuty_zen, sekundy_zen);
    if (blad==true) exit(0);

    cout<<"W minutach: ";
    cin>>minuty;
    poprawnosc_stopnie_minuty_sekundy (stopnie, minuty, sekundy, wybor, stopnie_zen, minuty_zen, sekundy_zen);
    if (blad==true) exit(0);

    cout<<"W sekundach: ";
    cin>>sekundy;
    poprawnosc_stopnie_minuty_sekundy (stopnie, minuty, sekundy, wybor, stopnie_zen, minuty_zen, sekundy_zen);
    if (blad==true) exit(0);
    cout<<endl<<endl;

// ===================================================================================

    cout<<"Podaj polkule na ktorej znajduje sie punkt (N lub S) (jesli to rownik, to wybor nie ma znaczenia): ";
    cin>>polkula;
    poprawnosc_polkule(polkula);
    if (blad==true) exit(0);
    cout<<endl<<endl;

// ===================================================================================


    cout<<"Podaj date: "<<endl;
    cout<<"1. 22.06"<<endl;
    cout<<"2. 22.12"<<endl;
    cout<<"3. 21.03 LUB 23.09"<<endl;
    cout<<"4. INNA"<<endl;
    cout<<"Twoj wybor: ";
    cin>>wybor;
    poprawnosc_wybor(wybor);
    if (blad==true) exit(0);
    cout<<endl<<endl;

// ===================================================================================

    if (wybor==4)
    {
        cout<<"Podaj wspolrzedne lokalizacji, gdzie wystepuje gorowanie Slonca w ZENICIE"<<endl;

        cout<<"W stopniach: ";
        cin>>stopnie_zen;
        poprawnosc_stopnie_minuty_sekundy (stopnie, minuty, sekundy, wybor, stopnie_zen, minuty_zen, sekundy_zen);
    if (blad==true) exit(0);

        cout<<"W minutach: ";
        cin>>minuty_zen;
        poprawnosc_stopnie_minuty_sekundy (stopnie, minuty, sekundy, wybor, stopnie_zen, minuty_zen, sekundy_zen);
    if (blad==true) exit(0);

        cout<<"W sekundach: ";
        cin>>sekundy_zen;
        poprawnosc_stopnie_minuty_sekundy (stopnie, minuty, sekundy, wybor, stopnie_zen, minuty_zen, sekundy_zen);
    if (blad==true) exit(0);
        cout<<endl<<endl;

        cout<<"Podaj polkule na ktorej znajduje sie punkt, gdzie slonce goruje w zenicie (N lub S): ";
        cin>>polkula_zen;
        poprawnosc_polkule_zen(polkula_zen);
    if (blad==true) exit(0);
        cout<<endl<<endl;
    }

// ===================================================================================

    obliczenia (stopnie, minuty, sekundy, polkula, wybor, stopnie_zen, minuty_zen, sekundy_zen, polkula_zen);

    regulacja_wynikow (wynik_stopnie, wynik_minuty, wynik_sekundy);

    cout<<"Wysokosc gorowania Slonca w punkcie o wspolrzednych:"<<endl;

    if (stopnie<10) cout<<"0";
    cout<<stopnie<<" stopni, ";

    if (minuty<10) cout<<"0";
    cout<<minuty<<" minut, ";

    if (sekundy<10) cout<<"0";
    cout<<sekundy<<" sekund "<<polkula<<endl<<endl;

    if (wybor==4)
    {
        cout<<"W momencie, kiedy Slonce goruje w zenicie w punkcie:"<<endl;

        if (stopnie<10) cout<<"0";
        cout<<stopnie_zen<<" stopni, ";

        if (minuty<10) cout<<"0";
        cout<<minuty_zen<<" minut, ";

        if (sekundy<10) cout<<"0";
        cout<<sekundy_zen<<" sekund "<<polkula<<endl<<endl;
    }


    cout<<"Wynosi: "<<wynik_stopnie<<" stopni, "<<wynik_minuty<<" minut, "<<wynik_sekundy<<" sekund";

    noc_polarna (wynik_stopnie, wynik_minuty, wynik_sekundy);

// ===================================================================================

    cout<<endl<<endl;
    cout<<"======================================================================"<<endl;
    cout<<"Koniec programu"<<endl;
    cout<<"Kod informacyjny: ";
    for (int i=0; i<n; i++)
    {
        cout<<kod_informacyjny[i];
    }
    cout<<endl;
    return 0;
}

// ===================================================================================
// ===================================================================================
// ===================================================================================
// ===================================================================================
// ===================================================================================

void obliczenia (int stopnie, int minuty, int sekundy, string polkula, int wybor, int stopnie_zen, int minuty_zen, int sekundy_zen, string polkula_zen)
{
    if (wybor==1)
    {
        if (polkula=="N")
        {
            wynik_stopnie=90-stopnie+23;
            wynik_minuty=minuty+26;
        }

        if (polkula=="S")
        {
            wynik_stopnie=90-stopnie-23;
            wynik_minuty=minuty-26;
        }
    }

    if (wybor==2)
    {
        if (polkula=="S")
        {
            wynik_stopnie=90-stopnie+23;
            wynik_minuty=minuty+26;
        }

        if (polkula=="N")
        {
            wynik_stopnie=90-stopnie-23;
            wynik_minuty=minuty-26;
        }
    }

    if (wybor==3)
    {
        wynik_stopnie=90-stopnie;
    }

    if (wybor==4)
    {
        if (polkula==polkula_zen)
        {
            wynik_stopnie=90-stopnie+stopnie_zen;
            wynik_minuty=minuty+minuty_zen;
            wynik_sekundy=sekundy+sekundy_zen;
        }

        if (polkula!=polkula_zen)
        {
            wynik_stopnie=90-stopnie-stopnie_zen;
            wynik_minuty=minuty-minuty_zen;
            wynik_sekundy=sekundy-sekundy_zen;
        }
    }
}

// ===================================================================================
// ===================================================================================

void regulacja_wynikow (int &wynik_stopnie, int &wynik_minuty, int &wynik_sekundy)
{
    if (wynik_stopnie>90)
    {
        wynik_stopnie=180-(wynik_stopnie);
        kod_informacyjny[0]="p";
    }

    while (wynik_sekundy<0)
    {
        wynik_sekundy+=60;
        wynik_minuty-=1;
    }

    while (wynik_minuty<0)
    {
        wynik_minuty+=60;
        wynik_stopnie-=1;
    }
}

// ===================================================================================
// ===================================================================================

void poprawnosc_stopnie_minuty_sekundy (int stopnie, int minuty, int sekundy, int wybor, int stopnie_zen, int minuty_zen, int sekundy_zen)
{
    if (stopnie>90)
    {
        cout<<"\n\nBLAD!\n";
        cout<<"Ilosc stopni szerokosci geograficznej nie moze wynosic wiecej nie 90 stopni!";
        cout<<"\nZresetuj program i wprowadz POPRAWNE dane\n\n";
        blad=true;
    }

    if (minuty>=60)
    {
        cout<<"\n\nBLAD!\n";
        cout<<"Ilosc minut nie moze wynosic wiecej nie 60 stopni!";
        cout<<"\nZresetuj program i wprowadz POPRAWNE dane\n\n";
        blad=true;
    }

    if (sekundy>=60)
    {
        cout<<"\n\nBLAD!\n";
        cout<<"Ilosc minut nie moze wynosic wiecej nie 60 stopni!";
        cout<<"\nZresetuj program i wprowadz POPRAWNE dane\n\n";
        blad=true;
    }

// ---------------------------------------------------------------------------

    if (stopnie_zen>90)
    {
        cout<<"\n\nBLAD!\n";
        cout<<"Ilosc stopni szerokosci geograficznej nie moze wynosic wiecej nie 90 stopni!";
        cout<<"\nZresetuj program i wprowadz POPRAWNE dane\n\n";
        blad=true;
    }

    if (minuty_zen>=60)
    {
        cout<<"\n\nBLAD!\n";
        cout<<"Ilosc minut nie moze wynosic wiecej nie 60 stopni!";
        cout<<"\nZresetuj program i wprowadz POPRAWNE dane\n\n";
        blad=true;
    }

    if (sekundy_zen>=60)
    {
        cout<<"\n\nBLAD!\n";
        cout<<"Ilosc minut nie moze wynosic wiecej nie 60 stopni!";
        cout<<"\nZresetuj program i wprowadz POPRAWNE dane\n\n";
        blad=true;
    }
}

// ===================================================================================
// ===================================================================================

void poprawnosc_wybor (int wybor)
{
    if (wybor<=0 || wybor>4)
    {
        cout<<"\n\nBLAD!\n";
        cout<<"Nie ma takiej opcji w menu!";
        cout<<"\nZresetuj program i wprowadz POPRAWNE dane\n\n";
        blad=true;
    }
}

// ===================================================================================
// ===================================================================================

void poprawnosc_polkule (string polkula)
{
    if (polkula!="N" && polkula!="S")
    {
        cout<<"\n\nBLAD!\n";
        cout<<"Mozliwe polkule to N lub S! W szerokosci geograficznej nie ma innych!";
        cout<<"\nZresetuj program i wprowadz POPRAWNE dane\n\n";
        blad=true;
    }
}

// ===================================================================================
// ===================================================================================

void poprawnosc_polkule_zen(string polkula_zen)
{
    if (polkula_zen!="N" && polkula_zen!="S")
    {
        cout<<"\n\nBLAD!\n";
        cout<<"Mozliwe polkule to N lub S! W szerokosci geograficznej nie ma innych!";
        cout<<"\nZresetuj program i wprowadz POPRAWNE dane\n\n";
        blad=true;
    }
}

// ===================================================================================
// ===================================================================================

void noc_polarna (int wynik_stopnie, int wynik_minuty, int wynik_sekundy)
{
    if ((wynik_stopnie<0) || (wynik_stopnie==0 && wynik_minuty<0) || (wynik_stopnie==0 && wynik_minuty==0 && wynik_sekundy<0))
    {
        cout<<endl<<endl<<"Panuje tutaj noc polarna!";
    }
}
