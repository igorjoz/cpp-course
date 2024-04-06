#include <iostream>

using namespace std;

int main()
{
    string imie[5] = {"Jan", "Kamil", "Anna", "Karolina", "Wiktor"};
    int wiek[5] = {20, 7, 65, 16, 5};

    int odp;

    cout<<"Podaj numer uzytkownika (od 1 do 5): ";
    cin>>odp;

    odp--; // Odp nalezy zmniejszyc o 1, bo tablice sa numerowane od 0

    cout<<endl<<"imie: "<<imie[odp]<<endl<<"wiek: "<<wiek[odp];

    cout<<endl<<endl;
    return 0;
}
