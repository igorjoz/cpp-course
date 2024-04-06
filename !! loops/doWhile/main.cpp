#include <iostream>

using namespace std;

int czas, populacja;

int main()
{
    czas=0;
    populacja=1;

    do
    {
        czas++;
        populacja=populacja*2;
        cout<<"Czas = "<<czas<<" Populacja = "<<populacja<<"\n";

    } while (populacja<=1000000);


    return 0;
}
