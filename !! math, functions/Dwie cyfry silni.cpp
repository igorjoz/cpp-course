#include <iostream>

using namespace std;

int main()
{
	int n, liczba;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> liczba;

		if (liczba == 0) cout << "0 1";
		else if (liczba == 1) cout << "0 1";
		else if (liczba == 2) cout << "0 2";
		else if (liczba == 3) cout << "0 6";
		else if (liczba == 4) cout << "2 4";
		else if (liczba == 5) cout << "2 0";
		else if (liczba == 6) cout << "2 0";
		else if (liczba == 7) cout << "4 0";
		else if (liczba == 8) cout << "2 0";
		else if (liczba == 9) cout << "8 0";
		else if (liczba > 9) cout << "0 0";

		cout << endl;
	}
}