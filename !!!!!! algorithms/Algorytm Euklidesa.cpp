#include <iostream>

using namespace std;

int euklides(int a, int b)
{
	if (a % b == 0) return b;
	else return euklides(b, a % b);
}

int main()
{
	int a, b;

	cout << "Podaj liczbe a: ";
	cin >> a;
	cout << "Podaj liczbe b: ";
	cin >> b;

	cout << euklides(a, b);

	return 0;
}