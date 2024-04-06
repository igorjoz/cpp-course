#include <iostream>
#include <string>

using namespace std;

string tekst;
int dlugosc;

int main()
{
    cout<<"Program szyfrujacy tekst metoda zamiany liter\n\n";
    cout<<"Podaj tekst, ktory chcesz zaszyfrowac: ";
    getline(cin, tekst);

    dlugosc=tekst.length();
    cout<<"Dlugosc tekstu wynosi: "<<dlugosc;

    cout<<"\n\n\nZaszyfrowany tekst:\n";

    for (int i=0; i<dlugosc; i++)
    {
        cout<<tekst[i+1]<<tekst[i];
        i+=1;
    }

    return 0;
}

    //cout<<tekst.at(tekst.length()-1);
    //cout<<tekst.at(tekst.length()-2)<<tekst.at(tekst.length()-1)<<tekst.at(tekst.length()-4)<<tekst.at(tekst.length()-3)<<tekst.at(tekst.length()-5);
