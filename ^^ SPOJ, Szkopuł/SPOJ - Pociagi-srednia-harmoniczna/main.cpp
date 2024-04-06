#include <iostream>

using namespace std;

int ilosc;

float *predkosc_start;
float *predkosc_powrot;

float *srednia;

void f_srednia (float *predkosc_start, float *predkosc_powrot, float *srednia , int ilosc)
{
    for (int i=0; i<ilosc; i++)
    {
        srednia[i] = 0; // Reset wartosci
        srednia[i] = 2 / ((1/predkosc_start[i]) + (1/predkosc_powrot[i])); //Obliczenie sredniej (srednia harmoniczna)
        cout<<srednia[i]<<endl; // Wypisanie wyniku na ekran
    }
}

int main()
{
    cin>>ilosc;

    predkosc_start = new float [ilosc];
    predkosc_powrot = new float [ilosc];

    srednia = new float [ilosc];

    // Pobranie informacji od uzytkownika
    for (int i=0; i<ilosc; i++)
    {
        cin>>predkosc_start[i]>>predkosc_powrot[i];
    }

    // Wypisanie wynikow
    f_srednia(predkosc_start, predkosc_powrot, srednia, ilosc);

    // Usuniecie niepotrzebych juz danych
    delete [] predkosc_start;
    delete [] predkosc_powrot;
    delete [] srednia;

    return 0;
}
