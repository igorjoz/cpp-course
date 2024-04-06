#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int textLength = 79;
const int keyLength = 5;

int main()
{
    string text, key;
    int KMPNext[keyLength + 1];
    int matchingPrefixLength, keyPosition;

    srand((unsigned)time(NULL));
    text = "";
    for (int i = 0; i < textLength; i++) text += 65 + rand() % 2;
    key = "";
    for (int i = 0; i < keyLength; i++) key += 65 + rand() % 2;

    // obliczenie KMPNext[] (dla wzorca) 
    KMPNext[0] = matchingPrefixLength = -1;
    for (int i = 1; i < keyLength + 1; i++) {
        while ((matchingPrefixLength > -1) && (key[matchingPrefixLength] != key[i - 1])) {
            matchingPrefixLength = KMPNext[matchingPrefixLength];
        }

        matchingPrefixLength++;

        if ((i == keyLength) || (key[i] != key[matchingPrefixLength])) {
            KMPNext[i] = matchingPrefixLength;
        }
        else {
            KMPNext[i] = KMPNext[matchingPrefixLength];
        }
    }

    cout << key << endl << text << endl;

    // szukaj wzorca w ³añcuchu
    keyPosition = matchingPrefixLength = 0;
    for (int i = 0; i < textLength; i++) {
        while ((matchingPrefixLength > -1) && (key[matchingPrefixLength] != text[i])) {
            matchingPrefixLength = KMPNext[matchingPrefixLength];
        }

        if (++matchingPrefixLength == keyLength) {
            while (keyPosition < i - matchingPrefixLength + 1) {
                cout << " ";
                keyPosition++;
            }
            cout << "^";
            keyPosition++;
            matchingPrefixLength = KMPNext[matchingPrefixLength];
        }
    }
}