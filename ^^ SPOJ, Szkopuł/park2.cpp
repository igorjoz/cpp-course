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

    int maxLeft = heights[0];
    int maxRight = *max_element(heights, heights + length);

    for (int i = 0; i < length; i++) {
        if (maxLeft <= heights[i]) {
            maxLeft = *max_element(heights, heights + i + 1);
            //cout << "jest maxLeft" << endl;
        }
        if (maxRight <= heights[i] || maxRight == heights[i - 1]) {
            maxRight = *max_element(heights + i, heights + length);
            //cout << "jest maxRight" << endl;
        }

        cout << maxLeft << " " << maxRight << endl;

        //cout << *max_element(heights, heights + i + 1) << " " << *max_element(heights + i, heights + length) << endl;
    }
}