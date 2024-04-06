#include <iostream>

using namespace std;

string login, haslo;

int main()
{
    cout << "Witaj na stronie banku Dzeus\n\n";
    cout<<"Wpisz swoj login: ";
    cin>>login;

    cout<<"Wpisz swoje haslo: ";
    cin>>haslo;

    {
    if (login=="justice" && haslo=="leeroyjenkins")
    {
        cout<<"\nWitaj Wojciechu Wiernicki. Udalo Ci sie zalogowac\n";
    }

    if (login=="leprikon" && haslo=="wielkieczolo")
    {
        cout<<"\nWitaj Lukaszu Rudlicki. Udalo Ci sie zalogowac\n";
    }

    }
    return 0;
}
