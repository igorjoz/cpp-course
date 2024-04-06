#include <iostream>
#include <iomanip>

/* SKIEROWANY - ZLICZANIE STOPNIA WYCHODZACEGO I WCHODZACEGO */

using namespace std;

int n, m, i, j, v1, v2;
char ** A;

int main()
{
    cout<<"Podaj liczbe wierzcholkow: ";
    cin>>n;

    cout<<"Podaj liczbe krawedzi: ";
    cin>>m;

    int stopien_wychodzacy[n];
    int stopien_wchodzacy[n];

    A=new char * [n];

    // Tworzenie wierszy
    for (i=0; i<n; i++)
    {
        A[i]=new char [n];
    }

    // Wypelnienie macierzy zerami
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            A[i][j]=0;
        }
    }

    cout<<endl;

    // Zerowanie wartosci stopni
    for (i=0; i<n; i++)
    {
        stopien_wychodzacy[i]=0;
        stopien_wchodzacy[i]=0;
    }

    // Odczytanie kolejnych krawedzi
    for (i=0; i<m; i++)
    {
        // Pobranie wierzcholka startowego krawedzi
        cout<<i+1<<". Krawedz:\n";
        cout<<"Podaj wierzcholek startowy: ";
        cin>>v1;

        // Pobranie wierzcholka koncowego krawedzi
        cout<<"Podaj wierzcholek koncowy: ";
        cin>>v2;

        cout<<endl;

        A[v1][v2]=1; // Krawedz v1->v2 obecna
    }

    cout<<endl;

    // Wypisanie zawartosci macierzy oraz okreslenie wartosci stopnia wchodzacego i wychodzacego
    cout<<"   ";
    for (i=0; i<n; i++)
    {
        cout<<setw(3)<<i;
    }

    cout<<endl<<endl;

    for (i=0; i<n; i++)
    {
        cout<<setw(3)<<i;

        for (j=0; j<n; j++)
        {
            cout<<setw(3)<<(int) A[i][j];

            stopien_wychodzacy[i]+=(int) A[i][j];
            stopien_wchodzacy[i]+=(int) A[j][i];
        }
        cout<<endl;
    }

    cout<<endl<<endl;

    // Wypisanie stopnia wychodzacego
    cout<<"Stopien wychodzacy dla:"<<endl;
    for (i=0; i<n; i++)
    {
        cout<<i<<". wiersza to: "<<stopien_wychodzacy[i]<<endl;
    }

    // Wypisanie stopnia wchodzacego
    cout<<endl<<"Stopien wchodzacy:"<<endl;
    for (i=0; i<n; i++)
    {
        cout<<i<<". kolumny to: "<<stopien_wchodzacy[i]<<endl;
    }

    // Usuniecie macierzy
    for (i=0; i<n; i++) delete [] A[i];
    delete [] A;

    cout<<endl<<endl;
    return 0;
}
