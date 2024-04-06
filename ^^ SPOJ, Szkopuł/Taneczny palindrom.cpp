#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int prices[3]; // [1] - white, [2] - black
	int minPrice;
	
	int sum = 0;

	cin >> n;
	int* dancers = new int[n];
	cin >> prices[1] >> prices[2];
	minPrice = min(prices[1], prices[2]);

	for (int i = 0; i < n; i++) {
		cin >> dancers[i];
	}

	for (int i = 0; i < n / 2; i++) {
		if (!(dancers[i] == dancers[n - i - 1] or dancers[i] == 0 or dancers[n - i - 1])) {
			cout << "NIE" << endl;
			return 0;
		}
	}

	if (n % 2 == 1 and dancers[(int)(n / 2)] == 0) {
		sum += minPrice;
	}

	for (int i = 0; i < n / 2; i++) {
		int rightIndex = n - i - 1;
		if (dancers[i] == 0 and dancers[rightIndex] != 0) {
			sum += prices[dancers[rightIndex]];
		}
		else if (dancers[i] != 0 and dancers[rightIndex] == 0) {
			sum += prices[dancers[i]];
		}
		else if (dancers[i] == 0 and dancers[rightIndex] == 0) {
			sum += 2 * minPrice;
		}
	}

	cout << sum;

	delete[]dancers;
}