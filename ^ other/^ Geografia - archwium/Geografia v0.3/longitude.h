#ifndef __Longitude__H__
#define __Longitude__H__

#include <iostream>

using namespace std;

class Longitude
{
private:
    int lok_A_stopnie, lok_B_stopnie;   // Zmienne stopni (polozenie geograficzne - dlugosc geograficzna)   (1. i 2. wybor)
    int lok_A_minuty, lok_B_minuty;     // Zmienne minut (polozenie geograficzne - dlugosc geograficzna)    (1. i 2. wybor)
    string polkula_A, polkula_B;        // Zmienne polkuli na jakiej znajduja sie punkty A i B

    int godzina_B, minuta_B, sekunda_B; // Zmienne potrzebne do okreslenia czasu w punkcie B                (2. wybor)

    bool czy_kolejny_dzien, czy_poprzedni_dzien; // Zmienne potrzebne do sprawdzenia prawdziwosci przesuniecia sie daty o jeden dzien do przodu

public:
    void get_data();
};

#endif
