#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    int n, m; // liczba wierzchołków i krawędzi
    int v1, v2; // wierzchołek startowy i końcowy
    char** A;

    cin >> n >> m;
    A = new char* [n]; // tablica wskaźników
    vector<int>* sasiedzi = new vector<int>[n];     // 2.
    vector<int>* sasiadDla = new vector<int>[n];    // 3.
    int* sWychodzacy = new int[n](); // () --> inicjalizacja tablicy z zerami
    int* sWchodzacy = new int[n]();
    int* stopien = new int[n]();
    vector<int> petle;
    vector<int> izolowane;

    for (int i = 0; i < n; i++) {
        A[i] = new char[n]; // Tworzymy wiersze
    }

    // wypełnienie macierzy zerami
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
        
    // Odczytujemy krawędzi
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;    // Wierzchołek startowy i końcowy krawędzi
        A[v1][v2] = 1;      // Krawędź v1->v2 obecna

        // 1. ZADANIE - JEŚLI GRAF MA BYĆ NIESKIEROWANY
        //A[v2][v1] = 1;

        // 2. ZADANIE - WSZYSCY SĄSIEDZI DLA WIERZCHOŁKA
        sasiedzi[v1].push_back(v2);

        // 3. ZADANIE - WSZYSCY SĄSIEDZI DLA WIERZCHOŁKA
        sasiadDla[v2].push_back(v1);

        // 4. ZADANIE - STOPIEŃ DLA NIESKIEROWANEGO
        if (v1 != v2) {
            stopien[v1]++;
            stopien[v2]++;
        }
        else {
            stopien[v1]++;
        }

        // 5. ZADANIE - STOPIEŃ WYCHODZĄCY I WCHODZĄCY
        sWychodzacy[v1]++;
        sWchodzacy[v2]++;

        // 6. ZADANIE - PĘTLE
        if (v1 == v2) {
            petle.push_back(v1);
        }
    }

    // Wypisujemy zawartość macierzy sąsiedztwa
    cout << endl << "   ";
    for (int i = 0; i < n; i++) {
        cout << setw(3) << i;
    }
    cout << endl << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(3) << i;
        for (int j = 0; j < n; j++) {
            cout << setw(3) << (int)A[i][j];
        }
        cout << endl;
    }

    // 2. ZADANIE - WYPISANIE SĄSIADÓW
    cout << endl << "Wierzcholek i jego sasiedzi:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < sasiedzi[i].size(); j++) {
            cout << sasiedzi[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // 3. ZADANIE - WYPISANIE DLA JAKICH WIERZCHOŁKÓW DANY WIERZCHOŁEK JEST SĄSIADEM
    cout << endl << "Dla tych wierzcholkow dany wierzcholek jest sasiadem:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < sasiadDla[i].size(); j++) {
            cout << sasiadDla[i][j] << " ";
        }
        cout << endl;
    }

    // 4. ZADANIE - STOPIEŃ DLA NIESKIEROWANEGO
    /*cout << endl << "Stopien:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": " << stopien[i] << endl;
    }*/

    // 5. ZADANIE - WYPISANIE STOPNIA WYCHODZĄCEGO I WCHODZĄCEGO
    cout << endl << "Stopien wychodzacy - wchodzacy:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": " << sWychodzacy[i] << " " << sWchodzacy[i] << endl;
    }

    // 6. PĘTLE
    cout << endl << "Petle dla wierzcholkow: ";
    for (int i = 0; i < petle.size(); i++) {
        cout << petle[i] << " ";
    }

    // 6. WIERZCHOŁKI IZOLOWANE
    for (int i = 0; i < n; i++) {
        bool izolowany = true; // flaga
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1 || A[j][i] == 1) {
                izolowany = false;
            }
        }

        if (izolowany) izolowane.push_back(i);
    }

    cout << endl << "Izolowane wierzcholki: ";
    for (int i = 0; i < izolowane.size(); i++) {
        cout << izolowane[i] << " ";
    }

    // usunięcie macierzy
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;

    cout << endl;
    return 0;
}
