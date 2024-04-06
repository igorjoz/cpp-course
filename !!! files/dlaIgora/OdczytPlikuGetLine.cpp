//Program otwiera podany przez nas plik i sprawdza czy nie wyst¹pi³y b³êdy. Je¿eli wszystko jest w porz¹dku, rozpoczyna siê wczytywanie danych za //pomoc¹ funkcji getline. Funkcja wywo³ana jest w pêtli wykonuj¹cej siê póki plik nie osi¹gnie koñca (eof).

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
            //cout << linia << endl; //wyœwietlenie linii
            cout << tresc[i] << endl;
        }
        plik.close();
    }
 
    system("PAUSE");
    return(0);
}

//Otwarliœmy plik u¿ywaj¹c nag³ówka biblioteki <fstream> oraz wykorzystuj¹c zmienn¹ fstream. 
//Poniewa¿ tylko wczytujemy tekst z pliku moglibyœmy u¿yæ //biblioteki <ifstream>. Nazwy pochodz¹ od jêzyka angielskiego:

//    ifstream = in file stream = wczytywanie plików
//    ofstream = out file stream = zapisywania plików
//    fstream = po³¹czenie obu powy¿szych
