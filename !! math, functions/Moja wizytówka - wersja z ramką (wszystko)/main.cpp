/*
Uniwersalna wizytówka - z ramką
*/

#include <iostream>

using namespace std;
string imie;

int main ()
{
    cout<<"Podaj swoje imie: ";
    cin>> imie;


    cout<<"x x x x x x x x x x x x x x x x\n";
    cout<<"x                             x\n";
    cout<<"x             "<<imie<<"            x\n";
    cout<<"x                             x\n";
    cout<<"x x x x x x x x x x x x x x x x\n\n\n";

    return 0;
}


