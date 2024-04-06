#include <iostream>

using namespace std;

long long fibRek(int n) {
    if (n == 1 or n == 2) return 1;
    else {
        return fibRek(n - 2) + fibRek(n - 1);
    }
}

int main()
{
    const int N = 100;

    // programowanie dynamiczne
    long long fib[N];
    fib[0] = 1;
    fib[1] = 1;

    cout << fib[0] << " " << fib[1];

    for (int i = 2; i < N; i++) {
        fib[i] = fib[i - 2] + fib[i - 1];
        cout << fib[i] << " ";
    }

    cout << endl << endl;


    // rekurencja
    for (int i = 1; i < N; i++) {
        cout << fibRek(i) << " ";
    }
}