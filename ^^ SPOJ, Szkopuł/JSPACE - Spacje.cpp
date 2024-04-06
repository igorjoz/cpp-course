#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string linia;

	while (getline(cin, linia))
	{
		int dlugosc = linia.length();
		for (int i = 0; i < dlugosc; i++)
		{
			if (linia[i] == ' ')
			{
				linia.erase(i, 1);
				dlugosc--;

				linia[i] = toupper(linia[i]);

				i--;
			}
		}
		cout << linia << endl;
	}
}