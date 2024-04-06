#include <iostream>
#include <cstdio>       // getchar()
#include <cstdlib>      // system("CLS"), exit(0)
#include <windows.h>    // Sleep()

#include "get_choice.h"
#include "longitude.h"
#include "latitude.h"


//------------------------------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

int main()
{
    bool stop = false;  // jesli uzytkownik chce zatrzymac program

    while (stop!=true)  // Petla sprawdzajaca, czy uzytkownik chce zakonczyc program
    {
        GetChoice c0;   // Zerowy wybor, czyli miedzy dlugoscia geograficzna, a szerokoscia geograficzna
        c0.wybor_walidacja(3, "txt/choice0.txt");

//------------------------------------------------------------------------------------------------------

        switch(c0.choice)
        {
        case 1:
            system("CLS");

            GetChoice c1; // Pierwszy wybor - menu dlugosci geograficznej;

            c1.wybor_walidacja(4, "txt/choice1.txt");

            switch (c1.choice)
            {
            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            default:

                break;
            }
            break;

            //------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

        case 2:
            system("CLS");

            GetChoice c2; // Drugi to menu szerokosci geograficznej

            c2.wybor_walidacja(0, "txt/choice2.txt");

            break;

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

        case 3:
            stop=true;
            break;

//------------------------------------------------------------------------------------------------------

        default:
            cout<<"Blad! Nie ma takiej opcji - musisz wpisac 1, 2 lub \'q\'\n";
            c0.reset_counting(5);
            break;

//------------------------------------------------------------------------------------------------------
        }
        system("CLS");
    }

    cout<<"Koniec programu\n\n";
    system("PAUSE");
    return 0;
}
