#include <iostream>

using namespace std;

int reku_nwd(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return reku_nwd(b, a % b);
	}
}

int iter_nwd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}

	return a;
}

int main()
{
	int a = 50, b = 6; // a > b

	cout << "Najwiekszy wspolny dzielnik dla " << a << " i " << b << ", czyli NWD(" << a << "," << b << ")" << endl << endl;

	int wynik1 = reku_nwd(a, b);
	cout << "Rekurencyjnie: " << wynik1 << endl << endl;

	int wynik2 = iter_nwd(a, b);
	cout << "Iteracyjnie: " << wynik2 << endl;
}