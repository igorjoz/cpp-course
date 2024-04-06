#include <iostream>
#include <iomanip>

/* SKIEROWANY - PETLE, IZOLOWANE, DWUKIERUNKOWE */

using namespace std;

int n, m, i, j, v1, v2;
char ** A;

int main()
{
    cout<<"Podaj liczbe wierzcholkow: ";
    cin>>n;

    cout<<"Podaj liczbe krawedzi: ";
    cin>>m;

    int petle[n];
    int izolowane[n];
    int dwukierunkowe_a[n];
    int dwukierunkowe_b[n];

    // Wyczyszczenie wartosci izolowanych (domyslnie, przed wprowadzeniem danych wierzcholek nie ma krawedzi)
    for (int k=0; k<n; k++)
    {
        izolowane[k]=1;
    }

    A = new char * [n];

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

        if (v1==v2)
        {
            petle[v1]=1;
        }

        cout<<endl;

        A[v1][v2]=1; // Krawedz v1->v2 obecna
    }

    cout<<endl;

    // Wypisanie zawartosci macierzy
    cout<<"   ";
    for (i=0; i<n; i++)
    {
        cout<<setw(3)<<i;
    }

    cout<<endl<<endl;

    int z=0; // Zmienna do segregacji krawedzi dwukierunkowych

    for (i=0; i<n; i++)
    {
        cout<<setw(3)<<i;

        for (j=0; j<n; j++)
        {
            cout<<setw(3)<<(int) A[i][j];

            if (A[i][j]==1 && A[j][i]==1)
            {
                dwukierunkowe_a[z]=i;
                dwukierunkowe_b[z]=j;
                z++;
            }
        }
        cout<<endl;
    }

    // Izolowane - zlokalizowanie
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (A[i][j]==1)
            {
                izolowane[i]=0;
            }

            if (A[j][i]==1)
            {
                izolowane[i]=0;
            }
        }
    }

    cout<<endl<<endl;

    // Wypisanie krawedzi dwukierunkowych
    cout<<"Krawedzie dwukierunkowe:"<<endl;
    for (i=0; i<z; i++)
    {
        cout<<dwukierunkowe_a[i]<<"<-->"<<dwukierunkowe_b[i]<<endl;
        if (dwukierunkowe_a!=dwukierunkowe_b)
        {
            i++;
        }
    }

    // Wypisanie petli
    cout<<endl<<"Petle: ";
    for (i=0; i<n; i++)
    {
        if (petle[i]==1)
        {
            cout<<i<<"; ";
        }
    }

    // Wypisanie izolowanych wierzcholkow
    cout<<endl<<endl<<"Izolowane: ";
    for (i=0; i<n; i++)
    {
        if (izolowane[i]==1)
        {
            cout<<i<<"; ";
        }
    }

    // Usuniecie macierzy
    for (i=0; i<n; i++)
        delete [] A[i];
    delete [] A;

    cout<<endl<<endl;
    return 0;
}
