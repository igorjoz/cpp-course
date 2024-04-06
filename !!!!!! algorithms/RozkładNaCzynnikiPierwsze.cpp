#include <iostream>

using namespace std;

int main()
{
	int liczba;
	bool koniec = false;

	cout << "Podaj liczbe calkowita: ";
	cin >> liczba;

	cout << endl << "Rozklad " << liczba << " na czynniki pierwsze:" << endl;

	int i = 2;
	while (!koniec)
	{
		if (liczba == 1) koniec = true;
		else if (liczba % i == 0)
		{
			cout << i << " ";
			liczba /= i;
		}
		else
		{
			i++;
		}
	}

	return 0;
}