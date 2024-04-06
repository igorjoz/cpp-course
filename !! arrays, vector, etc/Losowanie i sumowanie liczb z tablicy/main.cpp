#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stddef.h>

using namespace std;

int liczby[101];
int i, suma;

int main()
{
    srand((unsigned)time(NULL));

    for (i=1; i<=100; i++)
    {
    liczby[i]=rand()%10;
    cout<<i<<". liczba: "<<liczby[i]<<"\n";
    suma+=liczby[i];
    }

    cout<<"\n\nSuma wylosowanych liczb wynosi: "<<suma;

    cout<<"\n\n";
    return 0;
}
