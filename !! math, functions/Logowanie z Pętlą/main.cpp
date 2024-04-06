#include <iostream>

using namespace std;

string haslo, login, loginpodany, haslopodane;

int main()

{
    login="123456";
    haslo="admin123";

    cout << "Logowanie\n\n";

    cout<<"Podaj login: ";
    cin>>loginpodany;

    cout<<"Podaj haslo: ";
    cin>>haslopodane;


    while (login!=loginpodany && haslo!=haslopodane)
    {
        cout<<"\nZly login lub haslo!\nPodaj ponownie prawidlowy login i haslo!\n";
        cout<<"Login: ";
        cin>>loginpodany;

        cout<<"Haslo: ";
        cin>>haslopodane;
    }

    if (login==loginpodany && haslo==haslopodane) cout<<"\nPoprawny login i haslo! Witamy w programie.\n";

    return 0;
}
