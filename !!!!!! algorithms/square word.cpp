#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 20; // d³ugoœæ ³añcucha s

int main()
{
    string s;
    int i, j, k, b, b2, PI[N + 1];
    bool P[N >> 1];

    // wygenerowanie
    srand((unsigned)time(NULL));
    s = "";
    for (i = 0; i < N; i++) {
        s += char(65 + rand() % 2);
    }   

    cout << s << endl;

    // wyszukiwanie s³ów podwójnych
    for (j = 0; j < N - 1; j++) {
        PI[0] = b = -1;

        for (i = 1; i <= N - j; i++) {
            while (b > -1 && s[j + b] != s[j + i - 1]) {
                b = PI[b];
            }
                
            PI[i] = ++b; b2 = b << 1;

            if (!(i & 1)) {
                P[i >> 1] = false;

                if (b2 < i) {
                    continue;
                }

                if (b2 > i) {
                    if (b2 = b < (i << 1)) continue;
                    if (!P[(b2 - i) >> 1]) continue;
                }

                P[i >> 1] = true;

                for (k = 0; k < j; k++) {
                    cout << " ";
                }
                cout << s.substr(j, i) << endl;
            }
        }
    }
}