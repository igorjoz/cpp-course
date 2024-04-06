#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int minValue = nums[i];
        int minIndex = i;

        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < minValue) {
                minValue = nums[j];
                minIndex = j;
            }
        }

        int temp = nums[i];
        nums[i] = nums[minIndex];
        nums[minIndex] = temp;
    }
}

//void sort2(int nums[], int size) {
//    for (int i = 0; i < size; i++) {
//        cout << nums[i] << endl;
//    }
//}

int main()
{
    const int SIZE = 13;
    vector<int> nums = { 2, 6, 8, 1, 23, 4, 6, 16, 8, 2, 3, 51, 7 };
    //int nums2[SIZE] = { 2, 6, 8, 1, 23, 4, 6, 16, 8, 2, 3, 51, 7 };

    selectionSort(nums);

    for (auto num : nums) {
        cout << num << " ";
    }

    /*cout << endl << "---" << endl;
    sort2(&nums2[0], SIZE);*/
}