#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(string n1, string n2) {
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	string sum = "";
	bool addOne = false;

	if (n1.length() < n2.length()) {
		string temp = n1;
		n1 = n2;
		n2 = temp;
	}
	int maxLength = n1.length();
	int minLength = n2.length();
	int difference = maxLength - minLength;

	int i;
	for (i = 0; i < minLength; i++) {
		int addedDigits = (n1[i] - '0') + (n2[i] - '0') + addOne;

		//cout << addedDigits << " ";
		//cout << (n1[i] - '0') << " " << (n2[i] - '0') << " " << addOne << "\t";

		if (addedDigits < 10) {
			sum += to_string(addedDigits);
			addOne = false;
		}
		else {
			sum += to_string(addedDigits - 10);
			addOne = true;
		}
	}

	for (int j = 0; j < difference; j++) {
		int addedDigits = (n1[i] - '0') + addOne;

		//cout << addedDigits << " ";
		//cout << (n1[i] - '0') << " " << addOne << "\t";

		if (addedDigits < 10) {
			sum += to_string(addedDigits);
			addOne = false;
		}
		else {
			sum += to_string(addedDigits - 10);
			addOne = true;
		}
		i++;
	}

	if (addOne) {
		sum += '1';
		//cout << " +1";
	}

	reverse(sum.begin(), sum.end());
	return sum;
}

int main()
{
	int quantityOfActions;
	cin >> quantityOfActions;

	for (int i = 0; i < quantityOfActions; i++) {
		string n1, n2;
		cin >> n1 >> n2;

		cout << add(n1, n2) << endl;
	}
}