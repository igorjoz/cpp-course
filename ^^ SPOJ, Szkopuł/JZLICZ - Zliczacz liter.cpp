#include <iostream>
#include <string>

using namespace std;

int main()
{
	string wyrazenie;

	int male[26];
	int duze[26];

	for (int i = 0; i < 26; i++)
	{
		male[i] = 0;
		duze[i] = 0;
	}

	int n;
	cin >> n;

	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		getline(cin, wyrazenie);

		int dlugosc = wyrazenie.length();
		for (int j = 0; j < dlugosc; j++)
		{
			if (wyrazenie[j] != ' ')
			{
				if ((int)wyrazenie[j] >= 65 && (int)wyrazenie[j] <= 90)
				{
					int temp = (int)wyrazenie[j] - 65;
					duze[temp]++;
				}
				else if ((int)wyrazenie[j] >= 97 && (int)wyrazenie[j] <= 122)
				{
					int temp = (int)wyrazenie[j] - 97;
					male[temp]++;
				}
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (male[i] != 0)
		{
			cout << (char)(i + 97) << " " << male[i] << endl;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (duze[i] != 0)
		{
			cout << (char)(i + 65) << " " << duze[i] << endl;
		}
	}
}