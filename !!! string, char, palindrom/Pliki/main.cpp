#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    fstream plik;
    string *linia;
    string test;
    int i=0;
    int ilosc_linii=0;


    plik.open("dane.txt", ios::in);

    if (plik.good())
    {
        while (!plik.eof())
        {
            getline (plik, test);
            ilosc_linii++;
        }
        cout<<"Ilosc linii: "<<ilosc_linii<<endl<<endl;

        plik.seekg(0); //Ustawienie pozycji odczytu danych na poczatek
        linia = new string [ilosc_linii];

        while (!plik.eof())
        {
            getline(plik, linia[i]);
            cout<<linia[i]<<endl;
            i++;
        }
    }
    else
    {
        cout<<"Problem z otworzeniem pliku!";
    }
    plik.close();

    string do_znalezienia;
    cout<<endl<<"Wprowadz fraze do znalezienia (imie / nazwisko / imie i nazwisko): ";
    getline(cin, do_znalezienia);

    bool czy_znaleziono=false;

    for (int k=0; k<ilosc_linii; k++)
    {
        size_t znalezione = linia[k].find(do_znalezienia);

        if(znalezione!=string::npos) //jesli znaleziono frazê "ma"
        {
            cout<<endl<<"Znaleziono tekst \""<<do_znalezienia<<"\" na pozycji: "<<znalezione;
            cout<<"; w "<<k+1<<" lini"<<endl;
            czy_znaleziono=true;
        }
    }

    if (czy_znaleziono=false)
    {
        cout<<"Nie znaleziono";
    }

    cout<<endl;
    return 0;
}
