#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int n;
	int liczba, ostatnia;

	bool czy_pierwsza;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> liczba >> ostatnia;

		for (liczba; liczba <= ostatnia; liczba++)
		{
			czy_pierwsza = true;

			if (liczba == 1) czy_pierwsza = false;
			else if (liczba == 2) czy_pierwsza = true;
			else
			{
				for (int i = 2; i < ceil(liczba); i++)
				{
					if (liczba % i == 0) czy_pierwsza = false;
				}
			}

			if (czy_pierwsza == true)
			{
				cout << liczba << endl;
			}
		}
	}
}
