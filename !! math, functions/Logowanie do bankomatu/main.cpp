#include <iostream>

using namespace std;

string PINwpisany, PINpoprawny, imie, nazwisko;
int klient;

int main()
{
    cout << "Witaj w banku Hades\n\n";
    cout<<"Podaj swoje imie: ";
    cin>>imie;
    cout<<"\nPodaj swoje nazwisko: ";
    cin>>nazwisko;
    cout<<"\nPodaj swoj PIN: ";
    cin>>PINwpisany;
{

    if (imie=="Jan" || imie=="jan" || imie=="Janek" || imie=="janek" && nazwisko=="Walczak" || nazwisko=="walczak")
    {
        PINpoprawny = "0915";
    }
    if (imie=="Wojtek" || imie=="wojtek" || imie=="Wojciech" || imie=="wojciech" || imie=="ja" || imie=="Ja" || imie=="JA" && nazwisko=="Wiernicki" || nazwisko=="wiernicki" || imie=="ja" || imie=="Ja" || imie=="JA")
    {
        PINpoprawny = "5198";
    }
}

    if (PINwpisany==PINpoprawny)
    {
        cout<<"\nBrawo! Zalogowales sie!\n\n";
    }
    else cout<<"\nCos spartaczyles. Sprobuj sie zalogowac jeszcze raz\n\n";

    return 0;
}
