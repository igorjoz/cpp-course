#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// This makes the sort be according to column 2 and ascending
bool sortFunc(const vector<int>& p1,
    const vector<int>& p2) {
    return p1[1] < p2[1];
}

int main() {

    srand(time(NULL));

    // Creates and initializes 10 x 4 vector
    vector< vector<int> > vec;
    for (int i = 0; i < 10; i++) {
        vector<int> tmpVec;
        for (int j = 0; j < 2; j++) {
            tmpVec.push_back(rand() % 10);
        }
        vec.push_back(tmpVec);
    }

    // Print out the pre-sorted vector
    cout << "Pre-sorting state:" << endl;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Do the sorting according to column 2
    sort(vec.begin(), vec.end(), sortFunc);

    // Print out the sorted vector
    cout << "Pre-sorting state:" << endl;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}