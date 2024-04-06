#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

int ilosc, ilosc_kopia;

int main()
{
    ilosc=15; // Wartosc zmiennej ilosc musi byc rowna ilosci linijek w pliku "dane.txt"
    cout<<"Ilosc liczb wynosi: "<<ilosc;

    ilosc_kopia=ilosc;
    int liczby[ilosc]; // Tablica

    cout<<endl;

    string tresc[ilosc];

    fstream dane;

    dane.open("dane.txt", ios::in);

    // Pobranie liczb z pliku "dane.txt"
    if (dane.good()==false)
    {
        cout<<"Blad przy otwieraniu pliku!";
        exit(0);
    }

    string linia;
    int numer_linii=1;

    int c=0;

    while (!dane.eof())
    {
        getline(dane, linia);
        tresc[c]=linia;

        istringstream iss(tresc[c]);
        iss>>liczby[c];
        cout<<". "<<liczby[c]<<endl;

        c++;
    }

    // Wypisanie zawartosci nieposortowanej tablicy
    cout<<"Nieposortowana:"<<endl;
    for (int i=0; i<ilosc; i++)
    {
        cout<<liczby[i]<<endl;
    }

    cout<<endl;

    // Sortowanie tablicy babelkowo
    for (int i=0; i<ilosc; i++)
    {
        for (int k=1; k<ilosc_kopia-i; k++)
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

    // Zapis do pliku "posortowane.txt"
    fstream posortowane;

    posortowane.open("posortowane.txt", ios::out);

    if (posortowane.good()==false)
    {
        cout<<"Blad przy otwieraniu pliku!";
        exit(0);
    }
    else
    {
       for (int i=0; i<ilosc; i++)
       {
           posortowane<<liczby[i]<<endl;
       }
    }

    posortowane.close();

    cout<<endl<<endl;
    return 0;
}
