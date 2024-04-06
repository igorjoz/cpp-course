#include <iostream>
#include <string>

using namespace std;

string tekst;

int main()
{
    cout <<"Sprawdzanie czy tekst jest pusty\n";

    cout<<"Podaj tekst: ";
    getline(cin, tekst);
    if (tekst.empty()) cout<<"Nic nie wpisales\n";
    else cout<<"Ten tekst nie jest pusty";

    cout<<"\n";

    cout<<"Tekst wpisany przez Ciebie to: "<<tekst;

    cout<<"\n\nDlugosc tekstu, ktorey wpisales wynosi: "<<tekst.length();

    cout<<"\n\nPrzedostatni znak w tym teksie to: "<<tekst.at(tekst.length()-2);

    cout<<"\n\nSpacja w tym tekscie znajduje sie: "<<(tekst.find(' ')+1);

    cout<<"Podane imie jest: ";
    //if (tekst.find)
    //{
    //}

    cout<<"\n";
    return 0;
}
