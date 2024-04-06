#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <stack>
#include <typeinfo>
#include <string>
#include <ctime>
#include "numbers.h"

// C++17

using namespace std;


/*
Zadanie 66. z poziomu fundamentalnego.
Stw�rz funkcj�, kt�ra sprawdza, czy z podanego s�owa (napisu/string) zawieraj�cego ma�e litery alfabetu angielskiego mo�na u�o�y� palindrom? Palindrom ma zawiera� tyle samo znak�w co oryginalne s�owo, ale mo�na dowolnie przestawia� znaki w s�owie. Np.:
"aabbcc" -> mo�na -> "abccba"


*/









bool potencjalnyPalindrom(const string& s�owo) {
	// 1) mo�na sprawdzi� wszystkie mo�liwe kombinacje szukaj�c palindromu
	// 2) mo�na sprawdzi� czy istnieje symetria (ka�dy znak musi mie� parzyst� ilo�� wyst�pie�, ewentualnie jeden znak nie musi - o ile jest taki jeden (b�dzie na �rodku)).
	// uwaga! za��my, �e nie znam kontener�w STL
	int znaki[300]{}; // ka�d znak char to tak naprawd� liczba, wi�c mo�e by� ona indeksem w tablicy
	for (auto& znak : s�owo) {
		znaki[(int)znak]++;
	}
	if (s�owo.size() % 2 == 0) { // palindrom z parzystej ilo�ci znak�w
		for (auto ile : znaki) {
			if (ile % 2 == 1) return false;
		}
	}
	else {
		int znakiOnieparzystejIlo�ci = 0;
		for (auto ile : znaki) {
			if (ile % 2 == 1 && znakiOnieparzystejIlo�ci++ >= 1) return false;
		}
	}
	return true;
}

void _030() {
	setlocale(LC_ALL, ""); 
	//srand(time(0));
	srand(100);

	cout << potencjalnyPalindrom("a") << endl;
	cout << potencjalnyPalindrom("abc") << endl;
	cout << potencjalnyPalindrom("abb") << endl;
	cout << potencjalnyPalindrom("aab") << endl;
	cout << potencjalnyPalindrom("abcd") << endl;
	cout << potencjalnyPalindrom("aabb") << endl;
	cout << potencjalnyPalindrom("aabbcccc") << endl;
	cout << potencjalnyPalindrom("aabbccccd") << endl;
	cout << potencjalnyPalindrom("aabbccccde") << endl;
	cout << potencjalnyPalindrom("aabbccccddeeeee") << endl; // 5e
	cout << potencjalnyPalindrom("aaabbbb") << endl;
	cout << potencjalnyPalindrom("aaabbbccc") << endl;

}
