#include <iostream>

using namespace std;

int ile;
float *liczby;

void srednia_arytmetyczna (int ile, float *liczby)
{
    float suma=0;

    for (int i=0; i<ile; i++)
    {
        suma+=liczby[i];
    }

    cout<<suma/ile;
}

int main()
{
    cout<<"Ile liczb do obliczenia sredniej arytmetycznej masz zamiar podac: ";
    cin>>ile;

    cout<<endl;

    liczby = new float [ile];

    for (int i=0; i<ile; i++)
    {
        cout<<i+1<<". liczba: ";
        cin>>liczby[i];
    }

    cout<<endl;

    cout<<"Srednia arytmetyczna: ";
    srednia_arytmetyczna (ile, liczby);

    delete [] liczby;

    cout<<endl<<endl;
    return 0;
}
