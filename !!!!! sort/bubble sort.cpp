#include <iostream>

using namespace std;

int const N = 7;

int main()
{
    int numbers[N] = { -5, 20, -2, 37, 8, 200, 100 };
    
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N - i - 1; k++) {
            if (numbers[k] < numbers[k + 1]) {
                int temp = numbers[k];
                numbers[k] = numbers[k + 1];
                numbers[k + 1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << numbers[i] << " ";
    }
}