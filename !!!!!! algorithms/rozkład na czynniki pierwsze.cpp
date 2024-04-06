#include <iostream>
#include <cmath>

using namespace std;

void fermatMethod(unsigned int p)
{
    unsigned long long x, y, z, m, n;

    x = (unsigned long long)ceil(sqrt(p));

    do {
        z = x * x - p;
        y = (unsigned long long)floor(sqrt(z));
        if (z == y * y) {
            m = x + y;
            n = x - y;

            if (n == 1) break;

            fermatMethod(m);
            fermatMethod(n);

            return;
        }

        x++;
    } while (x + y < p);

    cout << p << " ";
}

int main()
{
    unsigned int p;
    cin >> p;

    /*for (int i = 2; i <= (unsigned int)(sqrt(p)); i++) {
        while (p % i == 0) {
            cout << i << " ";
            p /= i;
        }
        if (p == 1) break;
    }

    if (p > 1) cout << p;
    cout << endl;*/

    while (p % 2 == 0)
    {
        p /= 2;
        cout << 2 << " ";
    }
    if (p > 1) fermatMethod(p);
    cout << endl;
}