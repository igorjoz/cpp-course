#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int n, wynik=0, *liczby;
    char dzialanie;

    ifstream plik;
    plik.open("dane.txt");

    if (plik.good())
    {
        plik>>n>>dzialanie;
        cout<<n<<" "<<dzialanie<<endl;

        liczby = new int [n];

        for(int i=0; i<n; i++)
        {
            plik>>liczby[i];
            if (dzialanie == '+')
            {
                wynik+=liczby[i];
            }
            cout<<liczby[i]<<" ";
        }
        cout<<endl<<endl<<"Wynik: "<<wynik;
    }
    else
    {
        cout<<"Problem z otworzeniem pliku";
    }
    plik.close();

    cout<<endl;
    return 0;
}
