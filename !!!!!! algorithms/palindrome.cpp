#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 40; // d³ugoœæ ³añcucha str

int main()
{
    string str = "";

    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++) {
        str += char(65 + rand() % 5);
    }
    cout << str << endl;

    // wyszukanie palindromów
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 2; j <= N; j++) {
            int left = i;
            int right = j - 1;
            bool t = true;

            while (left < right) {
                if (str[left++] != str[right--]) {
                    t = false;
                    break;
                }
            }
                
            if (t) {
                for (int k = 0; k < i; k++) {
                    cout << " ";
                }
                cout << str.substr(i, j - i) << endl;
            }
        }
    }
}