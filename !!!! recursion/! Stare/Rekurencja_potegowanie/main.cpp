#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

int podstawa;
int wykladnik;

long long potegowanie_rekurencja (int podstawa, int wykladnik)
{
    if (wykladnik==0) return 1;
    else
    {
        return podstawa * potegowanie_rekurencja (podstawa, wykladnik-1);
    }
}

long long potegowanie_petla (int podstawa, int wykladnik);

int main()
{
    cout<<"Podaj podstawe potegi: ";
    cin>>podstawa;

    cout<<"Podaj wykladnik potegi: ";
    cin>>wykladnik;

    cout<<endl<<endl;

    cout<<"Wynik potegowania potegi o podstawie "<<podstawa<<" i wykladniku "<<wykladnik<<" wynosi: ";
    cout<<potegowanie_rekurencja (podstawa, wykladnik);
    //cout<<potegowanie_petla(podstawa, wykladnik);

    cout<<endl<<endl;
    return 0;
}

long long potegowanie_petla (int podstawa, int wykladnik)
{
    long long wynik;

    if (wykladnik==0) wynik=1;
    else if (wykladnik<0)
    {
        cout<<"Program jeszcze nie obsluguje ujemnego wykladnika!"<<endl;
        cout<<"Zaraz nastapi zamkniecie programu!";
        Sleep(4000);
        exit(0);

    }
    else wynik=podstawa;

    for (int i=1; i<wykladnik; i++)
    {
        wynik*=podstawa;
    }
    return wynik;
}
