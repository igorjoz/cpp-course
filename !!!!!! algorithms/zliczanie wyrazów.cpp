#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;
    int counter = 0;
    char c;
    bool isNewWord = true;

    getline(cin, text);

    for (int i = 0; i < text.length(); i++) {
        c = text[i];

        if (((c >= '0') && (c <= '9')) || (c == '_') || (c == '-') ||
            ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ||
            (c == 164) || (c == 165) || (c == 143) || (c == 134) ||
            (c == 168) || (c == 169) || (c == 157) || (c == 136) ||
            (c == 227) || (c == 228) || (c == 224) || (c == 162) ||
            (c == 151) || (c == 152) || (c == 141) || (c == 171) ||
            (c == 189) || (c == 190)) {
            if (isNewWord) {
                isNewWord = false;
                counter++;
            }
        }
        else {
            isNewWord = true;
        }
    }

    cout << counter;
}