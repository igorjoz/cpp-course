#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

string imie, nazwisko;
int numer_telefonu;

int main()
{
    cout<<"Program odczytujacy dane z pliku"<<endl<<endl;

    fstream plik;
    plik.open("dane.txt", ios::in); //in - wejscie

    if (plik.good()==false)
    {
        cout<<"Plik nie istnieje! Blad operacji.";
        exit(0);
    }

    string linia;
    int numer_linii=1;

    while(getline(plik, linia))
    {
        switch(numer_linii)
        {
            case 1: imie=linia; break;
            case 2: nazwisko=linia; break;
            case 3: numer_telefonu=atoi(linia.c_str()); break;
        }

        numer_linii++;
    }

    plik.close();

    cout<<imie<<endl;
    cout<<nazwisko<<endl;
    cout<<numer_telefonu<<endl;

    cout<<"\nUkonczono operacje\n\n";
    return 0;
}
