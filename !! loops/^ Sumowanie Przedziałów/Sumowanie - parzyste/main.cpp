#include <iostream>

using namespace std;

int suma, x, y, i;

int main()

{
    x=1;
    y=100;

    for(i=x; i<=y; i++)
    {
        if(i%2==0) suma=suma+i;
    }
    cout << "Suma wynosi: "<<suma;
    return 0;
}
