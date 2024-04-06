#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    return a == 0 ? b : gcd(a % b, a);
}

int main()
{
    long a, b;

    cin >> a >> b;

    cout << gcd(a, b) << endl;
}