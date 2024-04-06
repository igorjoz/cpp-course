#include <iostream>

using namespace std;

int i, suma;

int main()
{
    i=1;
    do
    {
        i++;
        if (i%32==0) suma=suma+i;
    }while(i<=100);

    cout<<"Suma liczb podzielnych przez 32 z przedzialu od 1 do 100 wynosi: "<<suma<<"\n\n";

    return 0;
}
