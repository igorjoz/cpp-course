#include <iostream>

using namespace std;

int main()
{
    double a, b, c;
    double delta;

    while (cin >> a) {
        cin >> b >> c;

        delta = (b * b) - (4 * a * c);

        if (delta > 0.0) cout << 2;
        else if (delta == 0.0) cout << 1;
        else cout << 0;

        cout << endl;
    }
}