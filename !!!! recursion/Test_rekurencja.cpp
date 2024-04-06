#include <iostream>

using namespace std;

int rekurencja(int l)
{
	if (l == 1)
	{
		return 2;
	}
	else return rekurencja(l - 1) * 2;
}

int main()
{
	int liczba, wynik;

	cout << "Podaj wykladnik: ";
	cin >> liczba;

	wynik = rekurencja(liczba);

	cout << "Potega 2 dla wykladnika = " << liczba << " wynosi: "<<wynik;

	return 0;
}