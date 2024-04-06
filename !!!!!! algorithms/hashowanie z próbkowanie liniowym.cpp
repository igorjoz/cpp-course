#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int hf(string s) {
    unsigned int h, i;

    h = 0;
    for (i = 0; i < s.length(); i++) {
        h = 2 * h + 1 - (s[i] & 1);
    }
        
    return h % 10;
}

string s4(int x)
{
    string s = "";
    int m = 8;  // Maska bitowa
    while (m) {
        s += (x & m) ? 'B' : 'A';
        m >>= 1;
    }

    return s;
}

int main()
{
    string T[10], s;
    int i, j, h, c, p;

    srand(time(NULL));

    // Zerujemy tablicę haszowaną
    for (i = 0; i < 10; i++) T[i] = "";

    // Tablicę wypełniamy łańcuchami
    for (i = 0; i < 10; i++) {
        // Generujemy losowy łańcuch z 4 znaków A, B
        s = s4(rand() % 16);

        // Łańcuch umieszczamy w tablicy haszowanej
        h = hf(s);
        j = h;
        while (true) {
            if (T[j] == "") {
                T[j] = s;
                break;
            }
            if (T[j] == s) break;
            j = (j + 1) % 10;
            if (j == h) break;
        }
    }

    // Wyświetlamy zawartość tablicy wraz z wartością funkcji haszującej
    for (i = 0; i < 10; i++) {
        cout << "T [ " << i << " ] = ";
        if (T[i] != "") cout << T[i] << " hf( ) = " << hf(T[i]);
        else           cout << "-";
        cout << endl;
    }

    cout << endl;

    // Sprawdzamy obecność łańcuchów w tablicy haszowanej
    for (i = 0; i < 16; i++) {
        s = s4(i);  // Łańcuch
        h = hf(s);  // Hasz łańcucha
        c = 0;      // Licznik obiegów
        j = h;
        p = -1;
        while (true) {
            if (T[j] == "") break;
            if (T[j] == s) {
                p = j; break;
            };
            j = (j + 1) % 10;
            if (j == h) break;
            c++;
        }

        // Wyświetlamy wyniki
        cout << s << " hf( ) = " << h << " c = " << c << " ";
        if (p > -1) cout << "is in T [ " << p << " ] ";
        else       cout << "-";
        cout << endl;
    }

    cout << endl;

    return 0;
}