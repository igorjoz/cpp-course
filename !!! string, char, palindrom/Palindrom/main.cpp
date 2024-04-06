#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

string napis_bez_znakow;

void wytnij_znaki(string napis)
{
    transform(napis.begin(), napis.end(), napis.begin(), ::tolower);

    int dlugosc = napis.length();

    cout<<"\nDlugosc napisu to: "<<dlugosc;

    for (int i=0; i<dlugosc; i++)
    {
        dlugosc = napis.length();
        if (napis[i] < 'a' || napis[i] > 'z')
        {
            napis.erase(i,1);
            i--;
        }
    }
    napis_bez_znakow = napis;
}

int main()
{
    string napis;
    int dlugosc;
    bool palindrom = true;

    cout<<"Podaj zdanie: ";
    getline(cin, napis);

    wytnij_znaki(napis);

    dlugosc = napis_bez_znakow.length();

    for (int i=0; i<ceil(dlugosc/2); i++)
    {
        if (napis_bez_znakow[i] != napis_bez_znakow[dlugosc-1-i])
        {
            palindrom = false;
        }
    }

    cout<<endl<<"Napis: \""<<napis<<"\" ";

    if (palindrom)
    {
         cout<<"JEST palindromem";
    }
    else
    {
        cout<<"NIE jest palindromem";
    }
    cout<<endl<<endl<<"*pomijajac znaki inne od liter oraz wielkosc liter";

    cout<<endl;
    return 0;
}
