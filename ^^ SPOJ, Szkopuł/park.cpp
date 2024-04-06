#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int length;
    cin >> length;
    int* heights = new int[length];

    for (int i = 0; i < length; i++) {
        cin >> heights[i];
    }

    for (int i = 0; i < length; i++) {
        cout << *max_element(heights, heights + i + 1) << " " << *max_element(heights + i, heights + length) << endl;
    }
}