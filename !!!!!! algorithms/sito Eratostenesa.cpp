#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned int n;

    cin >> n;
    bool* isPrime = new bool[n + 1];

    for (int i = 2; i <= n; i++) isPrime[i] = true;

    for (int i = 2; i <= (unsigned int)(sqrt(n)); i++) {
        if (isPrime[i]) {
            unsigned int w = i * i;
            while (w <= n) {
                isPrime[w] = false;
                w += i;
            }
        }
    }
        
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) cout << i << " ";
    }

    delete[] isPrime;





    /*unsigned int p = 3, q = 4, n, m;

    cin >> n;
    if (n & 1) {
        n++;
    }
    m = n >> 1;

    bool* isPrime = new bool[m + 1];

    for (int i = 1; i < m; i++) isPrime[i] = true;

    int i = 1;

    do {
        if (isPrime[i]) {
            int k = q;
            while (k < m) {
                isPrime[k] = false;
                k += p;
            }
        }
        i++;
        p += 2;
        q += (p << 1) - 2;
    } while (q < m);

    cout << 2 << " ";

    for (i = 1; i < m; i++) {
        if (isPrime[i]) cout << (i << 1) + 1 << " ";
    }

    delete[] isPrime;*/
}