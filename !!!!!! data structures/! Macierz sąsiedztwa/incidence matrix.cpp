#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n, m; // liczba wierzcho³ków i krawêdzi
    int v1, v2;

    signed char** A;

    cin >> n >> m;
    A = new signed char* [n]; // Tworzymy tablicê wskaŸników

    vector<int>* sasiedzi = new vector<int>[n];
    vector<int>* sasiadDla = new vector<int>[n];

    vector<int> petle;
    vector<int> izolowane;

    for (int i = 0; i < n; i++) {
        A[i] = new signed char[m]; // Tworzymy wiersze
    }

    // Macierz wype³niamy zerami
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = 0;
        }
    }

    // Odczytujemy kolejne definicje krawêdzi
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;    // Wierzcho³ek startowy i koñcowy krawêdzi
        A[v1][i] = 1;       // Wierzcho³ek startowy
        A[v2][i] = -1;      // Wierzcho³ek koñcowy

        // 1. ZADANIE - TRAKTOWANIE JAK GRAF NIESKIEROWANY
        //A[v2][i] = 1;

        // 2. ZADANIE - SASIÊDZI
        sasiedzi[v1].push_back(v2);

        // 3. ZADANIE - S¥SIAD DLA
        sasiadDla[v2].push_back(v1);
    }
    cout << endl;

    // Wypisujemy zawartoœæ macierzy incydencji
    cout << "   ";
    for (int i = 0; i < m; i++) {
        cout << setw(3) << i;
    }
    cout << endl << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(3) << i;
        for (int j = 0; j < m; j++) {
            cout << setw(3) << (int)A[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // 2.
    cout << endl << "Sasiedzi:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < sasiedzi[i].size(); j++) {
            cout << sasiedzi[i][j] << " ";
        }
        cout << endl;
    }

    // 3.
    cout << endl << "Sasiad dla:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < sasiadDla[i].size(); j++) {
            cout << sasiadDla[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    // 4. izolowane
    for (int i = 0; i < n; i++) {
        bool izolowany = true;
        cout << i << ": ";
        for (int j = 0; j < m; j++) {
            cout << (int)A[i][j] << " ";
            if (A[i][j] == 1) izolowany = false;
        }
        cout << endl;
        if (izolowany) izolowane.push_back(i);
    }

    // 4. dwukierunkowe
    cout << endl;
    for (int i = 0; i < (int)(n/2); i++) {
        for (int j = 0; j < sasiedzi[i].size(); j++) {
            for (int k = 0; k < sasiedzi[sasiedzi[i][j]].size(); k++) {
                if (i == sasiedzi[sasiedzi[i][j]][k]) {
                    cout << "Dwukierunkowe wierzcholki: " << sasiedzi[i][k] << " <--> " << sasiedzi[sasiedzi[i][j]][k] << endl;
                }
            }
        }
    }

    // transpozycja
    cout << endl << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << (int)A[j][i] << "\t";
        }
        cout << endl;
    }

    // 4.
    cout << endl << "Izolowane: ";
    for (int i = 0; i < izolowane.size(); i++) {
        cout << izolowane[i] << " ";
    }

    // Usuwamy macierz
    for (int i = 0; i < n; i++) delete[] A[i];
    delete[] A;

    cout << endl;
    return 0;
}
