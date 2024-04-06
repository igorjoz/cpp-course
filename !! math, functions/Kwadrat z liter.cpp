#include <iostream>
#include <string>

using namespace std;

void kwadrat(string ciag)
{
	int k = 0;
	int dlugosc = ciag.length();

	for (int i = 0; i < dlugosc; i++)
	{
		cout << ciag[i] << "\t";
		k++;

		if (k == 7)
		{
			cout << endl << endl << endl;
			k = 0;
		}
	}
}

void kolumnami(string ciag, int bok)
{
	int k = 0;
	int dlugosc = ciag.length();

	for (int i = 0; i < bok; i++)
	{
		while (i + k < dlugosc)
		{
			cout << ciag[i + k];
			k += bok;
		}
		
		k = 0;
	}
}

int main()
{
	string ciag;

	cout << "Podaj ciag znakow: ";
	getline(cin, ciag);

	cout << endl << endl;

	kwadrat(ciag);

	cout << endl << endl;

	kolumnami(ciag, 7);

	cout << endl;
}