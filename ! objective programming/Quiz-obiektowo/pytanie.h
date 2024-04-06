#include <iostream>

using namespace std;

class Pytanie
{
public:
    int numer;
    string tresc;
    string a,b,c,d;
    string poprawna;
    string odpowiedz;
    int punkt; // Przyznawane bedzie 1 lub 0
    int nr_pytania;

    void wczytaj(); // Wczytanie tresci jednego pytania
    void zadaj(); // Zadanie pytania uzytkownikowi
    void sprawdz(); // Sprawdza poprawnosc wprowadzonej odpowiedzi
};
