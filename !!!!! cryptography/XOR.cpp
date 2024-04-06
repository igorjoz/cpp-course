#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string text, key;

    cout << "Podaj tekst do zaszyfrowania: ";
    cin >> text;
    cout << "Podaj klucz szyfrowania: ";
    cin >> key;

    vector<char> encrypted;
    vector<char> decrypted;

    int const len = text.length();
    int const key_len = key.length();

    cout << "Text: " << text;

    cout << endl << endl << "Encryption: " << endl;

    int key_counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (key_counter == key_len) key_counter = 0;
        encrypted.push_back((char)text[i] ^ key[key_counter]);
        cout << encrypted[i];
        key_counter++;
    }

    cout << endl << endl << "Decryption:" << endl;

    key_counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (key_counter == key_len) key_counter = 0;
        decrypted.push_back((char)encrypted[i] ^ key[key_counter]);
        cout << decrypted[i];
        key_counter++;
    }

    cout << endl;

    return 0;
}