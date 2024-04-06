#include <iostream>
#include <array> // tablica
#include <vector> // wektor
#include <deque> // kolejka z dwoma koñcami
#include <list> // lista
#include <forward_list> // lista jednokierunkowa
#include <set> // zbiór
#include <queue> // kolejka
#include <algorithm> // algorytmy
#include <typeinfo> // typeid
#include <type_traits> // cechy typowe
#include <utility> // np. pair
#include <tuple> // krotki tuple
#include <memory> // inteligentne wskaŸniki
#include <functional> // reference_wrapper<>
#include <chrono> // czas
#include <iomanip> // manipulatory io
#include <string> // wiadomo
#include <ctime>
#include "numbers.h"

// C++17
using namespace std;
/*
	ujednolicono inicjalizacjê (mo¿na stosowaæ nawiasy {} jak i () i nie potrzeba znaku =, 
	chocia¿ jego obecnoœæ mo¿e zmieniaæ zachowanie inicjacji)
	() dopuszcza niejawn¹ konwersjê typu
	{} niedopuszcza do konwersji, typ musi byæ w³aœciwy
	{1,2,3} - coœ takiego to lista inicjalizacyjna, najczêœciej u¿ywana 
	przy tworzeniu zmiennej/obiektu 
	(jako argument dla konstruktora obiektu albo wartoœæ przypisywana do zmiennej)
*/
class A {
public:
	A(const std::initializer_list<string>& l) {
		for (auto& e : l) cout << e << " ";
	}
};

void _003() {
	int i1 = 1; // 1 - tak klasycznie, jak w 98ym :)	
	int oldtab[]{ 1,2,3 }; // bez równa siê
							//Tutaj pierwszym elementem bêdzie 1, potem reszta zape³ni siê zerami.
	int tab[10]{ 1 }; // stara tablica z C, ale zmieniona inicjacja. 
	
		
	printSTL(tab, ":", true); // taka moja funkcja drukuj¹ca - kiedyœ do niej dojdziemy ;)	
	cout << typeid(tab).name() << endl;

	int i2(1.5); // konwersja do 1 (nawiasy () pozwalaj¹ na konwersjê typu)
	int i3{ 1 }; // 1, nie trzeba znaku równoœci  int i3 = { 1 }; 
	//int i3_2{ 1.5 }; // to nie przejdzie, konwersja blokowana przez {}
	cout << i2 << " " << i3 << " " << endl;

	vector<int> v1 = { 1,1,1 }; // 3 razy wartoœæ 1 w wektorze
	vector<int> v2{ 1,1,1 }; // 3 razy 1 w wektorze
	printSTL(v1, ", ", true); 
	printSTL(v2, ", ", true); 
	
	// auto - ustawia typ z kontekstu
	auto v4{ 1 }; // v4 to int w C++17
	int v41{ 1 };
	int v42 = 1;
	auto v5 = { 1 }; // v5 to initializer_list<int>
	int v51 = { 1 };
	auto v6 = { 1,2 }; // v6 to initializer_list<int>, wszystkie elementy musz¹ byæ tego samego typu

	cout << typeid(v4).name() << endl;  
	cout << typeid(v41).name() << endl;  
	cout << typeid(v42).name() << endl;  
	cout << typeid(v5).name() << endl; 
	cout << typeid(v51).name() << endl; 
	cout << typeid(v6).name() << endl;		
	
	A obiekt( { "a","b","c" } );
	



	//konstruktor(int, int);	// dla wywo³ania:  o(1,2);
	//konstruktor(initializer_list<int>); // dla wywo³ania:   o{1,2};	
}





