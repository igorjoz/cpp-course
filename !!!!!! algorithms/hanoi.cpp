#include <iostream>

using namespace std;

int counter = 0;

void hanoi(int n, char a, char b, char c) {
	if (n != 1) {
		hanoi(n - 1, a, c, b);
		cout << a << c << " ";
		hanoi(n - 1, b, a, c);
		counter++;
	}
}

int main()
{
	hanoi(3, 'A', 'B', 'C');
	cout << endl << counter;
}