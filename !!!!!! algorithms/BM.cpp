// Wyszukiwanie wzorca algorytmem BM
// Data:  6.06.2008
// (C)2020 mgr Jerzy Wa³aszek
//----------------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int textLength = 79;  // d³ugoœæ ³añcucha text
const int keyLength = 5;  // d³ugoœæ wzorca key
const int zp = 65;  // kod pierwszego znaku alfabetu
const int zk = 66;  // kod ostatniego znaku alfabetu

int main()
{
    string text, key;
    int Last[zk - zp + 1], textPosition;

    srand((unsigned)time(NULL));
    text = "";
    for (int i = 0; i < textLength; i++) text += zp + rand() % (zk - zp + 1);
    key = "";
    for (int i = 0; i < keyLength; i++) key += zp + rand() % (zk - zp + 1);

    cout << key << endl << text << endl;

    // oblicz Last[] dla wzorca 
    for (int i = 0; i <= zk - zp; i++) Last[i] = -1;
    for (int i = 0; i < keyLength; i++) {
        Last[key[i] - zp] = i;
    }

    // szukaj wzorca w ³añcuchu
    int i, j;
    textPosition = i = 0;

    while (i <= textLength - keyLength) {
        j = keyLength - 1;

        while ((j > -1) && (key[j] == text[i + j])) j--;

        if (j == -1) {
            while (textPosition < i) {
                cout << " ";
                textPosition++;
            }

            cout << "^";
            textPosition++;
            i++;
        }

        else {
            i += max(1, j - Last[text[i + j] - zp]);
        }
    }
}