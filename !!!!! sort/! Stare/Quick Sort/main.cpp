#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

clock_t start, stop;

void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while (tablica[i]<v)
            i++;
        while (tablica[j]>v)
            j--;
        if (i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if (j>lewy)
        quicksort(tablica,lewy, j);
    if (i<prawy)
        quicksort(tablica, i, prawy);
}

int main()
{
    int *tablica;
    long long int ile;

    srand((unsigned)time(NULL));\

    cout<<"Quick Sort"<<endl<<endl;

    cout<<"Ile liczb wylosowac: ";
    cin>>ile;

    tablica = new int [ile];

    /*
    cout<<"Wylosowana tablica:"<<endl;
    for (int i=0; i<ile; i++)
    {
        tablica[i] = rand()%1000+1;
        cout<<i+1<<". "<<tablica[i]<<endl;
    }
    */

    double czas;

    cout<<endl<<"*Sortowanie*"<<endl;

    start=clock();
    quicksort(tablica, 0, ile-1);
    stop=clock();

    /*
    cout<<"Posortowana tablica:"<<endl;
    for (int i=0; i<ile; i++)
    {
        cout<<i+1<<". "<<tablica[i]<<endl;
    }
    */

    czas = (double) (stop-start) / CLOCKS_PER_SEC;

    cout<<"Czas sortowania: "<<czas<<" s";

    cout<<endl<<endl;
    return 0;
}
