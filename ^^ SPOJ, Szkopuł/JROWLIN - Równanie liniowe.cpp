#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c;
	double rightSide, result;

	while (cin >> a >> b >> c) {
		if (a != 0.0) {
			rightSide = c - b;
			result = rightSide / a;

			cout << fixed << setprecision(2) << result;
		}
		else if (b == c) {
			cout << "NWR";
		}
		else {
			cout << "BR";
		}

		cout << endl;
	}
}