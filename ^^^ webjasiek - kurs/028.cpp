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
#include <list>
#include <iterator>
#include <algorithm>
#include "numbers.h"

// C++17

using namespace std;
/* operacje ogólne na kontenerach, o których mog³em nie wspomnieæ wczeœniej 
oraz ogólnie 
ALGORYTMY (wyszukiwanie, sortowanie, kopiowanie, przestawianie, modyfikacje czy przetwarzanie numeryczne). Algorytmy to globalne funkcje korzystaj¹ce z iteratorów. Dzia³aj¹ na dowolnym kontenerze. Ta uniwersalnoœæ mo¿e jednak rodziæ s³absz¹ wydajnoœæ. Dlatego metody nale¿¹ce
	 do interfejsu kontenera s¹ lepsze (o ile istniej¹) od ogólnych metod.
	 Np. swap(kontener1,kontener2) jest gorsze ni¿ kontener1.swap(konener2) o ile kontener1.swap istnieje...
*/
void _028() {
	vector<int> v{ 1,2,3 };
	if (!v.empty()) cout <<  v.size() << " " << v.max_size() << endl;

	// operacje == <= >= < > s¹ mo¿liwe (kontenery tego samego typu)
	vector<int> v2{ 3,2,1 };
	vector<int> v3{ 1,2,3 };
	vector<int> v4{ 1,2,3,4 };
	// mo¿na szybko dojœæ do wniosku, jak to jest porównywane ;)
	cout << (v==v2) << (v==v3) << (v==v4) << endl; // 
	cout << (v<=v2) << (v<=v3) << (v<=v4) << endl; // 
	cout << (v<v2) << (v<v3) << (v<v4) << endl; // 
	cout << (v>v2) << (v>v3) << (v>v4) << endl; // 
	cout << (v>=v2) << (v>=v3) << (v>=v4) << endl; // 
	
	// swap - podmiana kontenerów 
	auto vit = v.begin(); // v 1 2 3
	auto v2it = v2.begin(); // v2 3 2 1
	auto vittemp = v.begin();
	while (vittemp != v.end()) {
		cout << *vittemp;
		++vittemp;
	}
	cout << *vit << " " << *v2it << endl; // 1 3		
	cout << &v[0] << " " << v[0] << " " << &v2[0] << " " << v2[0] << endl; //
	swap(v, v2); // mo¿na te¿ v.swap(v2); co jest zalecane, gdy istnieje taka metoda 
	cout << &v[0] << " " << v[0] << " " << &v2[0] << " " << v2[0] << endl; //
	cout << *vit << " " << *v2it << endl; // dalej 1 3 !!! (iteratory wskazuj¹ na to samo)	
	// uwaga! nie jest ju¿ mo¿liwe przesuwanie vit++ ... bo 
	// ju¿ tak nie mo¿na ! while (vit != v.end()) { cout << *vit; ++vit; }

	array<float, 10> ar{}; // same 0 bêd¹, bo 0 jest domyœlne
	for (auto& e : ar) cout << e;
	ar.fill(-5); // zastêpuje elementy
	for (auto& e : ar) cout << e;
	cout << endl;

	list<int> l1{ 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 };
	auto pos = l1.begin();
	advance(pos, 4); // #include <iterator>, pozwala przesun¹æ siê 4 razy po elemencie
	cout << *pos << endl; 
	pos = prev(pos);
	cout << *pos << endl; 
 	pos = prev(pos, 2);
	cout << *pos << endl; 
	pos = next(pos, 3);
	cout << *pos << endl; 
	
	
	// distance oblicza ró¿nicê pomiêdzy iteratorami 
	cout << distance(l1.begin(), pos) << endl; // 4 pozycje 
	cout << distance(l1.begin(), l1.end()) << endl; // praktycznie iloœæ elementów

	// iter_swap - podmienia wartoœci wskazane przez iteratory. Iteratory mog¹ siê ró¿niæ, ale wskazywane wartoœci nie i wartoœci wskazywane przez iteratory powinny mieæ mo¿liw¹ operacjê przypisania
	cout << *l1.begin() << " " << *v.begin() << endl;
	iter_swap(l1.begin(), v.begin());
	cout << *l1.begin() << " " << *v.begin() << endl;


	vector<int> exp3 = { 1,6,8,0,3,-5,0,9,4 };
	auto minimum = min_element(exp3.cbegin(), exp3.cend());
	cout << *minimum << " " << *max_element(exp3.cbegin(), exp3.cend()) << endl; // -5 jako minimum i 9 jako maximum
	sort(exp3.begin(), exp3.end()); // nie mo¿na cbegin() ani cend(), bo przecie¿ sort modyfikuje kontener (cbegin, cend na to nie pozwoli)
	printSTL(exp3,",",false);
	for (int i = -5; i < 10; i++) {
		auto pos = find(exp3.cbegin(), exp3.cend(), i); // szukam i, jak znajdê to zwracam pozycjê znalezion¹ (iterator), jak nie to zwraca iterator na koniec .end()
		if (pos != exp3.end()) cout << *pos << " ";
	}
	cout << endl;

	reverse(exp3.begin(), exp3.end()); /// odwracam kolejnoœæ ca³ej kolekcji
	printSTL(exp3,",",false);
	reverse(find(exp3.begin(), exp3.end(), 3), exp3.end()); // od miejsca gdzie by³o 3, do koñca - odwracam kolejnoœæ
	printSTL(exp3,",",true);
	/// ZAUWA¯, ¿e zakres do np. posortowania czy szukania jest od begin() do end() czyli od pozycji jakiegoœ elementu do pozycji "za ostatnim". [od,do) 

	vector<int> exp4 = { 2,3,4,5 };
	vector<int> exp5 = { 2,4,0,0 };
	list<int> exp6 = { 2,3,4,5 };
	list<int> exp7 = { 0,0 };
	/// porównuje elementy z exp4 z tymi z exp5. Liczba w exp5 musi byæ nie mniejsza ni¿ elementów w exp4 !!!
	cout << equal(exp4.begin(), exp4.end(), exp5.begin()) << endl; // nie taka sama zawartoœæ, 0
	cout << equal(exp4.begin(), exp4.end(), exp6.begin()) << endl; // taka sama zawartoœæ, 1

	/// kopiowanie (nie wstawianie, musi byæ miejsce na kopiowane elementy)
	exp7.resize(exp4.size(), -5); // muszê podnieœæ iloœæ elementów w exp5 do przynajmniej tylu ile jest w exp4, inaczej b³¹d (nowe elementy dostaj¹ -5)
	printSTL(exp7," ",true);
	copy(exp4.begin(), exp4.end(), exp7.begin());
	printSTL(exp7," ",true); // w exp5 jest ju¿ to, co by³o w exp4 (2,3,4,5)

	/// usuwanie (remove): dzia³a "dziwnie" i dla kontnerów sekwencyjnych, usuwa chciany element, ale nie skraca rozmiaru. W efekcie mamy coœ takiego:
	vector<int> col = { 1,2,3,4,4,4,5,6 };
	remove(col.begin(), col.end(), 4); /// znikn¹ wszystkie 4-ki
	printSTL(col," ",false); // wyœwietli siê 1,2,3,5,6 i ... coœ tam jeszcze (pozosta³oœci, które jednak zosta³y pokazane, bo end() nie zmieni³o siê !
	/// trzeba wiêc odkryæ nowy end() (iterator za ostatnim elementem)
	col = { 1,2,3,4,4,4,5,6 };
	auto newend = remove(col.begin(), col.end(), 4); /// znikn¹ wszystkie 4-ki
	for (auto i = col.cbegin(); i != newend; i++) {
		cout << *i << " ";
	} cout << endl;
	cout << "Skasowano elementów = " << distance(newend, col.end()) << endl; /// distance liczy odleg³oœæ miêdzy iteratorami, ale gdy iteratory s¹ dostêpu swobodnego (np. w vector czy array) to mogê te¿
	// obliczyæ dystans poprzez operator odejmowania po prostu:
	cout << "Skasowano elementów = " << col.end() - newend << endl;

	col.erase(newend, col.end()); // a tu usunê te elementy nadmiarowe i teraz col.end() jest ju¿ prawdziwy.
	printSTL(col," ",true); // ju¿ pokazuje zmniejszony kontener bo .end() siê przesun¹³ za faktycznie ostatni element;

	
	list<int> li = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	auto newE = remove_if(li.begin(), li.end(), [](auto& e) { return e >= 4; }); // usuwam 4 i 5 (wszystkie) );	// sprawdŸ li.remove_if () !!
	li.erase(newE, li.end()); 
	li.remove(1); // wszystkie 1-ki precz	// nie muszê li.erase() bo remove jest "w³asny"
	printSTL(li, ", ", true);
		
	unordered_multimap<int, int>myMap{ {-1,0}, {0,0}, {1,1},{2,2},{3,3},{1,10},{1,20} };
	for (auto i : myMap) cout << i.first << ":" << i.second << endl;
	
	/// algorytm z funkcj¹ lambda jako argumentem 
	for_each(myMap.begin(), myMap.end(),
		[](const auto& p) {cout << p.first << "*" << p.second + 1 << "\t";  });  		
	
}


