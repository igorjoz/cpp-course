#pragma once

//------------------------------------------------------------------------------------------------------

using namespace std;

/*------------------------------------------------------------------------------------------------------
|                                                                                                      |
|                                          Funkcje                                                     |
|                                                                                                      |
------------------------------------------------------------------------------------------------------*/

// Odliczanie dla podanego czasu, wsywietla podany tekst, mozliwosc podwojnego endl
void resetCounting(int time, string text, bool doEndl);

// Sprawdzenie, czy kazdy znak lancucha jest liczba
bool isStringANumber(string str);

/*------------------------------------------------------------------------------------------------------
|                                                                                                      |
|                                          Longitude                                                   |
|                                                                                                      |
------------------------------------------------------------------------------------------------------*/

class Longitude
{
private:
    int locA_degrees, locB_degrees;     // Zmienne stopni (polozenie geograficzne - dlugosc geograficzna)   (1. i 2. wybor)
    int locA_minutes, locB_minutes;     // Zmienne minut (polozenie geograficzne - dlugosc geograficzna)    (1. i 2. wybor)
    int locA_seconds, locB_seconds;     // Zmienne minut (polozenie geograficzne - dlugosc geograficzna)    (1. i 2. wybor)
    string hemisphereA, hemisphereB;    // Zmienne polkuli na jakiej znajduja sie punkty A i B

    int hourB, minuteB, secondB;    // Zmienne potrzebne do okreslenia czasu w punkcie B                (2. wybor)
    bool isNextDay, isPreviousDay;  // Zmienne potrzebne do sprawdzenia prawdziwosci przesuniecia sie daty o jeden dzien do przodu

    //------------------------------------------------------------------------------------------------------

public:
    // Konstruktor
    Longitude(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, string = "brak danych", string = "brak danych", int = 0, int = 0, int = 0, bool = false, bool = false);

    //------------------------------------------------------------------------------------------------------

    // Pobranie dancyh
    void getData(char choice);


    // Pobranie i walidacja stopni, minut lub sekund
    void degreesMinSecValidation(int &what, string text, int type); // what --> do jakiej zmiennej ma zostac przypisana pobrana liczba; text --> co ma wyswietlic uzytkownikowi podczas pobierania danych; type --> 1 dla stopni (degrees), 2 dla minut i sekund - sluzy do okreslenia dozwolonego przedzialu liczby oraz tekstu do wyswietlenia podczas bledu

    // Pobranie i walidacja polkuli
    void hemisphereValidation(string &what, string text); // what --> do jakiej zmiennej ma zostac przypisana pobrana liczba; text --> co ma wyswietlic uzytkownikowi podczas pobierania danych;
};

/*------------------------------------------------------------------------------------------------------
|                                                                                                      |
|                                          Latitude                                                    |
|                                                                                                      |
------------------------------------------------------------------------------------------------------*/

class Latitude
{
private:
    int degrees, minutes, seconds; // Zmienna szerokosci geograficznej punktu dla ktorego ma byc obliczone gorowanie slonca pobierana od uzytkownika
    string hemisphere;             // Zmienna polkuli pobierana od uzytkownika

    int degreesZen, minutesZen, secondsZen; // Zmienne szerokosci geograficznej punktu, gdzie slonce goruje w zenicie
    string hemisphereZen;                   // Zmienna polkuli punktu, gdzie slonce goruje w zenicie

    int resultDegrees, resultMinutes, resultSeconds; // Zmienne wyniku obliczen - wysokosci gorowania Slonca

public:
    Latitude(int = 0, int = 0, int = 0, string = "brak danych", int = 0, int = 0, int = 0, string = "brak danych", int = 0, int = 0, int = 0);

    void getData(char choice);

    void calculations(int degrees, int minutes, int seconds, string hemispherre, int degreesZen, int minutesZen, int secondsZen, string hemisphereZen);
    void polarDayNight(int resultDegrees, int resultMinutes, int resultSeconds);
};

/*------------------------------------------------------------------------------------------------------
|                                                                                                      |
|                                          GetChoice                                                   |
|                                                                                                      |
------------------------------------------------------------------------------------------------------*/

class GetChoice
{
private:
    bool error;     // potwierdzenie wystapienia bledu z powodu uzytkownika --> decyzja, czy zapytac uzytkownika o zamkniecie programu
    char choice;    // drugi wybor, czyli dokladne okreslenie sytuacji uzytkownika
    int type;       // typ walidacji - co jest dozwolone, a co nie; type == 0 --> tylko liczby; type == 1 --> liczby i 'q'; type == 2 --> liczby, 'b' i 'q'

public:
    GetChoice(char = '1', bool = false, int = 1); // Konstruktor, podstawowa wartosc wyboru, to 1 (raczej zawsze powinna byc opcja 1.), doyslnie error ma wartosc false

    void choiceValidation(string file_name, int type, bool clear); // pobranie oraz walidacja wyboru uzytkownika
    char showChoice(); // Pokazanie wartosci zmiennej choice (wybor)
};
