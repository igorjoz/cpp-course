#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int* A = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = k; i < n; i++) {
        cout << A[i] << " ";
    }

    for (int i = 0; i < k; i++) {
        cout << A[i] << " ";
    }
}