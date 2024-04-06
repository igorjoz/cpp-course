#include <iostream>

using namespace std;

int binarySearch(int nums[], int length, int searchedNumber) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (nums[middle] == searchedNumber) {
            return middle;
        }
        else if (nums[middle] < searchedNumber) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return -1;
}

int main()
{
    const int QUANTITY = 20;
    int nums[QUANTITY] = {
        1, 1, 1, 3, 4,
        10, 20, 22, 30, 31,
        40, 50, 51, 56, 78,
        102, 103, 104, 222, 921
    };

    int searchedNumber = 222;

    for (auto num : nums) cout << num << " ";
    cout << endl;


    int searchedNumberIndex = binarySearch(nums, QUANTITY, searchedNumber);


    if (searchedNumberIndex != -1) {
        cout << nums[searchedNumberIndex] << " pod indeksem " << searchedNumberIndex;
    }
    else {
        cout << "nie znaleziono liczby " << searchedNumber;
    }
    cout << endl;
}