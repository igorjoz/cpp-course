#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 79;   // d³ugoœæ ³añcucha text
const int M = 4;    // d³ugoœæ wzorca key
const int zp = 65;  // kod pierwszego znaku alfabetu
const int zk = 67;  // kod ostatniego znaku alfabetu

// Funkcja obliczaj¹ca hasz dla ³añcucha x
//----------------------------------------
int hashText(string& x) {
    int hx;

    hx = 0;
    for (int i = 0; i < M; i++)
        hx = 3 * hx + (x[i] - 65);

    return hx;
}

int main()
{
    string text, key;
    int pp, Hp, Hs;

    srand((unsigned)time(NULL));
    text = "";
    for (int i = 0; i < N; i++)
        text += zp + rand() % (zk - zp + 1);
    key = "";
    for (int i = 0; i < M; i++)
        key += zp + rand() % (zk - zp + 1);

    cout << key << endl << text << endl;

    // obliczamy hasz wzorca
    Hp = hashText(key);

    // obliczamy hasz okna wzorca
    Hs = hashText(text);

    // szukamy pozycji wzorca w ³añcuchu
    pp = 0;

    int i = 0;
    while (true) {
        if ((Hp == Hs) && (key == text.substr(i, M))) {
            while (pp < i) {
                cout << " ";
                pp++;
            }
            cout << "^";
            pp++;
        }

        i++;

        if (i == N - M) break;

        Hs = (Hs - (text[i - 1] - 65) * 27) * 3 + text[i + M - 1] - 65;
    }
}