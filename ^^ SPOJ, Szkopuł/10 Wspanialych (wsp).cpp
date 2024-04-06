#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* numbers = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + n, greater<int>());

    int counter = 0;
    for (int i = 0; i < n; i++) {
        counter++;
        cout << numbers[i] << " ";
        if (counter == 10) break;
    }
}