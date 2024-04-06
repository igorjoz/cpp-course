#include <iostream>
#include <fstream>
#include <cstdlib>

#include "pytanie.h"

using namespace std;

void Pytanie::wczytaj()
{
    fstream plik;

    plik.open("quiz.txt", ios::in);

    if (plik.good() == false)
    {
        cout<<"Problem z otworzeniem pliku!";
        exit(0);
    }

    int nr_linii = (nr_pytania-1)*6+1;
    int aktualny_nr = 1;
    string linia;

    while(getline(plik,linia))
    {
        if(aktualny_nr==nr_linii)
            tresc=linia;
        if(aktualny_nr==nr_linii+1)
            a=linia;
        if(aktualny_nr==nr_linii+2)
            b=linia;
        if(aktualny_nr==nr_linii+3)
            c=linia;
        if(aktualny_nr==nr_linii+4)
            d=linia;
        if(aktualny_nr==nr_linii+5)
            poprawna=linia;
        aktualny_nr++;
    }

    plik.close();
}

void Pytanie::zadaj()
{
    cout<<endl<<nr_pytania<<". "<<tresc<<endl;
    cout<<"a) "<<a<<endl;
    cout<<"b) "<<b<<endl;
    cout<<"c) "<<c<<endl;
    cout<<"d) "<<d<<endl;

    cout<<"------------------";
    cout<<endl<<"Odpowiedz: ";
    cin>>odpowiedz;
}

void Pytanie::sprawdz()
{
    if (odpowiedz==poprawna)
    {
        punkt=1;
        cout<<"Dobrze! Zdobywasz punkt";
    }
    else
    {
        punkt=0;
        cout<<"Bledna odpowiedz";
    }
    cout<<endl;
}
