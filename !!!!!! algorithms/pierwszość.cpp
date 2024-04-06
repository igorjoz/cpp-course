#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number) {
	if (number == 0 or number == 1) return false;
	else if (number == 2) return true;
	else if (number % 2 == 0) return false;

	for (int i = 3; i <= (int)(sqrt(number)); i += 2) {
		if (number % i == 0) return false;
	}

	return true;
}

int main()
{
	for (int i = 0; i < 111; i++) {
		cout << i << ": " << isPrime(i) << endl;
	}
}