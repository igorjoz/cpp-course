#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    int n;

    cout<<"n: ";
    cin>>n;

    int tab1[n];
    int tab2[n];

    // Zalaczenie generatora liczb pseudolosowych
    srand((unsigned)time(NULL));

    // Wylosowanie liczb do tab1
    for (int i=0; i<n; i++)
    {
        tab1[i] = rand()%50+1; // Nalezy dodac 1, bo inaczej wylosowane liczby bylyby z przedzialu od 0 do 49 (sytuacja podobna z tablicami - sa numerowane od 0)

        // Przepisanie tab1 do tab2
        tab2[i]=tab1[i];
    }

    cout<<endl<<"tab1:"<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<tab1[i]<<endl;
    }

    cout<<endl<<"tab2:"<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<tab2[i]<<endl;
    }

    // Przepisanie zawartosci tab1 do tab 2 w odwrotnej kolejnosci
    for (int i=0; i<n; i++)
    {
        tab2[i] = tab1[n-(i+1)]; // i + 1, bo tablice sa numerowane od 0
    }

    // Wypisanie zmienionej tab2
    cout<<endl<<endl<<"tab2, odwrotna kolejnosc:"<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<tab2[i]<<endl;
    }

    return 0;
}
