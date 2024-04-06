#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string transformacja_wyrazenia(string wyrazenie)
{
	transform(wyrazenie.begin(), wyrazenie.end(), wyrazenie.begin(), ::tolower);

	int dlugosc = wyrazenie.length();

	for (int i = 0; i < dlugosc; i++)
	{
		if (wyrazenie[i] < 'a' || wyrazenie[i] > 'z')
		{
			wyrazenie.erase(i, 1);
			dlugosc = wyrazenie.length();
			i--;
		}
	}

	return wyrazenie;
}

string sortowanie_wyrazenia(string wyrazenie)
{
	int dlugosc = wyrazenie.length();

	for (int i = 0; i < dlugosc; i++)
	{
		for (int j = 1; j < dlugosc - i; j++)
		{
			if (wyrazenie[j] < wyrazenie[j - 1])
			{
				char temp = wyrazenie[j];
				wyrazenie[j] = wyrazenie[j - 1];
				wyrazenie[j - 1] = temp;
			}
		}
	}

	return wyrazenie;
}

int main()
{
	string wyrazenie1, wyrazenie2;
	int dlugosc1, dlugosc2;
	bool anagram = true;

	cout << "Podaj 1. wyrazenie: ";
	getline(cin, wyrazenie1);
	cout << "Podaj 2. wyrazenie: ";
	getline(cin, wyrazenie2);

	string sort_wyrazenie1 = transformacja_wyrazenia(wyrazenie1);
	string sort_wyrazenie2 = transformacja_wyrazenia(wyrazenie2);

	dlugosc1 = sort_wyrazenie1.length();
	dlugosc2 = sort_wyrazenie2.length();

	if (dlugosc1 == dlugosc2)
	{
		sort_wyrazenie1 = sortowanie_wyrazenia(sort_wyrazenie1);
		sort_wyrazenie2 = sortowanie_wyrazenia(sort_wyrazenie2);

		for (int i = 0; i < dlugosc1; i++)
		{
			if (sort_wyrazenie1[i] != sort_wyrazenie2[i])
			{
				anagram = false;
				break;
			}
		}
	}
	else
	{
		anagram = false;
	}

	cout << "Wyrazenia \"" << wyrazenie1 << "\" oraz \"" << wyrazenie2 << "\" ";
	if (anagram) cout << "SA anagramami";
	else cout << "NIE sa anagramami";

	cout << endl;

	return 0;
}