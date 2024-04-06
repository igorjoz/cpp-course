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
	 Lista dwukierunkowa (list).
	 (i jednokierunkowa)
*/

void _011() {
	/* Lista (list - domy�lnie dwukierunkowa), jak wiemy ka�dy element jest powi�zany z poprzednim i nast�pnym. Lista nie daje bezpo�redniego dost�pu do element�w dlatego by doj�� do np. 4 elementu musz� "przej��" przez pierwsze 3. 
	Dost�p do elementu jest wi�c liniowy, co nie jest zbytnio korzystne. Zaleta jednak jest taka, �e wstawienie elementu czy usuni�cie jest tak samo szybkie niezale�nie od jego pozycji! (nie wymaga przesuwania innych element�w a tylko zmian� odniesie� u s�siednich wzgl�dem tego nowego elementu).
	Lista nie zapewnia dost�pu swobodnego. Aby dosta� si� do elementu 10-ego musz� "przej��" 
	przez wszystkie od pocz�tku lub ko�ca. 
	Wstawianie/usuwanie nie powoduje uniewa�nienia wska�nik�w, referencji i iterator�w.
	front(), back(), push_front(), pop_front(), push_back(), pop_back()
	size(), empty(), swap(), max_size(), begin()....end() i mutacje,
	insert(), erase()
	remove(val), remove_if() , clear()
	uniue(), splice(), sort(), merge(), reverse()


	*/

	list<int> bigL = { 1,2,3,4,5,5,5,4,3,2,1 };
	bigL.insert(--bigL.end(), 100);
	printSTL(bigL, " ", true);
	// mo�liwy ++iterator, --iterator, ale nie (iterator + 5) (bo brak swobodnego dost�pu)
	for (auto it = bigL.begin(); it != bigL.end(); ++it) {
		cout << *it << " ";
	}
	cout << "[" << bigL.size() << "]" << endl;
	bigL.pop_front();
	printSTL(bigL, " ", true);


	// dodaj 
	bigL.push_back(-5);
	bigL.push_front(-10);
	bigL.insert(bigL.begin(), 100);
	auto pos = ++++++bigL.begin(); // hehe: JAK TO WYGL�DA ??? :) Uwaga! Iterator musi istnie�, aby si� przesun��. Tu przesuwam si� na 4-ty element.
	printSTL(bigL, " ", true);
	auto newpos = bigL.insert(pos, 1500);
	*pos -= 1; // to nie jest pozycja 1500, ale tej 3-ki co by�a 4tym elementem
	*newpos -= 1; // to jest pozycja 1500
	printSTL(bigL, " ", true);

	// bigL.begin() + 3; // nie zadzia�a
	// ++bigL.end(); // nie zadzia�a, wiadomo, poza koniec nie wyjdzie
	// ale mo�na tak
	int move = 5; // przesu� si� 5 razy od pocz�tku (6-ty element listy) o ile nie ma ko�ca
	auto pos2 = bigL.begin();
	while (pos2 != bigL.end() && move) {
		++pos2;
		--move;
	}
	cout << *pos2 << "!" << endl;
	
	// usuwanie
	bigL.remove(5); // wszystkie 5-ki precz
	printSTL(bigL, " ", true);

	// znajdnowanie i zwrot iteratora
	auto found = find(bigL.begin(), bigL.end(), 100);
	bigL.erase(found); //
	printSTL(bigL, " ", true);

	// sortowanie
	bigL.sort([](auto& a, auto& b) { return (a < b);  });
	printSTL(bigL, " ", true);

	// usuwanie pod warunkiem, �e 
	bigL.remove_if([](auto& e) {return (e < 4); }); // usuwam z warunkiem (lambda)
	printSTL(bigL, " ", true);
	
	/// UWAGA! forward_list jest jednokierunkowa, bo elementy s� powi�zane tylko z nast�pnym. Zmniejsza to zu�ycie pami�ci, ale k�opotliwie si� po tym porusza�...

	forward_list<string> stringList{ "Tak","Nie","Nie wiem","chyba" };	
	cout << *++stringList.begin() << endl; // "Nie"

	// --stringList.end(); // Nie przejdzie! Nie mo�na w obie strony
	// pozosta�y interfejs jest w zasadzie zbli�ony do tego, co ma list<T>, ale z wyj�tkami
	// - np. nie ma size()
	cout << distance(stringList.begin(), stringList.end()) << endl; // w miejsce size()

	
}

