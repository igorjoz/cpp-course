/* Przedzialy, sumowanie, generator */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stddef.h>

using namespace std;

int najmniejsza, najwieksza, i, suma;

int main()
{
srand((unsigned)time(NULL));
najmniejsza=rand()%100;
najwieksza=najmniejsza+rand()%100;
cout<<"Program losujacy zbior liczb";
cout<<"\nWylosowany zbior to: najmniejsza = " << najmniejsza<<" najwieksza = " <<najwieksza<<"\n\n";

for(i=najmniejsza; i<=najwieksza; i++)
{
    suma=suma+i;
}

cout<<"Suma liczb z tego wylosowanego przedzialu wynosi: "<<suma<<"\n\n";

    return 0;
}
