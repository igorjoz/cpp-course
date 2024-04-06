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
	 W³asny "zasiêg" by u³atwiæ pêtli for egzystencjê !
		 ...bo niekiedy brakuje eleganckiego sposobu wykonania czegoœ ileœ-razy, albo 
		 od-do
*/

void _020() {	
	

	// zrób coœ 150 razy...
	for (int i = 1; i <= 150; i++) { ; }  // Dzia³a, ale ile¿ znaków do napisania... brzydko
	
	int i = 150; 
	while (i--) { ; } // ca³kiem eleganckie, ale koniecznoœæ definiowania wy¿ej i wszystko psuje

	for (int i = 150; i; i--) { ; } // fajnawe, ale mimo to ... niesmak pozostaje

	// .. bo inne jêzyki maj¹ to jakoœ smaczniej zrobione...
	// np. mniej wiêcej coœ takiego: 
	// for (i : range(1,10))  ....
	// for (i in -10:10) ...

	// Uwaga! C++20 posiada ju¿ podobne rozwi¹zania, mo¿na te¿ korzystaæ z biblioteki boost, niemniej tutaj miêtosimy bibliotekê standardow¹, wiêc ... spróbujmy wymiêtosiæ w ramach æwiczeñ to, czego potrzebujemy :)

	// A tymczasem chcia³bym zrobiæ coœ takiego:
	/*
	
	for (int i : range(-15,30)) {
		cout << i << " ";
	}	
	*/




	// taka klasa mo¿e byæ oczywiœcie przed main() aby mia³a zasiêg globalny ;)
	{
		// klasa iteratora, iteruj¹ca po liczbach :) Taka prymitywna ale skutczna wersja iteratora!
		class num_iterator { // nasz iterator bêdzie "postêpowa³" czyli musi mieæ operacjê ++
			long long i;
			bool increase; // czy itaracja bêdzie maleæ czy rosn¹æ ? 
		public:			
			// czêœæ : i(valueOfi) od razu ustawia this->i = valueOfi itd.
			num_iterator(long long valueOfi=0, bool inc=true) 
				: i(valueOfi),increase(inc) {}

			long long operator*() { return i; } // dereferencja, wy³uskanie

			num_iterator& operator++() { 
				if (increase) ++i; else --i;
				return *this; 
			}			

			bool operator!=(num_iterator& other) { return i != other.i; }
		};
		class range {
			long long a;
			long long b;
		public:
			range(long long from, long long to) : a{ from }, b{ to } {}
			num_iterator begin() { 
				if (a<b) return num_iterator{ a,true }; 
				return num_iterator{ a,false };
			}
			num_iterator end() { 				
				if (a<b) return num_iterator{ b + 1, true };
				return num_iterator{ b - 1, false };
			} 
		};		

		/* takie u¿ycie for, zawieraj¹ce mechanizm ':' oznacza, ¿e i bêdzie iterowaæ...
		dlatego potrzebna s¹ operacje dereferencji, operacja przesuwania ++, oraz != bo wszystkie
		one niejawnie ale s¹ uruchamiane w poni¿szej pêtli */
		for (int i : range(-15,15)) {
			cout << i << " ";
		}
		cout << endl << string(70, '#') << endl;
				
		for (int i : range(-15, -10)) {
			cout << i << " ";
		}
		cout << endl << string(70, '#') << endl;
				
		for (int i : range(15, 0)) {
			cout << i << " ";
		}
		cout << endl << string(70, '#') << endl;

		for (int i : range(0, -10)) {
			cout << i << " ";
		}
		cout << endl << string(70, '#') << endl;

		for (int i : range(10, -10)) {
			cout << i << " ";
		}
		cout << endl << string(70, '#') << endl;


		// Uwaga! Tak utworzona mechanika funkcjonuje jak taki prymitywny iterator, ale takie iteratory nie zadzia³aj¹ np. z algorytmami, chocia¿ wystêpuj¹ tu metody .begin() czy .end(). Do tego aby nasza klasa num_range i klasa range by³y zgodne w pe³ni z iteratorami STL potrzeba trochê wiêcej pracy. Je¿eli bêdzie ktoœ zainteresowany - dajcie znaæ w komentarzach.

		/*
		// a tu mo¿na sobie zobaczyæ, ¿e range(a,b) funkcjonuje jak iterator z biblioteki STL ;)
		auto it = range(-20, 20).begin(); // no nie kojarzy siê z iteratorem? :-D
		auto endit = range(-20, 20).end(); // jest nawet end() 
		while (it != endit) {
			cout << *it << " ";
			++it;
		}
		cout << endl << string(70, '#') << endl;
		*/

	}




	



}
