#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

string PIN, PIN_podany;
bool blad;

int main()
{
    PIN="1234";

    do
    {
    cout<<"Podaj PIN: ";
    cin>>PIN_podany;

    if (PIN!=PIN_podany)
    {
        cout<<"Blad! Niepoprawny PIN. Wprowadz PIN ponownie.";
        Sleep(2500);
        system("cls");
    }

    } while (PIN!=PIN_podany);

    cout<<"\n";
    cout<<"Brawo! Poprawny PIN";

    return 0;
}
