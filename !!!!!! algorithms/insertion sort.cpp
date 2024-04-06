#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums = { 10, 12, 15, -20, -3, 73, 31, 200, -100, 44 };
	int n = nums.size();

	for (auto num : nums) {
		cout << num << " ";
	}
	cout << endl;

	for (int i = 1; i < n; i++) {
		if (nums[i] < nums[i - 1]) {
			int temp = nums[i];

			int j;
			for (j = i - 1; j >= 0 and nums[j] > temp; j--) {
				nums[j + 1] = nums[j];
			}
			nums[j + 1] = temp;
		}
	}

	for (auto num : nums) {
		cout << num << " ";
	}
	cout << endl;
}