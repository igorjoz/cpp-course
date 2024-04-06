#include <iostream>

using namespace std;

int reku_silnia(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return reku_silnia(n - 1) * n;
	}
}

int iter_silnia(int n)
{
	if (n > 1)
	{
		int wynik = 1;

		for (int i = 2; i <= n; i++)
		{
			wynik *= i;
		}
		return wynik;
	}
	else
	{
		return 1;
	}
	
}

int main()
{
	int const n = 6;
	int wynik1, wynik2;

	wynik1 = reku_silnia(n);
	cout << "Wynik z rekurencji: " << wynik1;

	cout << endl << endl;

	wynik2 = iter_silnia(n);
	cout << "Wynik z iteracji: " << wynik2 << endl;

	return 0;
}