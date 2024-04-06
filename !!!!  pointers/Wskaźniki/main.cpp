#include <iostream>

using namespace std;

int main()
{
    int liczba=15;

    cout<<"Liczba: "<<liczba<<endl;

    int *w;
    w=&liczba;

    cout<<"Wskaznik liczby (jej adres) w systemie dziesietnym: "<<(int) w<<endl;
    cout<<"Wskaznik liczby (jej adres) w systemie szesnastkowym: "<< w<<endl;
    cout<<"Liczba o adresie ze wskaznika: "<< *w;


    /*
    int ile;

    cout<<"Ile liczb w tablicy: "<<endl;
    cin>>ile;

    cout<<endl<<endl;

    int*tablica;
    tablica=new int [ile];

    for (int i=0; i<ile; i++)
    {
        cout<<(int) tablica<<endl;
        tablica++;
    }

    delete [] tablica;
    */

    cout<<endl;
    return 0;
}
