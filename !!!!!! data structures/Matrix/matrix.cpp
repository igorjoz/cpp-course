#include <iostream>

using namespace std;

void p(int m, int n, int** A)
{
    int i, j;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) A[i][j] = (i + j) % 2;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++) cout << A[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int** A;
    int n, m;

    cin >> m >> n;
    A = new int* [m];

    for (int i = 0; i < m; i++) A[i] = new int[n];
    p(m, n, A);

    for (int iw = 0; iw < m; iw++)
        for (int ik = 0; ik < n; ik++) cin >> A[iw][ik];

    for (int i = 0; i < m; i++) delete[] A[i];
    delete[] A;

    return 0;
}