#include <iostream>
#include <string>

using namespace std;

string kod;

void ta (string kod)
{
    int dlugosc = kod.length();
    string po_zmianie[dlugosc];

    // Przepisanie oryginalnego kodu do nowej zmiennej "po_zmianie"; Odejmuje 1, bo tablice sa numerowane od zera
    for (int i=0; i<=dlugosc-1; i++)
    {
        po_zmianie[i] = kod [i];
    }

    // Jesli litera w szufladce kod[i] nie jest litera 'A', to zmienia ten znak na gwiazdke
    for (int i=0; i<=dlugosc-1; i++)
    {
        if (kod[i]!='A')
        {
            po_zmianie[i]='*';
        }
    }

    // Wypisanie wyniku
    for (int i=0; i<=dlugosc-1; i++) cout<<po_zmianie[i];
}

int main()
{
    cout<<"Podaj kod: ";
    cin>>kod;

    cout<<endl<<"Napis po zmianie: ";
    ta(kod);

    return 0;
}
