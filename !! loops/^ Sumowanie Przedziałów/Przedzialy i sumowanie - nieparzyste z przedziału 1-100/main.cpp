/* Przedzialy i sumowanie - nieparzyste */

#include <iostream>

using namespace std;

int i, suma, liczba;

int main()
{
    cout<<"Program zliczajacy liczby nieprzyste\n\n";
    for(i=1; i<=100; i++) // i++ = inkrementacja (zwieksznie liczby o 1)
    {
        if (i%2!=0) suma=suma+i;
    }

    cout<<"Suma liczb nieparzystych z przedzialu od 1-100 wynosi: "<<suma<<"\n";

    return 0;
}
