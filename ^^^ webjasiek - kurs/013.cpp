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
	 Krotki. 
	 Niejawne typ krotki.
	 Array a krotka.
*/


void _013() {	
	
	/// krotka ��czy wiele typ�w w jeden element (para dok�adnie dwa, tu mo�na wiele)
	tuple<int, float, string, bool> t1 (1, 2.0f, "abc", true);	
	// krotka nie pozwala na iterowanie po elementach, dlatego indeks nie mo�e by� obliczany w czasie wykonania
	cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << " " << get<3>(t1) << endl; 	
	printSTL(t1, ":", true); // m�j druk krotki
	
	auto t2 = make_tuple(1, 2.0, "def", false); // c++11
	get<1>(t2) = 5.0; // modyfikacja mo�liwa
	printSTL(t2, ", ", true);
	cout << endl;	
	cout << typeid(t2).name() << endl;

	// kopia
	string s = "napis";
	auto t3 = make_tuple(s); // wewn�trz tupla jest kopia tego s, nie sam s
	cout << get<0>(t3) << endl; 	

	//referencja w krotce
	auto t4 = make_tuple(ref(s)); // referencja do s sprawia, �e ...
	get<0>(t4) = "kolejny napis"; // ... jak zmieni� co� w krotce t4 ...
	cout << s << " " << get<0>(t4) << " " << endl; // ... to zmienia si� s ...
	s = "niemo�liwe, kolejny napis?"; // ... a jak zmieni� s ...
	cout << s << " " << get<0>(t4) << " " << endl; // ... to zmienia si� i krotka t4.


	tuple<int, double, string, string> t6(1,2.5,"jestem","krotk�");
	printSTL(t6," ",true);
	int g0;
	double g1;
	string g3;
	/// tie rozpakuje mi krotk�, ignore ignoruje element) C++11
	tie(g0, g1, std::ignore, g3) = t6; 
	cout << g0 << g1 << g3 << endl;	
	/// tzw. ROZPAKOWANIE krotki (podobnie mo�na rozpakowa� par�) C++17
	auto& [x1, x2, x3, x4] = t6;
	cout << ":-D " << x1 << x2 << x3 << x4 << " !" << endl;
	x1 = 100; // referencja, zmieni si� element krotki ;)
	cout << get<0>(t6) << " " << get<3>(t6) << endl; // 

	// definiuj w�asny typ na podstawie typu krotki
	typedef tuple<int, unsigned int, int> MyTripleTuple;	
	cout << tuple_size_v<MyTripleTuple> << endl; // z ilu element�w jest krotka
	MyTripleTuple t7(10, 20, 30); // o tak mog� sobie zdefiniowa� zmienn� typu mojej krotki
	tuple_element_t<1, MyTripleTuple> zmienna; // pobieranie typu dla 1-ego elementu z krotki	
	cout << typeid(zmienna).name() << endl; // zmienna ma typ, jak 1-y element w krotce (indeks 1)

	// nieudokumentowana funkcja, kt�r� znalaz�em
	_For_each_tuple_element(t7, [](auto& e) {cout << e << "!\t"; }); 
	cout << endl;

	auto implode = tuple_cat(t7, t4); // krotka z dw�ch krotek :)
	cout << tuple_size_v<decltype(implode)> << endl;
	printSTL(implode, "-", false);
	

	// zagnie�d�enie - przyk�ad
	tuple<int, tuple<float, float>> tint(1, { 2.5f,4.6f });
	cout << get<0>(tint) << " " << get<1>(get<1>(tint)) << endl; // 1, 4.6

	// c++17
	// krotki i pary mog� by� tworzone z niejawnie podanym typem
	tuple tu1(1, "czary", string("mary"), 100.5f); // ponownie krotka nie ma jawnie dope�nionego typu, wiadomo �e to krotka a reszta wynika z inicjatora	
	cout << get<1>(tu1) << " " << get<2>(tu1) << endl;
	// wcze�niej musia�o by by�
	tuple<int, const char*, string, float> tu2(1, "czary", string("mary"), 100.5f);

	// UWAGA!
	// tablice maj� interfejs krotek
	cout << tuple_size_v<array<int, 10>> << endl; // w tuple_size jest typ mojej tablicy tab1
	typedef array<int, 5> fivea;
	fivea tab2 = { 1,2 }; // 1,2,0,0,0
	cout << tuple_size_v<fivea> << endl; // w tuple_size jest typ mojej tablicy tab2	
	cout << get<0>(tab2) << endl; // 1

}








