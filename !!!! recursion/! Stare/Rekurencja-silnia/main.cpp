#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int liczba;

clock_t start1, stop1, start2, stop2;
float czas1, czas2;

long long silnia (int liczba)
{
    if (liczba==0) return 1;
    else return liczba * silnia(liczba-1);
}

long long silnia_petla (int liczba);

int main()
{
    cout<<"Podaj liczbe: ";
    cin>>liczba;

    start1=clock();

    cout<<endl<<endl<<"(REKURENCJA) "<<liczba<<"! = ";
    cout<<silnia(liczba);

    stop1=clock();
    czas1=(double) (stop1-start1) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas (1) wykonania: "<<czas1;

// ======================================================

    start2=clock();

    cout<<endl<<endl<<"(PETLA)      "<<liczba<<"! = " <<silnia_petla (liczba);

    stop2=clock();
    czas2=(double) (stop2-start2) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas (2) wykonania: "<<czas2;

    cout<<endl<<endl;
    return 0;
}

long long silnia_petla (int liczba)
{
    long long wynik=1;

    for (int i=1; i<=liczba; i++)
    {
        wynik*=i;
    }

    return wynik;
}
