#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 40;

int main()
{
    int nums[N], maxValues[11], k, x;

    srand((unsigned)time(NULL));

    for (int i = 0; i < N; i++) {
        nums[i] = rand() % 100;
    }
    k = 5 + (rand() % 6);

    for (int i = 0; i < k; i++) {
        maxValues[i] = -1;
    }
    maxValues[k] = 1000;


    for (int i = 0; i < N; i++) {
        int j;
        x = nums[i];
        for (j = -1; x > maxValues[j + 1]; ) {
            j++; maxValues[j] = maxValues[j + 1];
        }
        if (j >= 0) {
            maxValues[j] = x;
        }
    }


    for (int i = 0; i < N; i++) {
        cout << setw(4) << nums[i];
    }
    cout << endl;

    cout << "k = " << k << ": ";
    for (int i = 0; i < k; i++) cout << setw(4) << maxValues[i] << endl;
}