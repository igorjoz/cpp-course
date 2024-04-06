#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string s1, s2;
    int i, j, p1, p2, maxLength, lengths[41][41];

    srand((unsigned)time(NULL));
    s1 = ""; s2 = "";
    for (i = 0; i < 40; i++) {
        s1 += 65 + rand() % 2;
        s2 += 65 + rand() % 2;
    }
    cout << "s1 = " << s1 << endl << "s2 = " << s2 << endl;

    // szukamy najd³u¿szego wspólnego pod³añcucha
    for (i = 0; i <= 40; i++) {
        lengths[i][0] = 0;
        lengths[0][i] = 0;
    }

    maxLength = 0;

    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            if (s1[i] != s2[j]) {
                lengths[i + 1][j + 1] = 0;
            }
            else {
                lengths[i + 1][j + 1] = 1 + lengths[i][j];

                if (lengths[i + 1][j + 1] > maxLength) {
                    maxLength = lengths[i + 1][j + 1];
                    p1 = i - maxLength + 1;
                    p2 = j - maxLength + 1;
                }
            }
        }
    }  
            


    // wynik
    cout << endl;
    if (maxLength == 0) cout << "BRAK\n";
    else {
        do {
            if (p1 > p2) {
                s2 = " " + s2; p2++;
            }
            else if (p2 > p1) {
                s1 = " " + s1; p1++;
            }
        } while (p1 != p2);

        cout << s1 << endl;

        for (i = 0; i < p1; i++) cout << " ";

        cout << s1.substr(p1, maxLength) << ": " << maxLength << endl << s2 << endl;
    }
}