#include <iostream>

using namespace std;

typedef unsigned long long ulong;

// Funkcja mnoży a i b mod n
//--------------------------
ulong multiplyMod(ulong a, ulong b, ulong n) {
    ulong m, w;

    w = 0;
    m = 1;

    while (m)
    {
        if (b & m) w = (w + a) % n;
        a = (a << 1) % n;
        m <<= 1;
    }

    return w;
}

// Funkcja oblicza 2^e mod n
//--------------------------
ulong powerMod(ulong e, ulong n)
{
    ulong m, p, w;

    p = 2;
    w = m = 1;

    while (m)
    {
        if (e & m) w = multiplyMod(w, p, n);
        p = multiplyMod(p, p, n);
        m <<= 1;
    }

    return w;
}

int main()
{
    ulong p;

    cin >> p;
    cout << (powerMod(p, p) == 2 ? "TAK" : "NIE") << endl;
}