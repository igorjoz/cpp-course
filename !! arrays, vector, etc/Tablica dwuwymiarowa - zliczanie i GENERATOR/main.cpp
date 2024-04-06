#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stddef.h>

using namespace std;

int liczby[11][11];
int i, suma;
int k=0;

int main()
{
    srand((unsigned)time(NULL));

    for (k=1; k<=10; k++)
    {
    for (i=1; i<=10; i++)
    {
        liczby[i][k]=rand()%10;
        cout<<"Liczba w "<<i<<". kolumnnie i "<<k<<". wierszu : "<<liczby[i][k]<<".\n";
        suma+=liczby[i][k];
    }
    cout<<"\n";
    }

    cout<<"Suma wszystkich liczb wynosi: "<<suma;

    cout<<"\n\n";
    return 0;
}
