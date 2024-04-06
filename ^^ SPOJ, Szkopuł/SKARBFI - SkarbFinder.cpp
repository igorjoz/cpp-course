#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n1, n2; // n1 - pierwsza petla, n2 - druga, wewnetrzna petla

	/* 
	pion dodatni	-->	na pó³noc
	pion ujemny		-->	na poludnie

	poziom dodatni	-->	na zachod
	poziom ujemny	-->	na wschod
	*/
	int pion, poziom;

	cin >> n1;

	for (int i = 0; i < n1; i++)
	{
		pion = 0;
		poziom = 0;

		cin >> n2;
		int* tab_kierunek = new int[n2];
		int* tab_wartosc = new int[n2];

		for (int k = 0; k < n2; k++)
		{
			cin >> tab_kierunek[k] >> tab_wartosc[k];

			/*
			0 - pó³noc
			1 - po³udnie
			2 - zachód
			3 - wschód
			*/

			if (tab_kierunek[k] == 0)
			{
				pion += tab_wartosc[k];
			}
			if (tab_kierunek[k] == 1)
			{
				pion -= tab_wartosc[k];
			}

			if (tab_kierunek[k] == 2)
			{
				poziom += tab_wartosc[k];
			}
			if (tab_kierunek[k] == 3)
			{
				poziom -= tab_wartosc[k];
			}
		}

		// Wypisanie wyniku
		if (pion > 0)
		{
			cout << "0 " << pion << endl;
		}
		else if (pion < 0)
		{
			cout << "1 " << abs(pion) << endl;
		}

		if (poziom > 0)
		{
			cout << "2 " << poziom << endl;
		}
		else if (poziom < 0)
		{
			cout << "3 " << abs(poziom) << endl;
		}

		if (pion == 0 && poziom == 0)
		{
			cout << "studnia" << endl;
		}
	}

	return 0;
}