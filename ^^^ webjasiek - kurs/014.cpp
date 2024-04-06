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
	 Para. 	 
*/

void _014() {	
	// para ��czy dwa elementy w jeden, jest wykorzystywana 
	// w kontenerach np: map, multimap, unordered_map i undordered_multimap;	
	
	pair<int, int> p1(5, 10);
	cout << typeid(p1).name() << endl;

	auto p2(p1); // kontruktor kopiuj�cy (z p1)
	printSTL(p2, " ");
	pair<double, double> pd( p1 );
	printSTL(pd, " ");
	
	// .first : pierwsza warto�� pary
	// .second : druga warto�� pary
	cout << p1.first << " " << p1.second << endl;	 // 5,10
	++p2.second;
	cout << p2.first << " " << p2.second << endl; // 5,11

	// por�wnywanie par to por�wnanie kolejnych warto�ci first i potem second
	cout << (p1 == p2) << (p1 != p2) << (p1 > p2) << (p1 < p2) << endl;  // 5,10 vs 5,11
	p2.first = 2;
	cout << (p1 == p2) << (p1 != p2) << (p1 > p2) << (p1 < p2) << endl; // 5,10 vs 2,11

	cout << &p1 << " " << &p2 << endl; 
	p1.swap(p2); // podmianka warto�ci
	cout << &p1 << " " << &p2 << endl; // adresy si� nie zmieni�y...		
	cout << p1.first << " " << p1.second << endl; // ... ale warto�ci tak
	cout << p2.first << " " << p2.second << endl; 

	// make_pair : tworzy par� i nadaje si� do inicjacji zmiennej z typem auto
	auto p3 = make_pair(1.0, string("Kaszanka jest smaczna.")); // tworz� par� double->string
	cout << typeid(p3).name() << endl;
	printSTL(p3," ");	

	// pareczka z int'a i ... wektora :) bo para nie musi by� z�o�ona z prostych typ�w
	auto p4 = make_pair(10, vector<int>{100, 200, 300}); 
	cout << typeid(p4).name() << endl;
	cout << p4.first << " " << p4.second[2] << endl;

	// klasyczny wska�nik
	pair<string, string>* p_ptr;
	p_ptr = new pair<string, string>;
	p_ptr->first = "RAZ"; // -> zamiast .
	p_ptr->second = "DWA";
	printSTL(*p_ptr, "=");	

	// zdefinuj� sobie taki 'alias' na typ pair<string,double> i nazw� go myPairType
	typedef pair<string, double> myPairType;	
	myPairType p_ptr2{ "ABC",10.5 };	
	printSTL(p_ptr2, " ");

	// pary mog� by� tworzone z niejawnie podanym typem (c++17)
	// nie musz� pisa� pair<string,double> ! typ jest niejawny utworzony przy inicjacji
	pair pshort(string("first"), 100.95f); // nie ma auto, nie ma make_pair
	printSTL(pshort, " ");
	cout << typeid(pshort).name() << endl;
}

