#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string skoder, slamacz, sklucz, sk;
    int i, j, runda;

    srand((unsigned)time(NULL));
    skoder = "";
    for (i = 0; i < 4; i++) {
        skoder += char(65 + rand() % 6);
    }

    for (runda = 1; runda <= 6; runda++) {

        // odczytujemy kod ³amacza
        cout << "Runda " << runda << ": ";
        cin >> slamacz;

        // normalizujemy kod ³amacza
        while (slamacz.length() < 4) {
            slamacz += slamacz + '$';
        }
            
        // generujemy kod klucza
        sk = skoder; // kopia robocza kodu kodera
        sklucz = "";
        for (i = 0; i < 4; i++) {
            if (sk[i] == slamacz[i]) {
                sklucz += 'x';
                sk[i] = '#';      // wartownik w1
                slamacz[i] = '$'; // wartownik w2
            }
        }
            
        for (i = 0; i < 4; i++) {
            if (sk[i] != '#') {
                for (j = 0; j < 4; j++) {
                    if (sk[i] == slamacz[j]) {
                        sklucz += 'o';
                        slamacz[j] = '$'; // wartownik w2
                        break;
                    }
                }     
            }     
        }
            

        // wyœwietlamy kod klucza
        cout << "               : " << sklucz << endl;

        // jeœli odgadniêto kod kodera, koñczymy
        if (sklucz == "xxxx") break;
    }

    cout << "KOD     : " << skoder;
}