#include <iostream>

using namespace std;

int main()
{
    string text = "slimakls";
    int length = text.length();

    int counter = 0;
    string maxBorder = "";

    for (int i = 0; i < length; i++) {
        if (text[i] == text[length - i - 1]) {
            counter++;
            maxBorder += text[i];
        }
        else {
            break;
        }
    }

    cout << "\"" << maxBorder << "\""<< endl << counter;
}