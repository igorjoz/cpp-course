#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> heights;
    int counter = 1; // first is already counted

    int n;
    cin >> n;
    int* steps = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> steps[i];
    }

    for (int i = 1; i < n; i++) {
        if (steps[i] == 1) {
            counter++;
            heights.push_back(steps[i - 1]);
        }
    }
    heights.push_back(steps[n - 1]);

    cout << counter << endl;
    for (auto height : heights) cout << height << " ";
}