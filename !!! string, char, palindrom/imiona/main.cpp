#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    string imie[5];
    fstream plik;
    int i = 0;

    plik.open("imiona.txt", ios::in);

    if (plik.good())
    {
        while (!plik.eof())
        {
            plik>>imie[i];
            cout<<imie[i]<<" ";
            i++;
        }
        cout<<endl;
    }
    else
    {
        cout<<"Problem z plikiem";
    }

    plik.close();

    //string imie[5] = {"Igor", "Wiktor", "Marzena", "Jaroslaw", "Mak"};
    string poszukiwany = "or";

    for (int i=0; i<5; i++)
    {
        size_t znalezione = imie[i].find(poszukiwany);
        if (znalezione!=string::npos)
        {
            cout<<"Znaleziono \"go\" w: "<<znalezione<<". znaku wyrazu"<<"; w "<<i+1<<" imieniu"<<endl;
        }
    }

    cout<<endl;
    return 0;
}
