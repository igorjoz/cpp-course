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
    cout<<"Suma wynosi: "<<suma;

    return 0;
}
