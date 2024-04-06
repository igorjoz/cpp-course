#include <iostream>

using namespace std;

int i, suma;

int main()
{
    i=1;

    while (i<=100)
    {
        i++;
        if (i%5==0) suma=suma+i;
    }
    cout<<"Suma liczb podzielnych przez 5 z przedialu od 1 do 100 wynosi: "<<suma<<"\n\n";

    return 0;
}
