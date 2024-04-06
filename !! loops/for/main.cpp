#include <iostream>

using namespace std;

int i, suma;

int main()
{
    for (i=1; i<=100; i++)
    {
        if (i%3==0) suma=suma+i;
    }
    cout<<"Suma liczb podzielnych przez 3 w zbiorze liczb od 1 do 100 wynosi: "<<suma;

    return 0;
}
