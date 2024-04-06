#include <iostream>
#include <cstdlib>      // system("CLS")
#include <windows.h>    // Sleep(1000)
#include <fstream>      // fstream file...
#include <string>       // getline()

#include "get_choice.h"

//------------------------------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

void GetChoice::wybor_walidacja(int kiedy_wyjscie, string file_name)
{
    system("CLS");

    do
    {
        error = false;

//------------------------------------------------------------------------------------------------------
        // Odczytanie tresci z pliku
        fstream file;

        file.open(file_name.c_str(), ios::in);

        if (file.good())
        {
            string line;

            while(!file.eof())
            {
                getline(file, line);
                cout<<line<<endl;
            }
            cout<<"Wybor: ";
        }
        else
        {
            cout<<"Problem z plikiem. Sprawdz folder \"txt\"";
        }

        file.close();

//------------------------------------------------------------------------------------------------------

        char temp; // Tymczasowa zmienna na potrzeby walidacji wprowadzonych danych
        cin>>temp;

        cout<<"\n\n";

        if (isdigit(temp))
        {
            choice = temp - '0';
        }
        else if (temp == 'q')
        {
            choice = kiedy_wyjscie;
        }
        else
        {
            cout<<"Blad! To nie jest liczba! Wprowadz poprawne dane\n";
            reset_counting(5);
            system("CLS");
            error=true;
        }
    }
    while (error == true);
}

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

void GetChoice::reset_counting(int time)
{
    cout<<"Zaraz nastapi reset programu ";
    for (int i=time; i>0; i--) // Odliczanie do wyczyszczenia konsoli
    {
        cout<<i<<".. ";
        Sleep(1000);
    }
}
