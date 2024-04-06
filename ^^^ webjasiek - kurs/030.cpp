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
Stwórz funkcjê, która sprawdza, czy z podanego s³owa (napisu/string) zawieraj¹cego ma³e litery alfabetu angielskiego mo¿na u³o¿yæ palindrom? Palindrom ma zawieraæ tyle samo znaków co oryginalne s³owo, ale mo¿na dowolnie przestawiaæ znaki w s³owie. Np.:
"aabbcc" -> mo¿na -> "abccba"


*/









bool potencjalnyPalindrom(const string& s³owo) {
	// 1) mo¿na sprawdziæ wszystkie mo¿liwe kombinacje szukaj¹c palindromu
	// 2) mo¿na sprawdziæ czy istnieje symetria (ka¿dy znak musi mieæ parzyst¹ iloœæ wyst¹pieñ, ewentualnie jeden znak nie musi - o ile jest taki jeden (bêdzie na œrodku)).
	// uwaga! za³ó¿my, ¿e nie znam kontenerów STL
	int znaki[300]{}; // ka¿d znak char to tak naprawdê liczba, wiêc mo¿e byæ ona indeksem w tablicy
	for (auto& znak : s³owo) {
		znaki[(int)znak]++;
	}
	if (s³owo.size() % 2 == 0) { // palindrom z parzystej iloœci znaków
		for (auto ile : znaki) {
			if (ile % 2 == 1) return false;
		}
	}
	else {
		int znakiOnieparzystejIloœci = 0;
		for (auto ile : znaki) {
			if (ile % 2 == 1 && znakiOnieparzystejIloœci++ >= 1) return false;
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
