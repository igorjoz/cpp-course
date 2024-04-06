#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

clock_t start, stop;

void BubbleSort (int *liczby, int &ile, int wybor)
{
    int bufor = 0;

    switch (wybor)
    {
    case 1:
        for (int k=0; k<ile; k++)
        {
            for (int i=1; i<ile-k; i++)
            {
                if (liczby[i-1] < liczby[i])
                {
                    bufor = liczby[i];
                    liczby[i] = liczby[i-1];
                    liczby [i-1] = bufor;
                }
            }
        }
        break;

    case 2:
        for (int k=0; k<ile; k++)
        {
            for (int i=1; i<ile-k; i++)
            {
                if (liczby[i-1] > liczby[i])
                {
                    bufor = liczby[i];
                    liczby[i] = liczby[i-1];
                    liczby [i-1] = bufor;
                }
            }
        }
        break;
    }
}

int main()
{
    int *liczby;
    int ile;
    int wybor;

    srand((unsigned)time(NULL));

    cout<<"Sortowanie babelkowe"<<endl<<endl;

    cout<<"Podaj ile liczb chcesz wylosowac: ";
    cin>>ile;

    // Stworzenie tablicy
    liczby = new int [ile];

    // Losowanie liczb i wypisanie tablicy
    cout<<"Wylosowana tablica: "<<endl;
    for (int i=0; i<ile; i++)
    {
        liczby[i] = rand()%1000+1;
        cout<<i+1<<". "<<liczby[i]<<endl;
    }

    cout<<endl<<"Chcesz posortowac malejaco (1), czy rosnaco (2)?: ";
    cin>>wybor;

    cout<<endl<<"*Sortowanie*"<<endl;

    // Sortowanie
    start = clock();
    BubbleSort(liczby, ile, wybor);
    stop = clock();

    double czas = (double) (stop-start) / CLOCKS_PER_SEC;

    // Wypisanie posortowanej tablicy
    cout<<"Posortowana tablica:"<<endl;
    for (int i=0; i<ile; i++)
    {
        cout<<i+1<<". "<<liczby[i]<<endl;
    }

    delete [] liczby;

    cout<<"Czas sortowania babelkowego: "<<czas<<" s";

    cout<<endl<<endl;
    return 0;
}
