#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>   //system("PAUSE) / system("CLS")

using namespace std;

int ile;

void wyswietl(int *tablica, string jaka, bool czy_wyczyscic)
{
    cout<<"Tablica "<<jaka<<":\n";
    for (int i=0; i<ile; i++)
    {
        cout<<tablica[i]<<"["<<i<<"]\t ";
    }
    cout<<"\n\n";

    if (czy_wyczyscic)
    {
        system("PAUSE");
        system("CLS");
    }
}

int main()
{
    int wstawienie[2], usuniecie, zamiana[2];
    int *tab, *tab_wstawienie, *tab_usuniecie, *tab_zamiana, *tab_odwrocenie;

    cout<<"Ile elementow w tablicy: ";
    cin>>ile; if (ile<=0) exit(0);

    tab = new int [ile];

    tab_wstawienie = new int [ile];
    tab_usuniecie = new int [ile];
    tab_zamiana = new int [ile];
    tab_odwrocenie = new int [ile];

    srand((unsigned)time(NULL));

    for (int i=0; i<ile; i++)
    {
        tab[i]=rand()%20+1;

        tab_wstawienie[i] = tab[i];
        tab_usuniecie[i] = tab[i];
        tab_zamiana[i] = tab[i];
        tab_odwrocenie[i] = tab[i];
    }

    wyswietl(tab, "pierwotna", 0);

    cout<<"\nJaka liczbe chcesz wstawic: ";
    cin>>wstawienie[0];
    cout<<"Gdzie (w ktora komorke tablicy) chcesz wstawic te liczbe: ";
    cin>>wstawienie[1]; if (wstawienie[1]<0 && wstawienie[1]>=ile) exit(0);

    for (int i=ile-1; i>=wstawienie[1]; i--)
    {
        tab_wstawienie[i]=tab_wstawienie[i-1];
    }
    tab_wstawienie[wstawienie[1]]=wstawienie[0];

    cout<<"\n\n";
    wyswietl(tab_wstawienie, "po wstawieniu", 1);
//-----------------------------------------------
    wyswietl(tab, "pierwotna", 0);

    cout<<"Ktory element chcesz usunac: ";
    cin>>usuniecie; if (usuniecie<0 && usuniecie>=ile) exit(0);

    for (int i=usuniecie; i<ile-1; i++)
    {
        tab_usuniecie[i]=tab_usuniecie[i+1];
    }
    tab_usuniecie[ile-1]=0;

    wyswietl(tab_usuniecie, "po usunieciu", 1);
//-----------------------------------------------
    wyswietl(tab, "pierwotna", 0);

    cout<<"Ktory element zamienic z ktorym?\n";
    cout<<"Pierwszy element: ";
    cin>>zamiana[0]; if (zamiana[0]<0 && zamiana[0]>=ile) exit(0);
    cout<<"Drugi element: ";
    cin>>zamiana[1]; if (zamiana[1]<0 && zamiana[1]>=ile) exit(0);

    int temp=tab_zamiana[zamiana[0]];
    tab_zamiana[zamiana[0]]=tab_zamiana[zamiana[1]];
    tab_zamiana[zamiana[1]]=temp;

    wyswietl(tab_zamiana, "po zamianie", 1);
//-----------------------------------------------
    wyswietl(tab, "pierwotna", 0);

    for (int i=1; i<=ile; i++)
    {
        tab_odwrocenie[i-1]=tab[ile-i];
    }

    wyswietl(tab_odwrocenie, "po odwroceniu", 0);

    return 0;
}
