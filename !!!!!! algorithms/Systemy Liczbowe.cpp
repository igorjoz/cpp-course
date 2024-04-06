#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int dec_bin(int liczba);
int bin_dec(int liczba);
void validation(int wybor, int numer);

int main()
{
	int wybor;
	bool powtorz;
	int liczba;
	int wynik;

	do
	{
		powtorz = false;

		cout << "\t  Menu" << endl << endl;
		cout << "1. dziesietne --> binarne" << endl;
		cout << "2. binarne --> dziesietne" << endl << endl;

		cout << "Wybor: ";
		cin >> wybor;

		system("CLS");

		cout << "Podaj liczbe: ";
		cin >> liczba;

		validation(wybor, liczba);

		switch (wybor)
		{
		case 1:
			wynik = dec_bin(liczba);

			break;

		case 2:
			wynik = bin_dec(liczba);

			break;

		default:
			cout << "Nie ma takiej opcji!";
			Sleep(3000);
			powtorz = true;
			system("CLS");

			break;
		}
	} while (powtorz == true);
	
	system("PAUSE");

	return 0;
}

int dec_bin(int liczba)
{

}

int bin_dec(int liczba)
{

}

void validation(int wybor, int liczba)
{

}