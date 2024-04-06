#include <iostream>

using namespace std;

int main()
{
	int liczba;
	bool pierwsza = true;

	cout << "Podaj liczbe calkowita: ";
	cin >> liczba;

	for (int i = 2; i < liczba; i++)
	{
		if (liczba % i == 0)
		{
			pierwsza = false;
			i = liczba;
		}
	}

	if (pierwsza)
	{
		cout << "Liczba " << liczba << " JEST pierwsza";
	}
	else cout << "Liczba " << liczba << " NIE jest pierwsza";


	return 0;
}