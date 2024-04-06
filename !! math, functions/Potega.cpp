#include <iostream>

using namespace std;

int reku_potega(int a, int b)
{
	if (b == 1)
	{
		return a;
	}
	else
	{
		return reku_potega(a, b - 1) * a;
	}
}

int iter_potega(int a, int b)
{
	int wynik = 1;

	for (int i = 0; i < b; i++)
	{
		wynik *= a;
	}

	return wynik;
}

int main()
{
	int a = 5, b = 4; // a to podstawa, b to wykladnik
	int wynik1, wynik2;

	cout << "Potega liczby" << endl << endl;

	wynik1 = reku_potega(a, b);
	cout << "Rekurencyjnie: " << wynik1;

	cout << endl << endl;

	wynik2 = iter_potega(a, b);
	cout << "Iteracyjnie: " << wynik2;

	cout << endl;

	return 0;
}