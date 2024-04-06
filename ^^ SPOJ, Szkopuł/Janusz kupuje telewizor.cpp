#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
    long long maxWidth, maxHeight;
    long long ratioWidth, ratioHeight;

    cin >> maxWidth >> maxHeight >> ratioWidth >> ratioHeight;

    long long gcdValue = gcd(ratioWidth, ratioHeight);
    ratioWidth /= gcdValue;
    ratioHeight /= gcdValue;

    cerr << gcdValue << endl;
    cerr << ratioWidth << " " << ratioHeight << endl;

    long long widthPossibilities = maxWidth / ratioWidth;
    long long heightPossibilities = maxHeight / ratioHeight;

    cout << min(widthPossibilities, heightPossibilities) << endl;
}