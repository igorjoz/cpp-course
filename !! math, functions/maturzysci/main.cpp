#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <cmath>

using namespace std;

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

void wypisz_powoli(string wyraz, int czas)
{
    for (int i=0; i<wyraz.length(); i++)
    {
        cout<<wyraz[i];
        if (wyraz[i] == ' ')
            Sleep(300);
        else
            Sleep(czas);
    }
}

void wyczysc()
{
    Sleep(3500);
    SetConsoleTextAttribute(hOut, 7);
    system("CLS");
}

int main()
{
    int const czek = 3500;
    SetConsoleTextAttribute(hOut, 112);

    wypisz_powoli("Drogi MATURZYSTO! ..",180);
    wyczysc();

    SetConsoleTextAttribute(hOut, 112);
    wypisz_powoli("O ile zdajesz mature z informatyki, to pamietaj o: \n", 120);
    SetConsoleTextAttribute(hOut, 31);
    wypisz_powoli("typach zmiennych (np. int, float, bool, string, char), \ninstrukcji warunkowej if, \npetlach i iteracji, \ntablicach, \nfunkcjach, \nrekurencji, \nwskaznikach (& - pobranie adresu, * - wyciagniecie wartosci ze wskaznika), \nobsludze plikow, \nanalizie algorytmu, \nzlozonosci czasowej, \nvector <vector> - przydatnym zbiorniku, \nwaznych instrukcjach - wyraz.length() <string>, getline(plik, linia) <string>, plik.open(dane.txt, ios:in) <fstream>, abs(liczba_calkowita) i fabs(liczba_zmiennoprzecinkowa) <cmath>, round(liczba) <cmath>", 75);
    wyczysc();

    SetConsoleTextAttribute(hOut, 112);
    wypisz_powoli("Z Excela na pewno Ci sie przyda: \n", 120);
    SetConsoleTextAttribute(hOut, 47);
    wypisz_powoli("adresowanie wzgledne i bezwzgledne, \nJEZELI(), \nORAZ() I LUB(), \nMAX() i MIN(), \nSUMA(), \nLICZ.JEZELI() i LICZ.WARUNKI(), \nZAOKR(), \nDZIEN(), MIESIAC(), ROK(), \nLICZ.JEZELI() i LICZ.WARUNKI(), \nSREDNIA(), \nWYSZUKAJ.PIONOWO(), \ntworzenie wykresow, \nimportowanie danych z pliku tekstowego", 75);
    wyczysc();

    SetConsoleTextAttribute(hOut, 112);
    wypisz_powoli("Bazy danych - SQL i ACCESS tez pewnie nie sa Ci straszne, wiec na pewno wiesz, co to: \n", 130);
    SetConsoleTextAttribute(hOut, 160);
    wypisz_powoli("tabela, \nrekord, \npole, \nklucz podstawowy i obcy, \nkwerendy wyszukujace - SELECT (ALL/DISTINCT, TOP 1 (WITH TIES)), FROM; ODRER BY (ASC/DESC/NEWID()), BETWEEN, LIKE, WHERE, \nwazne funkcje systemowe - ROUND(), CAST(), \nfunkcje daty i czasu - DAY(), MONTH(), YEAR(), GATDATE(), \noperatory logiczne AND, OR, NOT, \nCASE WHEN ... THEN END, \nzlaczenia - JOIN ... ON, LEFT/RIGTH OUTER JOIN, CROSS JOIN i UNION, \nGROUP BY (... HAVING) oraz funkcje grupujace: COUNT(), SUM(), AVG(), MIN(), MAX()", 75);
    wyczysc();

    SetConsoleTextAttribute(hOut, 112);
    wypisz_powoli("Wiedz do czego sie uzywa HTML i CSS; rozrozniaj Java Script od PHP", 100);
    wyczysc();

    int liczba, pom=0, k=0, suma=0;
    SetConsoleTextAttribute(hOut, 7);
    wypisz_powoli("A czy znasz sposob na zamiane liczby z systemu dziesietnego na binarny?   \nPodaj mi jakas liczbe: ", 120);
    SetConsoleTextAttribute(hOut, 64);
    cin>>liczba;
    SetConsoleTextAttribute(hOut, 7);
    wypisz_powoli("wypisujemy kolejne potegi dwojki\n", 120);
    while(liczba > pom)
    {
        pom = pow(2,k);
        cout<<pom<<"\t";
        k++;
        Sleep(1000);
    }
    k-=1;
    int const ile = k;
    int m=k;
    wypisz_powoli("\na teraz odwracamy\n",150);
    string wynik[ile+1];
    for (m; m>=0; m--)
    {
        cout<<pow(2,m)<<"\t";
        Sleep(400);
    }
    cout<<endl;
    wypisz_powoli("i sprawdzamy, co sie zmiesci w sumie - nasza liczba to ", 120);
    SetConsoleTextAttribute(hOut, 64);
    cout<<liczba;
    SetConsoleTextAttribute(hOut, 7);
    wypisz_powoli(" ...\n", 500);
    int licznik=0;
    for (k; k>=0; k--)
    {
        if (pow(2,k) + suma > liczba)
        {
            cout<<"0\t";

            if (k!=ile)
            {
                wynik[licznik] = '0';
                licznik++;
            }
        }
        else if (pow(2,k) + suma <= liczba)
        {
            suma+=pow(2,k);
            cout<<"1\t";

            if (k!=ile)
            {
                wynik[licznik] = '1';
                licznik++;
            }
        }

        Sleep(1000);
    }

    wypisz_powoli("\nCzyli otrzymujemy: ", 120);
    for (int i=0; i<ile+1; i++)
    {
        cout<<wynik[i];
        Sleep(400);
    }
    Sleep(2000);
    wyczysc();

    wypisz_powoli("Mam nadzieje, ze wasza ciezka praca przyniesie w skutkach jak najlepsze wyniki na maturze i tego wam tez zycze.\nTo wszystko jest bardzo wazne, ale nie najwazniejsze :)\nNajwazniejsze jest czerpanie radosci z codziennosci --> tego zycze wam przede wszystkim!\nPamietajcie o tym\n\n", 120);
    Sleep(2000);
    wypisz_powoli("PS. Niedlugo 3 miesiace wakacji... wykorzystajcie ten czas jak najlepiej :D", 120);
    Sleep(2000);
    wyczysc();


    return 0;
}
