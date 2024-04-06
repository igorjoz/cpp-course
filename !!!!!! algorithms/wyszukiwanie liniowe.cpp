#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int findNum(vector<int> nums, int searchedNum) {
    /*for (auto it = nums.begin(); it != nums.end(); it++) {
        cout << *it << " ";
        if (*it == searchedNum) { }
    }*/

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == searchedNum) {
            return i;
        }
    }

    return -1;
}

int count(vector<int> nums, int searchedNum) {
    int counter = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == searchedNum) {
            counter++;
        }
    }

    return counter;
}

int findMax(vector<int> nums) {
    int maxIndex = 0;
    int maxValue = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > maxValue) {
            maxValue = nums[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

int findMin(vector<int> nums) {
    int minIndex = 0;
    int minValue = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < minValue) {
            minValue = nums[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int main()
{
    vector<int> nums = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 7, 7, 17, 1 };

    int index = findNum(nums, 23);
    cout << "index: " << index << endl;

    int counter = count(nums, 17);
    cout << "counter: " << counter << endl;

    int max = findMax(nums);
    cout << "max: " << max << endl << "maxValue: " << nums[max] << endl;

    int min = findMin(nums);
    cout << "min: " << min << endl << "minValue: " << nums[min] << endl;
}