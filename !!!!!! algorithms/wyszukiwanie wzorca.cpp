#include <iostream>

using namespace std;

int main()
{
    string text = "Igor i Wiktor wyruszyli na wycieczke, a dokladnie na grzybobranie; eee; geer weezy i dook";
    string pattern = "ru";

    cout << text << endl;
    int cooldown = 0;

    for (int i = 0; i < text.length() - pattern.length() + 1; i++) {
        if (!cooldown) {
            if (text.substr(i, pattern.length()) == pattern) {
                cout << "^";
                cooldown = pattern.length() - 1;

                for (int k = 0; k < pattern.length() - 1; k++) {
                    cout << "-";
                }
            }
            else {
                cout << " ";
            }
        }
        else {
            cooldown--;
        }
    }

    cout << endl;

    for (int i = 0; i < text.length() - pattern.length() + 1; i++) {
        if (text.substr(i, pattern.length()) == pattern) {
            cout << "znaleziono" << endl;
        }
    }


    //for (int i = pattern.length() - 1; i < text.length(); i++) {
    //    //cout << text[i];
    //    for (int j = 0; j < pattern.length(); j++) {
    //        cout << text[i - pattern.length() + 1 + j] << " " << pattern[j] << "\t";
    //        if (text[i - pattern.length() + 1 + j] == pattern[j]) {
    //            cout << "ok" << "\t";
    //        }
    //        else {
    //            cout << "nie, koniec";
    //            break;
    //        }
    //    }
    //    cout << endl;
    //}


    //setlocale(LC_ALL, "");
    //cout << "æip æip ¿abo\n";
    //cout << "za¿ó³æ gêœl¹ jaŸñ\n";
}