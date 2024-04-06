#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double n, eps, a, b;
    cout << "liczba do pierwiastokowania: ";
    cin >> n;

    cout << "Jaka ma być dokładność? ";
    cin >> eps;

    a = 0;
    b = n;

    while (abs(b - a) > eps) {
        double c = (a + b) / 2;
        if (c * c > n) b = c;
        if (c * c < n) a = c;
        if (c * c == n) a = b = c;
    }
    cout << "Pierwiastek z " << n << " mieści się w przedziale <" << a << ", " << b << ">";
}