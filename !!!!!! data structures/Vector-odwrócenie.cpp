#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> liczby;
	int input, dlugosc;

	while (cin >> input)
	{
		liczby.push_back(input);
	}

	dlugosc = liczby.size();

	for (int i = 0; i < dlugosc/2; i++)
	{
		int temp = liczby[i];
		liczby[i] = liczby[dlugosc - 1 - i];
		liczby[dlugosc - 1 - i] = temp;
	}

	for (int i = 0; i < dlugosc; i++)
	{
		cout << liczby[i] << " ";
	}
}