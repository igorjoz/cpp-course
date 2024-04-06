#include <iostream>
#include <iomanip>

using namespace std;

int n, m, i, j, v1, v2;
char ** A;

int main()
{
    cout<<"Podaj liczbe wierzcholkow: ";
    cin>>n;

    cout<<"Podaj liczbe krawedzi: ";
    cin>>m;

    A=new char * [n];

    for (i=0; i<n; i++)
    {
        A[i]=new char [n]; //Tworzenie wierszy
    }

    //Wypelnienie macierzy zerami
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            A[i][j]=0;
        }
    }

    cout<<endl;

    //Odczytanie kolejnych krawedzi
    for (i=0; i<m; i++)
    {
        //Pobranie wierzcholka startowego krawedzi
        cout<<i+1<<". krawedz:\n";
        cout<<"Podaj 1. wierzcholek: ";
        cin>>v1;

        //Pobranie wierzcholka koncowego krawedzi
        cout<<"Podaj 2. wierzcholek: ";
        cin>>v2;

        A[v1][v2]=1; //Krawedz v1->v2
        A[v2][v1]=1; //Krawedz v1<-v2 (bo ma byc graf nieskierownany)

        cout<<endl;
    }

    cout<<endl;

    //Wypisanie zawartosci macierzy
    cout<<"   ";
    for (i=0; i<n; i++) cout<<setw(3)<<i;
    cout<<endl<<endl;

    for (i=0; i<n; i++)
    {
        cout<<setw(3)<<i;
        for (j=0; j<n; j++) cout<<setw(3)<<(int) A[i][j];
        cout<<endl;
    }

    //Usuniecie macierzy
    for (i=0; i<n; i++) delete [] A[i];
    delete [] A;
    cout<<endl;

    return 0;
}
