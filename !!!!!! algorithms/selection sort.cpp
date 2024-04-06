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

	for (int i = n - 1; i > 0; i--) {
		int max = -1'000'000'000;
		int maxIndex = -1;

		for (int j = 0; j < i; j++) {
			if (nums[j] > max) {
				max = nums[j];
				maxIndex = j;
			}
		}

		cout << nums[maxIndex] << " " << nums[i] << endl;

		int temp = nums[i];
		nums[i] = nums[maxIndex];
		nums[maxIndex] = temp;
	}

	cout << endl;
	for (auto num : nums) {
		cout << num << " ";
	}
	cout << endl;
}