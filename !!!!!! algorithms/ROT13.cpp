#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string obrobka (string tekst)
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

string szyfrPodstawieniowy(string tekst, int przesuniecie, bool deszyfracja, bool odwroc)
{
	if (odwroc)
	{
		int dlugosc = tekst.length();

		for (int i = 0; i < dlugosc / 2; i++)
		{
			char temp = tekst[i];
			tekst[i] = tekst[dlugosc - i - 1];
			tekst[dlugosc - i - 1] = temp;
		}
	}

	if (deszyfracja == false)
	{
		for (int i = 0; i < tekst.length(); i++)
		{
			int temp = (int)(tekst[i] + przesuniecie);
			while (temp > 122) temp -= 26;

			tekst[i] = (char)temp;
		}
	}
	else
	{
		for (int i = 0; i < tekst.length(); i++)
		{
			int temp = (int)(tekst[i] - przesuniecie);
			while (temp < 97) temp += 26;

			tekst[i] = (char)temp;
		}
	}

	return tekst;
}

int main()
{
	string ciag;

	cout << "Podaj ciag znakow: ";
	getline(cin, ciag);

	ciag = obrobka(ciag);
	string wynik = szyfrPodstawieniowy(ciag, 1, true, true);

	cout << "Wynik szyfracji / deszyfracji: " << wynik << endl;

	return 0;
}