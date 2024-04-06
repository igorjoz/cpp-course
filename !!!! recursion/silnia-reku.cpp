#include <iostream>

using namespace std;

unsigned long int silnia(int a)
{
	if (a == 1 || a == 0) return 1;
	else return silnia(a-1)*a;
}

int main()
{
	int liczba;
	unsigned long int wynik;

	cout << "Podaj liczbe, ktore ma zostac podniesiona do silni: ";
	cin >> liczba;
	cout << silnia(liczba);

	return 0;
}