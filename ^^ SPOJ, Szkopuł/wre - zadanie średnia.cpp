#include <iostream>

using namespace std;

int main()
{
    int n;
    int* nums;
    int left, right;
    long long sum = 0;

    cin >> n;
    nums = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> left >> right;

    for (int i = left - 1; i < right; i++) {
        sum += nums[i];
    }

    cout << (int)(sum / (right - left + 1));

    delete[] nums;
}