#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int ile_testow, ile_liczb;
	int temp, suma, licznik, indeks_najblizej;
	float srednia;

	cin >> ile_testow;

	for (int i = 0; i < ile_testow; i++)
	{
		int* liczby;	// Przygotowanie dynamicznej tablicy

		suma = 0;		// Wyzerowanie sumy
		licznik = 0;	// Wyzerowanie licznika

		cin >> ile_liczb;
		liczby = new int [ile_liczb];

		for (int k = 0; k < ile_liczb; k++)
		{
			cin >> liczby[k];

			suma += liczby[k];
			licznik++;
		}

		if (licznik == 0) licznik = 1; // Gdyby sie tak zdarzylo, ze licznik jest rowny zero, to licznik, POMIMO tego, ze jest 0 liczb, a nie 1, ma wynosic 1 (aby zapobiec dzieleniu przez 0)

		srednia = (float) suma / licznik;

		indeks_najblizej = 0;

		for (int k = 1; k < ile_liczb; k++)
		{
			if (abs(srednia - liczby[k]) < abs(srednia - liczby[indeks_najblizej]))
			{
				indeks_najblizej = k;
			}
		}

		cout << liczby[indeks_najblizej] << endl;

		delete[] liczby; // Usuniecie tablicy
	}
}