#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 40; // d³ugoœæ ³añcucha s

int main()
{
    string s;
    int rp, R[2][N + 1];

    // wygenerowanie
    srand((unsigned)time(NULL));
    s = "";
    for (int i = 0; i < N; i++) {
        s += char(65 + rand() % 4);
    }
    cout << s << endl;

    // wyszukanie palindromów
    s = "@" + s + "#"; // wartownicy

    for (int j = 0; j <= 1; j++) {
        R[j][0] = rp = 0;
        int i = 1;
        while (i <= N) {
            while (s[i - rp - 1] == s[i + j + rp]) {
                rp++;
            }

            R[j][i] = rp;
            int k = 1;

            while (R[j][i - k] != rp - k && k < rp) {
                R[j][i + k] = min(R[j][i - k], rp - k);
                k++;
            }

            rp = max(rp - k, 0);
            i += k;
        }
    }

    s = s.substr(1, N); // usuniêcie wartowników

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 1; j++) {
            for (rp = R[j][i]; rp > 0; rp--) {
                for (int k = 1; k < i - rp; k++) {
                    cout << " ";
                }
                cout << s.substr(i - rp - 1, 2 * rp + j) << endl;
            }
        }
            
    }
}