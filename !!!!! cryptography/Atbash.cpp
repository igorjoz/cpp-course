#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string obrobka(string tekst)
{
	transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);

	int dlugosc = tekst.length();

	for (int i = 0; i < dlugosc; i++)
	{
		if (tekst[i] < 'a' || tekst[i] > 'z')
		{
			tekst.erase(i, 1);
			i--;
			dlugosc = tekst.length();
		}
	}

	return tekst;
}

string atBash(string tekst)
{
	int dlugosc = tekst.length();

	for (int i = 0; i < dlugosc; i++)
	{
		int temp = (int)tekst[i] - 97;
		temp = abs(temp - 25);
		temp += 97;
		tekst[i] = (char)temp;
	}

	return tekst;
}

int main()
{
	string ciag, wynik;

    cout << "Podaj ciag: ";
    cin >> ciag;

	ciag = obrobka(ciag);

	wynik = atBash(ciag);
	cout << endl << wynik;

	return 0;
}