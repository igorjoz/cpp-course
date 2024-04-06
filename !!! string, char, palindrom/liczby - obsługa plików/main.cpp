#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    fstream plik;
    int liczby[5];
    int i=0;

    plik.open("dane.txt", ios::in);

    if (plik.good())
    {
        while (!plik.eof())
        {
            plik>>liczby[i];
            cout<<liczby[i]<<" ";
            i++;
        }
    }
    else
    {
        cout<<"Problem z plikiem";
    }

    int *it = find(liczby, liczby + 5, 2);
    cout<<"element przed 2 to "<<*( it - 1 )<<endl;

    plik.close();
    return 0;
}
