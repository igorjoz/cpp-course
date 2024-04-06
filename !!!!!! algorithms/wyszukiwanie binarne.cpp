#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 100;

int main()
{
    int Z[N], i, ip, ik, isr, k, L, p;

    srand((unsigned)time(NULL));
    Z[0] = rand() % 5;
    for (i = 1; i < N; i++) Z[i] = Z[i - 1] + (rand() % 5);

    k = Z[0] + (rand() % (Z[N - 1] - Z[0] + 1));

    // wyszukiwanie binarne
    p = -1;
    L = 0;
    ip = 0;
    ik = N - 1;
    while (ip <= ik) {
        L++;
        isr = (ip + ik) >> 1; // right shift - dzielenie przez: 2^x
        if (Z[isr] == k) {
            p = isr;
            break;
        }
        else if (k < Z[isr]) ik = isr - 1;
        else ip = isr + 1;
    }

    // wyœwietlenie wyniku
    cout << k << ": ";
    if (p >= 0) {
        cout << p;
    }
    else {
        cout << "BRAK";
    }  

    cout << ": obiegi = " << L << endl << endl;

    for (i = 0; i < N; i++) {
        cout << setw(3) << Z[i];
        if (p == i) cout << "<";
        else cout << " ";
    }
    cout << endl << endl;

    return 0;
}