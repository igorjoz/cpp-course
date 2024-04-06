#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long students, candies;
		cin >> students >> candies;

		students--; // odjêcie Jasia

		if (students != 0 && candies % students == 0) cout << "NIE" << endl;
		else cout << "TAK" << endl;
	}
}