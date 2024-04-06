//Program otwiera podany przez nas plik i sprawdza czy nie wyst�pi�y b��dy. Je�eli wszystko jest w porz�dku, rozpoczyna si� wczytywanie danych za //pomoc� funkcji getline. Funkcja wywo�ana jest w p�tli wykonuj�cej si� p�ki plik nie osi�gnie ko�ca (eof).

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
 
using namespace std;
 
int main()
{
    string tresc[200];
    int i;
	string linia;
    ifstream plik;
 
    plik.open("plik.txt.txt", ios::in);
    if(plik.good() == true)
    {
        while(!plik.eof())
        {
        	i++;
            getline(plik, linia);
            tresc[i]=linia;
            //cout << linia << endl; //wy�wietlenie linii
            cout << tresc[i] << endl;
        }
        plik.close();
    }
 
    system("PAUSE");
    return(0);
}

//Otwarli�my plik u�ywaj�c nag��wka biblioteki <fstream> oraz wykorzystuj�c zmienn� fstream. 
//Poniewa� tylko wczytujemy tekst z pliku mogliby�my u�y� //biblioteki <ifstream>. Nazwy pochodz� od j�zyka angielskiego:

//    ifstream = in file stream = wczytywanie plik�w
//    ofstream = out file stream = zapisywania plik�w
//    fstream = po��czenie obu powy�szych
