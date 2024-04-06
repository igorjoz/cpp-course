#include <iostream>
#include <fstream>

using namespace std;

string imie, nazwisko;
int telefon;

int main()
{
    cout<<"Program zapisujacy dane do pliku"<<endl<<endl;

    cout<<"Podaj imie: ";
    getline(cin, imie); //Pobranie calej linii (moga byc np. dwa imiona)
    cout<<"\nPodaj nazwisko: ";
    cin>>nazwisko;
    cout<<"\nPodaj numer telefonu: ";
    cin>>telefon;

    fstream plik;                    //Zmienna pliku
    plik.open("dane.txt", ios::out); //Otworz dane.txt (jak nie ma to swtworz, dopisywanie - out)

    plik<<imie<<endl;
    plik<<nazwisko<<endl;
    plik<<telefon<<endl;

    plik.close();

    cout<<"\nUkonczono operacje\n\n";
    return 0;
}
