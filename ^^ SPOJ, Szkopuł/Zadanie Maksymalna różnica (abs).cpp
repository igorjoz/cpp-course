#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> nums;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        nums.insert(abs(num));
    }

    //cout << nums[n - 1] + nums;
}