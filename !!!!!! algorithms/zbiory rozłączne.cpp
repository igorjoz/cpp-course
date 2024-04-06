#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10;                 // Liczba elementów

int R[N];

// Łączy dwa podzbiory w jeden
//----------------------------
void Union(int x, int y)
{
    int rx, ry, i;

    rx = R[x];                   // Wyznaczamy reprezentanta zbioru zawierającego x
    ry = R[y];                   // i reprezentanta zbioru zawierającego y
    if (rx != ry)                  // Łączenie wymaga różnych zbiorów
        for (i = 0; i < N; i++)      // Przeglądamy kolejne elementy tablicy R
            if (R[i] == ry) R[i] = rx; // i zastępujemy w nich reprezentanta ry przez rx
}

// **********************
// *** PROGRAM GŁÓWNY ***
// **********************

int main()
{
    int i, j, x, y, c;

    srand(time(NULL));
    for (i = 0; i < N; i++) {
        R[i] = i;
    }
    for (i = 0; i < N; i++) {
        x = rand() % N;              // Generujemy losowe x i y
        y = rand() % N;
        Union(x, y);               // Łączymy zbiory
    }

    c = 0;                          // Licznik podzbiorów w R

    // Wyświetlamy wyniki

    for (i = 0; i < N; i++) {
        if (R[i] == i) c++;         // Zliczamy reprezentantów
        cout << i << " is in set " << R[i] << endl;
    }

    cout << endl << "Number of sets = " << c << endl << endl;

    for (i = 0; i < N; i++) {
        if (R[i] == i) {
            cout << "Set " << i << ": ";
            for (j = 0; j < N; j++)
                if (R[j] == i) cout << j << " ";
            cout << endl;
        }
    }
}