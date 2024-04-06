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
	 Lista dwukierunkowa (list).
	 (i jednokierunkowa)
*/

void _011() {
	/* Lista (list - domyœlnie dwukierunkowa), jak wiemy ka¿dy element jest powi¹zany z poprzednim i nastêpnym. Lista nie daje bezpoœredniego dostêpu do elementów dlatego by dojœæ do np. 4 elementu muszê "przejœæ" przez pierwsze 3. 
	Dostêp do elementu jest wiêc liniowy, co nie jest zbytnio korzystne. Zaleta jednak jest taka, ¿e wstawienie elementu czy usuniêcie jest tak samo szybkie niezale¿nie od jego pozycji! (nie wymaga przesuwania innych elementów a tylko zmianê odniesieñ u s¹siednich wzglêdem tego nowego elementu).
	Lista nie zapewnia dostêpu swobodnego. Aby dostaæ siê do elementu 10-ego muszê "przejœæ" 
	przez wszystkie od pocz¹tku lub koñca. 
	Wstawianie/usuwanie nie powoduje uniewa¿nienia wskaŸników, referencji i iteratorów.
	front(), back(), push_front(), pop_front(), push_back(), pop_back()
	size(), empty(), swap(), max_size(), begin()....end() i mutacje,
	insert(), erase()
	remove(val), remove_if() , clear()
	uniue(), splice(), sort(), merge(), reverse()


	*/

	list<int> bigL = { 1,2,3,4,5,5,5,4,3,2,1 };
	bigL.insert(--bigL.end(), 100);
	printSTL(bigL, " ", true);
	// mo¿liwy ++iterator, --iterator, ale nie (iterator + 5) (bo brak swobodnego dostêpu)
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
	auto pos = ++++++bigL.begin(); // hehe: JAK TO WYGL¥DA ??? :) Uwaga! Iterator musi istnieæ, aby siê przesun¹æ. Tu przesuwam siê na 4-ty element.
	printSTL(bigL, " ", true);
	auto newpos = bigL.insert(pos, 1500);
	*pos -= 1; // to nie jest pozycja 1500, ale tej 3-ki co by³a 4tym elementem
	*newpos -= 1; // to jest pozycja 1500
	printSTL(bigL, " ", true);

	// bigL.begin() + 3; // nie zadzia³a
	// ++bigL.end(); // nie zadzia³a, wiadomo, poza koniec nie wyjdzie
	// ale mo¿na tak
	int move = 5; // przesuñ siê 5 razy od pocz¹tku (6-ty element listy) o ile nie ma koñca
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

	// usuwanie pod warunkiem, ¿e 
	bigL.remove_if([](auto& e) {return (e < 4); }); // usuwam z warunkiem (lambda)
	printSTL(bigL, " ", true);
	
	/// UWAGA! forward_list jest jednokierunkowa, bo elementy s¹ powi¹zane tylko z nastêpnym. Zmniejsza to zu¿ycie pamiêci, ale k³opotliwie siê po tym poruszaæ...

	forward_list<string> stringList{ "Tak","Nie","Nie wiem","chyba" };	
	cout << *++stringList.begin() << endl; // "Nie"

	// --stringList.end(); // Nie przejdzie! Nie mo¿na w obie strony
	// pozosta³y interfejs jest w zasadzie zbli¿ony do tego, co ma list<T>, ale z wyj¹tkami
	// - np. nie ma size()
	cout << distance(stringList.begin(), stringList.end()) << endl; // w miejsce size()

	
}

