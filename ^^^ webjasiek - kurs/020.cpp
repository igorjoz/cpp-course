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
	 W�asny "zasi�g" by u�atwi� p�tli for egzystencj� !
		 ...bo niekiedy brakuje eleganckiego sposobu wykonania czego� ile�-razy, albo 
		 od-do
*/

void _020() {	
	

	// zr�b co� 150 razy...
	for (int i = 1; i <= 150; i++) { ; }  // Dzia�a, ale ile� znak�w do napisania... brzydko
	
	int i = 150; 
	while (i--) { ; } // ca�kiem eleganckie, ale konieczno�� definiowania wy�ej i wszystko psuje

	for (int i = 150; i; i--) { ; } // fajnawe, ale mimo to ... niesmak pozostaje

	// .. bo inne j�zyki maj� to jako� smaczniej zrobione...
	// np. mniej wi�cej co� takiego: 
	// for (i : range(1,10))  ....
	// for (i in -10:10) ...

	// Uwaga! C++20 posiada ju� podobne rozwi�zania, mo�na te� korzysta� z biblioteki boost, niemniej tutaj mi�tosimy bibliotek� standardow�, wi�c ... spr�bujmy wymi�tosi� w ramach �wicze� to, czego potrzebujemy :)

	// A tymczasem chcia�bym zrobi� co� takiego:
	/*
	
	for (int i : range(-15,30)) {
		cout << i << " ";
	}	
	*/




	// taka klasa mo�e by� oczywi�cie przed main() aby mia�a zasi�g globalny ;)
	{
		// klasa iteratora, iteruj�ca po liczbach :) Taka prymitywna ale skutczna wersja iteratora!
		class num_iterator { // nasz iterator b�dzie "post�powa�" czyli musi mie� operacj� ++
			long long i;
			bool increase; // czy itaracja b�dzie male� czy rosn�� ? 
		public:			
			// cz�� : i(valueOfi) od razu ustawia this->i = valueOfi itd.
			num_iterator(long long valueOfi=0, bool inc=true) 
				: i(valueOfi),increase(inc) {}

			long long operator*() { return i; } // dereferencja, wy�uskanie

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

		/* takie u�ycie for, zawieraj�ce mechanizm ':' oznacza, �e i b�dzie iterowa�...
		dlatego potrzebna s� operacje dereferencji, operacja przesuwania ++, oraz != bo wszystkie
		one niejawnie ale s� uruchamiane w poni�szej p�tli */
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


		// Uwaga! Tak utworzona mechanika funkcjonuje jak taki prymitywny iterator, ale takie iteratory nie zadzia�aj� np. z algorytmami, chocia� wyst�puj� tu metody .begin() czy .end(). Do tego aby nasza klasa num_range i klasa range by�y zgodne w pe�ni z iteratorami STL potrzeba troch� wi�cej pracy. Je�eli b�dzie kto� zainteresowany - dajcie zna� w komentarzach.

		/*
		// a tu mo�na sobie zobaczy�, �e range(a,b) funkcjonuje jak iterator z biblioteki STL ;)
		auto it = range(-20, 20).begin(); // no nie kojarzy si� z iteratorem? :-D
		auto endit = range(-20, 20).end(); // jest nawet end() 
		while (it != endit) {
			cout << *it << " ";
			++it;
		}
		cout << endl << string(70, '#') << endl;
		*/

	}




	



}
