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

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[i]) {
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
			}
		}
	}

	for (auto num : nums) {
		cout << num << " ";
	}
	cout << endl;
}