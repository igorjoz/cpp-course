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
    int tab3[n];

    // Zalaczenie generatora liczb pseudolosowych
    srand((unsigned)time(NULL));

    // Wylosowanie liczb do tab1
    for (int i=0; i<n; i++)
    {
        tab1[i] = rand()%50+1;
    }

    // Wylosowanie liczb do tab2
    for (int i=0; i<n; i++)
    {
        tab2[i] = rand()%50+1;
    }

    // Wypisanie zawartosci tablic
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

    // Wyliczenie wartosci elementow tab3
    for (int i=0; i<n; i++)
    {
        tab3[i] = tab1[i] + tab2[i];
    }

    // Wypisanie tab3
    cout<<endl<<"tab3 (suma tab1 i tab2):"<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<tab3[i]<<endl;
    }

    // Wybranie najwiekszej liczby sposrod konkretnego i-tego miejsca w tabeli sposrod tab1 i tab2
    for (int i=0; i<n; i++)
    {
        if (tab1[i]>=tab2[i]) // Znak "wieksze rowne", bo nie ma znaczenia jaka liczbe wybierzemy, kazda (i z tab1 i z tab2) jest tak samo duza
        {
            tab3[i]=tab1[i];
        }

        if (tab1[i]<tab2[i])
        {
            tab3[i]=tab2[i];
        }
    }

    // Wypisanie wyniku; tab3
    cout<<endl<<"tab3, wybranie najwiekszej liczby:"<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<tab3[i]<<endl;
    }

    return 0;
}
