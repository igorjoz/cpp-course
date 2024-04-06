#include <iostream>

using namespace std;

int const C = 15; // C >= 1
int f1[C], f2[C];

int reku_fib(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return reku_fib(n - 1) + reku_fib(n - 2);
	}
}

void iter_fib(int n)
{
	if (n >= 2)
	{
		f2[0] = 1; cout << f2[0] << " ";
		f2[1] = 1; cout << f2[1] << " ";

		for (int i = 2; i < C; i++)
		{
			f2[i] = f2[i - 1] + f2[i - 2];
			cout << f2[i] << " ";
		}
	}
	else if (n == 1)
	{
		f2[0] = 1;
	}
}

int main()
{
	cout << "Ciag Fibonacciego" << endl << endl;

	cout << "Rekurencyjnie: " << endl;
	for (int i = 0; i < C; i++)
	{
		f1[i] = reku_fib(i + 1);
		cout << f1[i] << " ";
	}

	cout << endl << endl << "Zlota liczba (z rekurencji): " << (float)f1[C - 1] / f1[C - 2] << endl << endl;

	cout << "Iteracyjnie:" << endl;
	iter_fib(C);

	cout << endl << endl << "Zlota liczba (z iteracji): " << (float)f2[C - 1] / f2[C - 2] << endl << endl;

	return 0;
}