#include <iostream>

using namespace std;

int ile;

int *liczba;

void pobranie_liczb (int *liczba, int powtorzenia)
{
    for (int i=0; i<powtorzenia; i++)
    {
        cout<<"Podaj "<<i+1<<". "<<"liczbe: ";
        cin>>liczba[i];
    }
}

int main()
{
    cout<<"Ile liczb chcesz podac: ";
    cin>>ile;
    cout<<endl;

    liczba=new int [ile];

    pobranie_liczb (liczba, ile);

    cout<<endl;

    for (int i=0; i<ile; i++)
    {
        cout<<i+1<<". liczba: "<<liczba[i]<<endl;
    }

    delete [] liczba;

    cout<<endl<<endl;
    return 0;
}
