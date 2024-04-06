#include <iostream>

using namespace std;

int main()
{
	int const dzien = 86400;

	int zestawy;

	cin >> zestawy;

	for (int i=0; i < zestawy; i++)
	{
		int ciastka = 0;
		int ile_pudelek = 0;

		int uczestnikow, pudelko;
		cin >> uczestnikow >> pudelko;

		for (int j = 0; j < uczestnikow; j++)
		{
			int ile_uplynelo = 0;

			int temp;
			cin >> temp;

			while (ile_uplynelo + temp <= dzien)
			{
				ciastka++;
				ile_uplynelo += temp;
			}

			while (ile_pudelek*pudelko < ciastka)
			{
				ile_pudelek++;
			}
		}
		cout << ile_pudelek << endl;
	}
}