#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string text) {
    int length = text.length();
    for (int i = 0; (int)(i < length / 2); i++) {
        if (text[i] != text[length - i - 1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    // mo¿na u¿yæ wektora do przechowania liczb, ale zajê³oby to wiêcej miejsca ni¿ dynamiczne zaalokowanie tablicy (lepiej u¿yæ tablicy, gdy znana jest liczba elementów)
    string * numbersStr = new string [n];

    vector<string> palindromes;

    for (int i = 0; i < n; i++) {
        cin >> numbersStr[i];

        if (isPalindrome(numbersStr[i])) {
            palindromes.push_back(numbersStr[i]);
        }
    }

    int palindromesQuantity = palindromes.size();
    if (palindromesQuantity == 0) {
        cout << "Brak" << endl;
    }
    else {
        for (int i = 0; i < palindromesQuantity; i++) {
            cout << palindromes[i] << endl;
        }
    }
}
