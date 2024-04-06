#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int shift = 3;
    string message;

    cout << "PODAJ TEKST DO DESZYFRACJI: ";
    cin >> message;
    transform(message.begin(), message.end(), message.begin(), [](char c) { return toupper(c); });

    cout << endl << message << endl;

    for (int i = 0; i < message.length(); i++) {
        if ((int)message[i] >= 65 + shift && (int)message[i] <= 90) {
            cout << (char)((int)(message[i]) - shift);
        }
        else if ((int)message[i] >= 65 && (int)message[i] <= 65 + shift) {
            cout << (char)(90 - shift + 1 + ((int)message[i]) - 65);
        }
    }

    cout << endl;
}