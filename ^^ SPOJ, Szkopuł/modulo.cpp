#include <iostream>

using namespace std;

int main()
{
    int const MOD_VALUE = 37;
    int counter = 0;
    bool doesOccur[MOD_VALUE] = { false };

    for (int i = 0; i < 15; i++) {
        int num;
        int modValue;

        cin >> num;
        doesOccur[num % MOD_VALUE] = true;
    }

    for (int i = 0; i < MOD_VALUE; i++) {
        if (doesOccur[i] == true) counter++;
    }

    cout << counter << endl;
}