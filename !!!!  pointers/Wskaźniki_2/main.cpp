#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int ile;
clock_t start, stop;

double czas;

int main()
{
    cout<<"Ile liczb w tablicy: ";
    cin>>ile;

    cout<<endl<<endl;

    int *tablica;
    tablica=new int [ile];

    start=clock();

    for (int i=0; i<ile; i++)
    {
        tablica[i]=i;
        tablica[i]+=50;
    }

    stop=clock();

    czas=(double)(stop-start) / CLOCKS_PER_SEC;
    cout<<"Czas zapisu bez wskaznika: "<<czas;

    delete [] tablica;

// ===============================================================================

    int *wskaznik;
    wskaznik=new int [ile];

    start=clock();

    for (int i=0; i<ile; i++)
    {
        *wskaznik=i;
        *wskaznik+=50;
        wskaznik++;
    }

    stop=clock();

    czas=(double) (stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<endl<<"Czas zapisu ze wskaznikiem: "<<czas;

    cout<<endl;
    return 0;
}
