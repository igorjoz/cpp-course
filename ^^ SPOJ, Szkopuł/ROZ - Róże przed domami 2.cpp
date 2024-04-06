#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    3 kolory - a, b, c (można uogólnić i użyć tablicy)
    ceny są różne dla poszczególnych setów domów i wybranego koloru
    żadni SĄSIEDZI nie mogą mieć tych samych kolorów
        1 set -> 2 set -> 3 set -> 4 set
            1 to sąsiad 2
            2 to sąsiad 1 i 3
            3 to sąsiad 2 i 4
            4 to sąsiad 3
    wyjście: minimalny koszt wykonania usługi
*/

int main()
{
    int n; // ilość setów domów
    int minA = 0, minB = 0, minC = 0; // suma - najmniejszy koszt zaczynając od a lub b lub c

    cin >> n;
    int* a = new int[n];
    int* b = new int[n];
    int* c = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // obliczanie najtańszej drogi, rozpoczyna się od wyjścia z 3 różnych możliwych początków
    for (int i = 0; i < n; i++) {
        // zmienne tymczasowe, aby nie nadpisać danych potrzebnych do kolejnych obliczeń
        int tempA = a[i] + min(minB, minC);
        int tempB = b[i] + min(minA, minC);
        int tempC = c[i] + min(minA, minB);

        // odebranie wyników z tymczasowych zmiennych
        minA = tempA;
        minB = tempB;
        minC = tempC;
    }

    // wynikiem jest minimalna droga spośród 3 obliczonych możliwych minimalnych dróg
    cout << min(min(minA, minB), minC);
}

/*
Wejście:
2
1 2 3
3 4 2

Wyjście:
3
*/


/*
Wejście:
2
1 2 3
3 10 12

Wyjście:
5
*/