#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num = -1;
    vector<int> nums;

    while (num != 0) {
        cin >> num;

        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    for (auto num : nums) {
        cout << num << endl;
    }
}