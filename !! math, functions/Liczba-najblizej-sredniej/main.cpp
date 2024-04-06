#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cmath>

using namespace std;

float najblizsza;

float srednia (float pierwsza, float druga, float trzecia)
{
    return (pierwsza+druga+trzecia)/3;
}

void najblizej_sredniej (float pierwsza, float druga, float trzecia, float srednia)
{
    float roznica1 = abs (srednia - pierwsza);
    float roznica2 = abs (srednia - druga);
    float roznica3 = abs (srednia - trzecia);

    if (roznica1<roznica2 && roznica1<roznica3)
    {
        najblizsza=pierwsza;
    }

    if (roznica2<roznica1 && roznica2<roznica3)
    {
        najblizsza=druga;
    }

    if (roznica3<roznica1 && roznica3<roznica2)
    {
        najblizsza=trzecia;
    }

    if (roznica1==roznica2 && roznica1==roznica3)
    {
        najblizsza=-1;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    float liczba1=rand()%100+1;
    float liczba2=rand()%100+1;
    float liczba3=rand()%100+1;

    cout<<"Wylosowane liczby:"<<endl;
    cout<<"Liczba 1.: "<<liczba1<<endl;
    cout<<"Liczba 2.: "<<liczba2<<endl;
    cout<<"Liczba 3.: "<<liczba3<<endl<<endl;

    float srednia_wynik=srednia(liczba1, liczba2, liczba3);
    cout<<"Srednia: "<<srednia_wynik<<endl;

    najblizej_sredniej (liczba1, liczba2, liczba3, srednia_wynik);

    cout<<"Najblizej do sredniej jest liczba: ";
    if (najblizsza==-1)
    {
        cout<<liczba1<<" i "<<liczba2<<" i "<<liczba3<<" - sa tak samo bliskie sredniej";
    }
    if (najblizsza>=0)
    {
        cout<<najblizsza;
    }

    cout<<endl<<endl;
    return 0;
}
