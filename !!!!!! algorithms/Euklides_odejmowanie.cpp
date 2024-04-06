#include <iostream>

using namespace std;

int euklides_odejmowanie(int a, int b)
{
	if (a == b) return b;
	else if (a > b) return euklides_odejmowanie(b,a-b);
	else if (a < b) return euklides_odejmowanie(a, b-a);
}

int main()
{
	int a, b;

	cout << "Podaj a: ";
	cin >> a;
	cout << "Podaj b: ";
	cin >> b;

	cout << euklides_odejmowanie(a, b);
}