#include <iostream>
#include <array> // tablica
#include <vector> // wektor
#include <deque> // kolejka z dwoma koñcami
#include <list> // lista
#include <forward_list> // lista jednokierunkowa
#include <set> // zbiór
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
#include <memory> // inteligentne wskaŸniki
#include <functional> // reference_wrapper<>
#include <chrono> // czas
#include <iomanip> // manipulatory io
#include <string> // wiadomo
#include <thread> // w¹tki 
#include <ctime>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "numbers.h"

// C++17
using namespace std;
/*
	 wt³aczanie referencji
*/


void _022() {	


	

}


// aby nie namna¿aæ specjalizacji szablonów mo¿na skorzystaæ z T jakby by³ T& poprzez wt³oczenie mu referencji 
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
	fufu(x); // zadzia³a
	cout << x << endl; // x bêdzie 10
	fufu(ref(x));
	cout << x << endl; // x bêdzie 11, mimo, ¿e nie ma fufu(T& x) !!!
	// fufu(cref(x)); // nie zadzia³a, bo wt³aczam referencjê const, czyli tak, jakbym mia³   const T&  (niemo¿liwa modyfikacja, dlatego nie zadzia³a)
	//mogê jawnie okreœlaj¹c typ domagaæ siê bycia referencj¹

	vector<reference_wrapper<int>> temp; // vektor referencji na int :)
	//temp.push_back(&x); // nie, bo wymagam ...
	temp.push_back(ref(x)); // ... takiej referencji :)

	// typ funkcyjny :)
	function<int(float, string)> f;
	f = somefunc; // bo somefunc to funkcja zwracaj¹ca int, maj¹ca argument float
	cout << f(3, "czeœæ") << endl;

	// max,min,swap - mo¿na siê pobawiæ
}