#include <iostream>

using namespace std;

int znajdzE_Euklides(int b)
{
	int a = 3;
	int zapas_a = a;
	int zapas_b = b;

	int temp;

	do
	{
		do
		{
			temp = a % b;
			if (temp != 0)
			{
				a = b;
				b = temp;
			}
		} while (temp != 0);

		if (b != 1)
		{
			b = zapas_b;
			zapas_a += 2;
			a = zapas_a;
		}

	} while (b != 1);

	return a;
}

int znajdzD(int e, int O)
{
	int d = 1;
	int temp;

	do
	{
		temp = d * e % O;
		if (temp != 1) d++;
	} while (temp != 1);

	return d;
}

int main()
{
	int p, q; // liczby pierwsze
	int O; // funkcja Eulera
	int n; // modul n
	int e; // wykladnik publiczny e
	int d; // prywatny wykladnik

	// 1. Wyznaczenie liczb pierwszych
	p = 13;
	q = 11;

	// 2. Obliczenie funkcji Eulera
	O = (p - 1) * (q - 1);

	// 3. Obliczenie modulu n
	n = p * q;

	// 4. Wyznaczenie wykladnika publicznego e; jest on wzglednie pierwszy z O; 1 < e < n; nie musi byæ pierwsza, ale musi byc nieparzysta
	e = znajdzE_Euklides(O);
	cout << e;

	cout << endl << endl;
	d = znajdzD(e, O);
	cout << d;

	return 0;
}
