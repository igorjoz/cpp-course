#include <iostream>     // cout, cin
#include <cstdio>       // getchar()
#include <stdlib.h>     // system("CLS"), exit(0)
#include <windows.h>    // Sleep()

//------------------------------------------------------------------------------------------------------

#include "Calculations.h" // Plik z klasami

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

int main()
{
    bool stop = false;  // stop == 1 --> uzytkownik chce zatrzymac program
    bool again = false; // again == 1 --> uzytkownik uzyl juz programu chociaz jeden raz

    GetChoice c1; // c1 - Pierwszy obiekt wyboru; wybor miedzy dlugoscia geograficzna, a szerokoscia geograficzna
    GetChoice c2; // c2 - Drugi obiekt wyboru; menu dlugosci lub szerokosci geograficznej

    Longitude longi;    // longi - obiekt do obliczen na dlugosci geograficznej
    Latitude lati;      //lati - obiekt do obliczen na szerokosci geograficznej

    do // Petla sprawdzajaca, czy uzytkownik chce zakonczyc program
    {
        if (again) // Jesli uzytkownik korzysta ponownie
        {
            std::system("cls");
            std::cout << "Wrociles do menu, mozesz skorzystac ponownie" << std::endl << std::endl;
            c1.choiceValidation("txt/choice1.txt", 1, false); // Pobranie danych pierwszego wyboru oraz walidacja
        }
        else // Gdy uzytkownik korzysta poraz pierwszy
        {
            c1.choiceValidation("txt/choice1.txt", 1, true); // Pobranie danych pierwszego wyboru oraz walidacja
        } 

     //------------------------------------------------------------------------------------------------------

        switch (c1.showChoice()) // Pierwszy, glowny switch - dla c1
        {
        case '1':

            c2.choiceValidation("txt/choice2.1.txt", 2, true); // Pobranie danych drugiego wyboru oraz walidacja

            switch (c2.showChoice()) // Drugi switch case - dla c2
            {
            case '1': // 1: Znam polozenie punktu A i punktu B - OBLICZANIE ROZNICY CZASU SLONECZNEGO
                longi.getData(c2.showChoice());
                break;

            case '2': //2: Znam polozenie punktu A i punktu B oraz godzine w punkcie B - OBLICZANIE KONKRETNEJ GODZINY W PUNKCIE A
                longi.getData(c2.showChoice());
                break;

            case '3': // 3: Znam roznice czasu miedzy punktem A i punktem B - OBLICZANIE ROZNICY ODLEGLOSCI KATOWEJ
                longi.getData(c2.showChoice());
                break;

            case 'b': // 'b' - uzytkownik che sie cofnac
                break;

            case 'q': // 'q' - uzytkownik chce wyjsc z programu
                stop = true;
                break;

            default: // gdy uzytkownik poda bledne dane, ALE to niemozliwe - wczesniej dane przechodza walidacje
                std::cout << "Blad!";
                std::system("pause");
                exit(0);
                break;
            }

            break;

     //------------------------------------------------------------------------------------------------------
     //------------------------------------------------------------------------------------------------------

        case '2': // NIE JEST JESZCZE GOTOWE!

            c2.choiceValidation("txt/choice2.2.txt", 2, true);

            switch (c2.showChoice())
            {
            case '1': // 1:
                std::cout << "2.1";
                break;

            case '2': // 2:
                std::cout << "2.2";
                break;

            case 'b': // 'b' - uzytkownik che sie cofnac
                break;

            case 'q': // 'q' - uzytkownik chce wyjsc z programu
                stop = true;
                break;

            default: // gdy uzytkownik poda bledne dane, ALE to niemozliwe, bo wczesniej dane przechodza przez walidacje
                std::cout << "Blad!";
                std::system("pause");
                exit(0);
                break;
            }

            break;

         //------------------------------------------------------------------------------------------------------
         //------------------------------------------------------------------------------------------------------

        case 'q':
            stop = true;
            break;

         //------------------------------------------------------------------------------------------------------

        default:
            std::cout << "Blad! Nie ma takiej opcji - musisz wpisac 1, 2 lub \'q\'\n";
            resetCounting(5, "Zaraz nastapi reset programu ", false);
            break;
        }

        std::cout << std::endl;
        if (stop == false)
        {
            std::system("pause");
            again = true;
        }

    } while (stop == false);

    return 0;
}
