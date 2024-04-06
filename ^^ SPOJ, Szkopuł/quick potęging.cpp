#include <iostream>

using namespace std;

int main()
{
	int n;
	string num;
	long long pow;

	int pow2[4] = { 2, 4, 8, 6 };
	int pow3[4] = { 3, 9, 7, 1 };
	int pow4[2] = { 4, 6 };
	int pow7[4] = { 7, 9, 3, 1 };
	int pow8[4] = { 8, 4, 2, 6 };
	int pow9[2] = { 9, 1 };

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num >> pow;
		char c = num.back();

		if (pow == 0) cout << 1;
		else {
			pow--;

			if (c == '0') cout << 0;
			else if (c == '1') cout << 1;
			else if (c == '2') cout << pow2[pow % 4];
			else if (c == '3') cout << pow3[pow % 4];
			else if (c == '4') cout << pow4[pow % 2];
			else if (c == '5') cout << 5;
			else if (c == '6') cout << 6;
			else if (c == '7') cout << pow7[pow % 4];
			else if (c == '8') cout << pow8[pow % 4];
			else if (c == '9') cout << pow9[pow % 2];
		}
		cout << "\n";
	}
}