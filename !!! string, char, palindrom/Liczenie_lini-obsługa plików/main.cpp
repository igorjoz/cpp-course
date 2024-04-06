#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream plik;
    int counter=0;
    string linia;

    plik.open("dane.txt", ios::in);

    if (plik.good())
    {
        while (!plik.eof())
        {
            getline (plik, linia);
            counter++;
        }
    }
    else
    {
        cout<<"Problem z plikiem";
    }

    cout<<counter;

    return 0;
}
