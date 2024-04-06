#include <iostream>

using namespace std;

long int potega(int p, int w)
{
	if (w == 0) return 1;
	else return potega(p, w - 1) * p;
}

int main()
{
	int podstawa, wykladnik;

	cout << "Podaj podstawe: ";
	cin >> podstawa;
	cout << "Podaj wykladnik: ";
	cin >> wykladnik;

	cout << "Wynik: " << potega(podstawa, wykladnik);

	return 0;
}