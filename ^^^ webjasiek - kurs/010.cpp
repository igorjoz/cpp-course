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
#include "numbers.h"


// C++17		

using namespace std;
void _010() {				
/*
	array - tablica, do korzystania w miejsce tablic z C.

	Kontenery sekwencyjne (kolekcje uporz¹dkowanane) cechuje to, ¿e
	ka¿dy element w kontenerze ma okreœlon¹ pozycjê zale¿n¹ od momentu wstawienia
	i miejsca wstawienia i niezale¿n¹ od wartoœci wk³adanej do kontenera.

	array to prosty przedstawiciel takich kontenerów. 
	Tablica (array) musi przy tworzeniu mieæ jasno okreœlon¹ iloœæ elementów,
	bo nie mo¿na zmieniaæ jej wielkoœci a tylko wartoœæ elementów.
	Do elementów tablicy dostêp mamy przez indeks/pozycjê w tablicy.
	Array przechowuje dane w sposób zwarty, dok³adnie jak tablica z C,
	ale dodaje lepsz¹ kontrolê i jest czêœci¹ kontenerów STL'owych.
	
	Tablice by³y jeszcze w jêzyku C i z racji na prost¹ konstrukcjê tej starszej wersji
	tablicy korzystam z niej w edukacji dla pocz¹tkuj¹cych do teraz.	
	Kiedy celem jest poznania samej idei programowania, 
	bardziej abstrakcyjny/skomplikowany zapis staje siê barier¹ i roœnie
	prób wejœcia w jêzyk. Czym innym jest bowiem zrozumienie idei programowania 
	a niekiedy czym innym dok³adne poznanie jakiegoœ jêzyka. 
	Niestety w procesie	edukacji te dwa elementy 
	(w przypadku skomplikowanego jêzyka jakim jest C++) stanowi¹ (na pocz¹tku!) trudne
	do pogodzenia zagadnienia i przyznajê - nie wiem do koñca, jak to m¹drze pogodziæ.
	Dlatego np.: ukazujê ideê tablicy jeszcze z jêzyka C, a potem powoli przechodzê
	do kontenerów, takich jak array.

	
*/
		/// TAKI "wklês³y" kod bêdê omija³ - jest jako pewne informacja do wgl¹du
		/// samodzielnego, ale nie jest potrzebny do zagadnienia jako takiego
		/// tablica jeszcze z C, tak dla przypomnienia
		int ctab[2];
		ctab[0] = 5; ctab[1] = 10;
		cout << ctab[0] << " " << --ctab[1] << endl; // 5 i 9

// O! Takiej tablicy powinniœmy u¿ywaæ (tak siê zaleca) 
// (nie, ¿e siê do kogoœ zaleca, tylko siê zaleca, jasne chyba...)
	// 6 elementów, ale inicjujê tylko 3, reszta bêdzie domyœlnie pustym napisem
	array<string, 6> names{ "Janusz", "Gra¿yna", "Czesiek" };

	// poruszanie po tablicy mo¿e byæ po indeksie
	for (int i = 0; i < names.size(); i++)
		cout << i << ":=" << names[i] << " " << endl;

	// albo bardziej elegancko: e stanie siê ka¿dym elementem 
	// z tablicy (array) names (kopi¹ kolejnych) | auto domyœli siê typu z kontekstu
	for (auto e : names) cout << e << " ";
	cout << endl;
	// jak wy¿ej, ale referencja (zmiana e zmieni elementy names)
	for (auto& e : names) cout << e << " ";
	cout << endl;
	printSTL(names, " ", true); // a tu moja funkcyjka	

	// Jak nie mo¿na inicjowaæ tablicy?
	// int a4 = 10; 
	// array<int, a4> tab1{ 1,2,3 }; // nie pójdzie, bo a4 nie jest sta³e
	
	// ITERATOR to obiekty wskazuj¹ce na elementy w kontenerach. Mo¿na o nich 
	// myœleæ, jak o wskaŸnikach - ale to nie jest wskaŸnik w rozumieniu jêzyka C (*)
	// chocia¿ korzysta np. z operatora wy³uskania :) 
	// ITERATORY dok³adniej omówiê w odcinkach poœwiêconych WEKTOROM, ok?
	// teraz tylko zajawka
	cout << "Korzystam z iteratorów: ";
	for (auto iterator = names.begin(); iterator != names.end(); iterator++) {
		cout << *iterator << " "; // *iterator - wy³uskujê to, na co wskazuje iterator		
	} 
	cout << endl;
	// iterator++ przesuwa siê na nastêpny element, przypomina to ruch jak w liœcie 
	// jednokierunkowej, w praktyce to po prostu kolejny element w tablicy
	
	// a taki typ ma ów iterator...
	auto it = names.begin(); // it bêdzie typu jak nasz iterator na pierwszy element
	cout << typeid(it).name() << endl; // nasz iterator taki ma typ w przypadku names

	array<int, 20>tab{ 1,2,3 }; // 20 elementów, pierwsze to 1,2,3 a potem same 0	
	cout << "tab.size()=" << tab.size() << endl;
	printSTL(tab, " ", false);

	// warto korzystaæ z metody .at(indeks) bo		
	cout << tab.at(0) << endl; // kontrola zakresu, bêdzie b³¹d zg³oszony
	// cout << tab.at(20) << endl; // kontrola zakresu, bêdzie b³¹d zg³oszony
	// cout << tab[20] << endl; // brak kontroli zakresu, gdy korzystamy z []

	cout << tab.front() << endl; // pierwszy (nie iterator, wartoœæ przechowywana)
	cout << tab.back() << endl; // ostatni (nie iterator, ostatnia wartoœæ)



	// .data() adres pierwszego, to samo co &ac[0] ale uwaga, 
	// to nie jest ITERATOR (bo iteratorem jest tutaj to, co zwraca ac.begin())
	array<float, 10> f10{ 0.5 };	
	cout << &f10[0] << " " << f10.data() << endl;

	// a to dowód, ¿e array w pamiêci jest taki jak tablica z C
	array<char, 100> ac = {}; // tablica stu znaków
	strcpy_s(ac.data(), ac.size(), "du¿o\0"); // kopiujê do pamiêci s³owo "du¿o" ...
	// ... zaczynaj¹c od adresu pierwszego elementu tablicy ac i nie przekraczaj¹c ac.size()
	
	// ac.data() to *char a wiêc wyœwietli siê jakby by³ zmienn¹ napisow¹ w stylu starego C
	cout << ac.data() << " " << ac.size() << endl; 
	
	
}










