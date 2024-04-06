#include <iostream>

using namespace std;

int main()
{
    const int N = 20;

    int nums[N] = {
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20
    };

    int nums2[N] = {
        -5, 3, 8, 12, 4,
        -7, -2, 1, 0, -6,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    };

    int sums[N];

    sums[0] = 0;
    for (int i = 1; i < N; i++) {
        sums[i] = sums[i - 1] + nums2[i - 1];
        cout << sums[i] << " ";
    }
}