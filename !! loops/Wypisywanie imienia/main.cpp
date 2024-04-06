#include <iostream>

using namespace std;

string tekst;
int liczba, i;

int main()
{
    cout <<"Podaj tekst: ";
    cin>>tekst;
    cout<<"Podaj liczbe razy powtorzenia tekstu: ";
    cin>>liczba;

    for (i=1; i<=liczba; i++)
    {
        cout<<i<<". "<<tekst<<"\n";
    }
    return 0;
}
