#include <iostream>
#include <string>

using namespace std;

string tekst;

int i, dlugosc;

int main()
{
    cout << "Wpisz jakis tekst: ";
    cin>>tekst;

    cout<<"Tekst podany przez Ciebie od tylu: ";

    tekst.length()=dlugosc;

    for (i=dlugosc; i=0; i--)
    {
    cout<<tekst.at(tekst.length()-i);
    }



    return 0;
}
