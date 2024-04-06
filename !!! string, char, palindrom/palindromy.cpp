#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_DEC = 1000000;

bool czyPalindrom(string str) {
	bool palindrom = true;

	//cout << str << ": ";
	for (int j = 0; j < (int)(str.length() / 2); j++) {
		//cout << str[j] << " ";

		if (str[j] != str[str.length() - 1 - j]) {
			palindrom = false;
			//cout << "nie palindrom";
			break;
		}
	}

	return palindrom;
}

int main()
{
	cout << "Zarowno palindrom w formie dziesietnej i palindrom w formie binarnej (liczby od 1 do 1000000):" << endl;
	// znalezienie dziesiêtnych palindromów
	for (int i = 1; i < MAX_DEC; i += 2) {

		string numberStr = to_string(i);

		bool palindromDziesietnie = czyPalindrom(numberStr);

		// jeœli palindom dziesiêtnie, to zamieñ na binarne i sprawdŸ czy te¿ jest palindromem
		if (palindromDziesietnie) {
			int number = i;

			// zamiana na binarne
			string binaryNumber = "";

			while (number != 0) {
				binaryNumber += to_string(number % 2);
				number /= 2;
			}
			reverse(binaryNumber.begin(), binaryNumber.end());
			//cout << "\t" << binaryNumber;

			bool palindromBinarnie = czyPalindrom(binaryNumber);

			if (palindromBinarnie) {
				cout << i << " --> " << binaryNumber << endl;
			}
		}

		//cout << endl;
	}
}