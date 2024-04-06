#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

float stopnie;
float celsius, kelvin, fahrenheit;

void pobranie_stopni ()
{
    cout<<endl<<"Podaj stopnie: ";
    cin>>stopnie;
}

void celsius_na_kelvin (float celsius)
{
    kelvin = 273.15 + celsius;
}

void celsius_na_fahrenheit (float celsius)
{
    fahrenheit = 32 + 9/5 * celsius;
}

void kelvin_na_celsius (float kelvin)
{
    celsius = kelvin - 273.15;
}

void kelvin_na_fahrenheit (float kelvin)
{
    fahrenheit = (kelvin - 273.15) * 1.8000 + 32.00;
}

void fahrenheit_na_celsius (float fahrenheit)
{
    celsius = (fahrenheit - 32) / 1.8;
}

void fahrenheit_na_kelvin (float fahrenheit)
{
    kelvin = (fahrenheit + 459.67) * 5/9;
}

void wypisanie_wyniku (float celsius, float kelvin, float fahrenheit)
{
    cout<<endl<<endl<<"Wynik:"<<endl;
    cout<<"Celsius: \t"<<celsius<<endl;
    cout<<"Kelvin: \t"<<kelvin<<endl;
    cout<<"Fahrenheit: \t"<<fahrenheit;
}

int main()
{
    int wybor;

    cout<<"Program zamieniajacy skale temperatur"<<endl<<endl;

    cout<<"Podaj w jakiej skali podajesz:"<<endl;
    cout<<"1. Celsius"<<endl;
    cout<<"2. Kelvin"<<endl;
    cout<<"3. Fahrenheit"<<endl;
    cout<<"Wybor: ";
    cin>>wybor;

    switch (wybor)
    {
    case 1:
        pobranie_stopni ();
        celsius = stopnie;
        celsius_na_kelvin (celsius);
        celsius_na_fahrenheit (celsius);

        break;

    case 2:
        pobranie_stopni ();
        kelvin = stopnie;
        kelvin_na_celsius (kelvin);
        kelvin_na_fahrenheit (kelvin);

        break;

    case 3:
        pobranie_stopni ();
        fahrenheit = stopnie;
        fahrenheit_na_celsius (fahrenheit);
        fahrenheit_na_kelvin (fahrenheit);

        break;

    default:
        cout<<endl<<"Blednie wybrany numer opcji!"<<endl;
        cout<<"Zrestartuj program i wprowadz poprawne dane";
        Sleep (4000);
        exit(0);
    }

    wypisanie_wyniku (celsius, kelvin, fahrenheit);

    cout<<endl<<endl;
    return 0;
}
