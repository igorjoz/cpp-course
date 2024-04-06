#include <iostream>
#include <iomanip>

using namespace std;

int n, m, i, j, v1, v2;
char ** A;

int main()
{
    /* Wierzcholki */
    cout<<"Podaj liczbe wierzcholkow: ";
    cin>>n;

    /* Krawedzie */
    cout<<"Podaj liczbe krawedzi: ";
    cin>>m;

    int sasiedzi_start[m];
    int sasiedzi_koniec[m];

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
        cout<<i+1<<". Krawedz:\n";
        cout<<"Podaj wierzcholek startowy: ";
        cin>>v1;

        //Pobranie wierzcholka koncowego krawedzi
        cout<<"Podaj wierzcholek koncowy: ";
        cin>>v2;

        A[v1][v2]=1; //Krawedz v1->v2 obecna

        sasiedzi_start[i]=v1;
        sasiedzi_koniec[i]=v2;

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

    cout<<endl<<endl;

    //Wypisanie po kolei wszystkich sasiadow
    for (i=0; i<m; i++)
    {
        cout<<"Wierzcholek: "<<sasiedzi_koniec[i]<<endl;
        cout<<"Jest sasiedem dla: "<<sasiedzi_start[i]<<endl<<endl;
    }

    //Usuniecie macierzy
    for (i=0; i<n; i++) delete [] A[i];
    delete [] A;
    cout<<endl;

    return 0;
}
