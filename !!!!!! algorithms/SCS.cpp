#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string S[8], P[8];
    int i, j, maxps, ps, sp, ss, k, ii;

    // generujemy generacja
    srand((unsigned)time(NULL));
    for (i = 0; i < 8; i++) {
        k = 3 + rand() % 8;
        S[i] = "";

        for (j = 0; j < k; j++) {
            S[i] += char(65 + rand() % 2);
        }

        cout << "S [ " << i << " ] = " << S[i] << endl;
        P[i] = S[i];
    }

    // wyznacz SCS
    for (k = 8; k > 1; k--) {
        maxps = -1;
        for (i = 0; i < k; i++) {
            for (j = 0; j < k; j++) {
                if (i != j) {
                    ii = S[i].length() - S[j].length();

                    if (ii < 0) {
                        ii = 0;
                    }

                    ps = 0;
                    S[i] += '@';  // wartownik1
                    S[j] += '#';  // wartownik2

                    while (S[i][ii] != '@') {
                        while (S[i][ii + ps] == S[j][ps]) ps++;
                        if (S[i][ii + ps] == '@') break;
                        ps = 0;
                        ii++;
                    }

                    S[i].erase(S[i].length() - 1, 1);
                    S[j].erase(S[j].length() - 1, 1);

                    if (ps > maxps) {
                        maxps = ps;
                        sp = j;
                        ss = i;
                    }
                }
            }
        }

        S[ss] += S[sp].substr(maxps, S[sp].length() - maxps);
        S[sp] = S[k - 1];
    }

    cout << endl;

    // wypisujemy ³añcuchy odpowiednio przesuniête
    // zapamiêtujemy równie¿ maksymaln¹ ostatni¹ pozycjê
    maxps = 0;
    for (i = 0; i < 8; i++) {
        cout << "S [ " << i << " ] =";

        ps = S[0].find(P[i]);

        for (j = 0; j <= ps; j++) {
            cout << " ";
        }

        cout << P[i] << endl;
        ps += P[i].length();

        if (ps > maxps) {
            maxps = ps;
        }
    }

    // optymalizujemy SCS
    S[0].erase(maxps, S[0].length() - maxps);
    cout << "          " << S[0];
}