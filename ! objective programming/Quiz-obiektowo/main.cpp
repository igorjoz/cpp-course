#pragma once

#include <iostream>

#include "pytanie.h"

using namespace std;

int main()
{
    int suma=0;

    cout<<"Witaj w quizie"<<endl;

    Pytanie p[5];

    for (int i=0; i<5; i++)
    {
        p[i].nr_pytania=i+1;
        p[i].wczytaj();
        p[i].zadaj();
        p[i].sprawdz();

        suma+=p[i].punkt;
    }

    cout<<endl<<"Koniec quizu"<<endl<<"Punkty: "<<suma;

    return 0;
}
