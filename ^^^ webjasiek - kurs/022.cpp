#include <iostream>
#include <array> // tablica
#include <vector> // wektor
#include <deque> // kolejka z dwoma ko�cami
#include <list> // lista
#include <forward_list> // lista jednokierunkowa
#include <set> // zbi�r
#include <map> // asocjacyjne kontenery 
#include <unordered_set>
#include <unordered_map> 
#include <stack> // stos
#include <queue> // kolejka
#include <algorithm> // algorytmy
#include <typeinfo> // typeid
#include <type_traits> // cechy typowe
#include <bitset> // bitset
#include <utility> // np. pair
#include <tuple> // krotki tuple
#include <memory> // inteligentne wska�niki
#include <functional> // reference_wrapper<>
#include <chrono> // czas
#include <iomanip> // manipulatory io
#include <string> // wiadomo
#include <thread> // w�tki 
#include <ctime>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "numbers.h"

// C++17
using namespace std;
/*
	 wt�aczanie referencji
*/


void _022() {	


	

}


// aby nie namna�a� specjalizacji szablon�w mo�na skorzysta� z T jakby by� T& poprzez wt�oczenie mu referencji 
template <typename T>
void fufu(T x) {
	cout << x << endl;
	++x;
}
int somefunc(float a, string b) {
	cout << a << " " << b << endl;
	return (int)(a * 2);
}
void funkcja_ref() {
	int x = 10;
	fufu(x); // zadzia�a
	cout << x << endl; // x b�dzie 10
	fufu(ref(x));
	cout << x << endl; // x b�dzie 11, mimo, �e nie ma fufu(T& x) !!!
	// fufu(cref(x)); // nie zadzia�a, bo wt�aczam referencj� const, czyli tak, jakbym mia�   const T&  (niemo�liwa modyfikacja, dlatego nie zadzia�a)
	//mog� jawnie okre�laj�c typ domaga� si� bycia referencj�

	vector<reference_wrapper<int>> temp; // vektor referencji na int :)
	//temp.push_back(&x); // nie, bo wymagam ...
	temp.push_back(ref(x)); // ... takiej referencji :)

	// typ funkcyjny :)
	function<int(float, string)> f;
	f = somefunc; // bo somefunc to funkcja zwracaj�ca int, maj�ca argument float
	cout << f(3, "cze��") << endl;

	// max,min,swap - mo�na si� pobawi�
}