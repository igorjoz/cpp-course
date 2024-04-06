/* Przedzialy i sumowanie v2 */

#include <iostream>

using namespace std;

int i, suma, liczba;

int main()
{
    cout<<"Program zliczajacy liczby przyste\n\n";
    for(i=1; i<=100; i++) // i++ = inkrementacja (zwiêksznie liczby o 1)
    {
        if (i%2==0) suma=suma+i;
    }

    cout<<"Suma liczb parzystych z przedzialu od 1-100 wynosi: "<<suma<<"\n";

    return 0;
}
