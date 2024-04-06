#include <iostream>     // cout, cin
#include <cstdlib>      // system("CLS"), atoi()
#include <windows.h>    // Sleep(1000)
#include <fstream>      // fstream file...
#include <string>       // getline(), .length()

//------------------------------------------------------------------------------------------------------

#include "Calculations.h" // Plik naglowkowy z klasami

//------------------------------------------------------------------------------------------------------

using namespace std;

/*------------------------------------------------------------------------------------------------------
|                                                                                                      |
|                                          Funkcje                                                     |
|                                                                                                      |
------------------------------------------------------------------------------------------------------*/

// Funkcja odliczajaca do resetu dla podanego czasu w milisekundach oraz wyswietlajaca podany tekst
void resetCounting(int time, string text, bool doEndl)
{
    cout << text; // Wyswietlenie podanego tekstu
    for (int i = time; i > 0; i--) // Odliczanie do wyczyszczenia konsoli
    {
        cout << i << ".. ";
        Sleep(1000);
    }

    if (doEndl)
    {
        std::cout << std::endl;
    }
}

// Funkcja sprawdzajaca, czy lancuch znakow jest liczba
bool isStringANumber(string str) // Sprawdza, czy lancuch znakow zawiera TYLKO liczby, jesli tak zwraca 1
{
    bool fine = true; // fine == 1 (pod koniec funkcji) --> poprawne dane; fine == 0 --> bledne dane od uzytkownika
    int length = str.length(); // length - dlugosc podanego lancucha znakow

    for (int i = 0; i < length; i++) // iteracja po kazdym znaku lancucha
    {
        char temp = (char)str[i];
        if (!isdigit(temp))
        {
            fine = false;
        }
    }

    return fine;
}

/*------------------------------------------------------------------------------------------------------
|                                                                                                      |                             
|                                          Longitude                                                   |
|                                                                                                      |
------------------------------------------------------------------------------------------------------*/

// Konstruktor klasy Longitude
Longitude::Longitude(int lAd, int lBd, int lAm, int lBm, int lAs, int lBs, string hA, string hB, int Bh, int Bm, int Bs, bool ND, bool PD)
{
    locA_degrees = lAd;
    locB_degrees = lBd;

    locA_minutes = lAm;
    locB_minutes = lBm;

    locA_seconds = lAs;
    locB_seconds = lBs;

    hemisphereA = hA;
    hemisphereB = hB;

    hourB = Bh;
    minuteB = Bm;
    secondB = Bs;

    isNextDay = ND;
    isPreviousDay = PD;
}

//------------------------------------------------------------------------------------------------------

void Longitude::getData(char choice)
{
    bool fine = true;

    if (choice == '1') // 1: Znam polozenie punktu A i punktu B - OBLICZANIE ROZNICY CZASU SLONECZNEGO
    {
        fine = true; // fine == 1 --> poprawne dane; fine == 0 --> bledne dane od uzytkownika

        std::system("cls");

        // Zestaw standardowych danych dlugosci geograficznej do pobrania
        std::cout << "Podaj dlugosc geograficzna punktu A:" << std::endl;
        Longitude::degreesMinSecValidation(locA_degrees,"(A) stopnie: ", 1);
        Longitude::degreesMinSecValidation(locA_minutes,"(A) minuty: ", 2);
        Longitude::degreesMinSecValidation(locA_seconds,"(A) sekundy: ", 2);
        Longitude::hemisphereValidation(hemisphereA, "(A) polkula: ");

        std::cout << std::endl << "Podaj dlugosc geograficzna punktu B:" << std::endl;
        Longitude::degreesMinSecValidation(locB_degrees, "(B) stopnie: ", 1);
        Longitude::degreesMinSecValidation(locB_minutes, "(B) minuty: ", 2);
        Longitude::degreesMinSecValidation(locB_seconds, "(B) sekundy: ", 2);
        Longitude::hemisphereValidation(hemisphereB, "(B) polkula: ");
        // Koniec standardowych danych dlugosci geograficznej do pobrania
    }
    else if (choice == '2') //2: Znam polozenie punktu A i punktu B oraz godzine w punkcie B - OBLICZANIE KONKRETNEJ GODZINY W PUNKCIE A
    {
        // Zestaw standardowych danych dlugosci geograficznej do pobrania
        std::cout << "Podaj dlugosc geograficzna punktu A:" << std::endl;
        Longitude::degreesMinSecValidation(locA_degrees, "(A) stopnie: ", 1);
        Longitude::degreesMinSecValidation(locA_minutes, "(A) minuty: ", 2);
        Longitude::degreesMinSecValidation(locA_seconds, "(A) sekundy: ", 2);

        std::cout << std::endl << "Podaj dlugosc geograficzna punktu B:" << std::endl;
        Longitude::degreesMinSecValidation(locB_degrees, "(B) stopnie: ", 1);
        Longitude::degreesMinSecValidation(locB_minutes, "(B) minuty: ", 2);
        Longitude::degreesMinSecValidation(locB_seconds, "(B) sekundy: ", 2);
        // Koniec standardowych danych dlugosci geograficznej do pobrania

        // Tutaj jeszcze do pobrania czas w punkcie B

    }
    else if (choice == '3') // 3: Znam roznice czasu miedzy punktem A i punktem B - OBLICZANIE ROZNICY ODLEGLOSCI KATOWEJ
    {
        // Tutaj tylko pobrac czas
    }
}

//------------------------------------------------------------------------------------------------------

void Longitude::degreesMinSecValidation(int &what, string text, int type)
{
    string errorInfo[2] = { "Bledne dane!\nDozwolone tylko liczby wieksze rowne 0 i mniejsze rowne 180\nWpisz dane ponownie ",  "Bledne dane!\nDozwolone tylko liczby wieksze rowne 0 i jednoczesnie mniejsze od 60\nWpisz dane ponownie " }; // Zawartosc do wyswietlenie, gdy uzytkownik wprowadzi bledne dane, trzy mozliwosci

    string temp; // Tymczasowy lancuch znakow, potrzebny do prawidlowej walidacji
    bool fine = true; // fine == 1 (pod koniec funkcji) --> poprawne dane; fine == 0 --> bledne dane od uzytkownika

    do
    {
        fine = true;

        std::cout << text;
        cin >> temp;

        fine = isStringANumber(temp);
        if (fine == false)
        {
            resetCounting(5, errorInfo[type - 1], true); // Zmniejszenie type o 1, bo tablice sa numerowane od 0
        }
        else
        {
            int number = atoi(temp.c_str()); // Konwersja tymczasowego stringa do int (juz wiadomo, ze to na pewno liczba)

            if (type == 1) // Dla typu == 1
            {
                if (number < 0 || number > 180)
                {
                    fine = false;
                }
            }
            else if (type == 2) // Dla typu == 2
            {
                if (number < 0 || number >= 60) // Nie moze wychodzic poza zakres <0;60)
                {
                    fine = false;
                }
            }

            if (fine == true)
            {
                what = number;
            }
            else
            {
                resetCounting(5, errorInfo[type - 1], true);; // Zmniejszenie type o 1, bo tablice sa numerowane od 0
            }
        }
    } while (fine == false);
}

//------------------------------------------------------------------------------------------------------


void Longitude::hemisphereValidation(string &what, string text)
{

}

/*------------------------------------------------------------------------------------------------------
|                                                                                                      |
|                                          Latitude                                                    |
|                                                                                                      |
------------------------------------------------------------------------------------------------------*/

// Konstruktor klasy Latitude
Latitude::Latitude(int dg, int m, int s, string h, int dgZ, int mZ, int sZ, string hZ, int rDg, int rM, int rS)
{
    degrees = dg;
    minutes = m;
    seconds = s;
    hemisphere = h;
    degreesZen = dgZ;
    minutesZen = mZ;
    secondsZen = sZ;
    hemisphereZen = hZ;
    resultDegrees = rDg;
    resultMinutes = rM;
    resultSeconds = rS;
}

//------------------------------------------------------------------------------------------------------

void Latitude::getData(char choice)
{

}

//------------------------------------------------------------------------------------------------------

void Latitude::calculations(int degrees, int minutes, int seconds, string hemispherre, int degreesZen, int minutesZen, int secondsZen, string hemisphereZen)
{

}

//------------------------------------------------------------------------------------------------------

// Wypisanie dodatkowych informacji w przypadku, gdy w podanym mijscu wystepuje dzien / noc polarna
void Latitude::polarDayNight(int resultDegrees, int resultMinutes, int resultSeconds)
{

}

/*------------------------------------------------------------------------------------------------------
|                                                                                                      |
|                                          GetChoice                                                   |
|                                                                                                      |
------------------------------------------------------------------------------------------------------*/

// Konstruktor klasy GetChoice
GetChoice::GetChoice(char ch, bool err, int t)
{
    choice = ch;
    error = err;
    type = t;
}

//------------------------------------------------------------------------------------------------------

// Pobranie wyboru oraz walidacja
void GetChoice::choiceValidation(string file_name, int type, bool clear)
{
    if (clear)
    {
        system("cls");
    }

    do
    {
        error = false;

        // Odczytanie tresci z pliku
        fstream file;

        file.open(file_name.c_str(), ios::in);

        if (file.good())
        {
            string line;

            while (!file.eof())
            {
                getline(file, line);
                cout << line << std::endl;
            }
            cout << "Wybor: ";
        }
        else
        {
            cout << "Problem z plikiem. Sprawdz folder \"txt\"";

            std::system("pause");
            std::exit(0);
        }

        file.close();

        //------------------------------------------------------------------------------------------------------

        char temp; // Tymczasowa zmienna na potrzeby walidacji wprowadzonych danych
        std::cin >> temp; // Pobranie tymczasowej zmiennej

        std::cout << std::endl << std::endl;

        if ((type == 0 && isdigit(temp)) || (type == 1 && (isdigit(temp) || temp == 'q')) || (type == 2 && (isdigit(temp) || temp == 'b' || temp == 'q'))) // Jesli wszystko jest OK
        {
            choice = temp;
        }
        else // Gdy uzytkownik wprowadzi niepoprawne dane
        {
            cout << "Blad! To nie jest liczba";
            if (type == 1)
            {
                std::cout << " lub \'q\'";
            }
            else if (type == 2)
            {
                std::cout << ", \'b\' lub \'q\'";
            }

            std::cout << "! Wprowadz poprawne dane" << std::endl;

            resetCounting(5, "Reset za ", false);
            system("cls");
            error = true;
        }

    } while (error == true);
}

//------------------------------------------------------------------------------------------------------

// Funkcja zwracajaca zawartosc prywatnej zmiennej choice
char GetChoice::showChoice()
{
    return choice;
}