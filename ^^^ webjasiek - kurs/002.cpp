#include <iostream>
#include <typeinfo> // typeid
#include <type_traits> // cechy typowe
#include <chrono> // czas
#include <string> // wiadomo
#include <ctime>
#include <vector>
#include "numbers.h"
// C++17
using namespace std;
int a{ 1 }; // a taka globalna zmienna a ;)

// If i switch z ograniczonym zasiêgiem zmiennej. Po co to?
// Bo dbamy o zasoby. Nie chcemy przechowywaæ w pamiêci nieu¿ywanych obiektów.
void _002() {
	// czasami robimy tak
	vector<int>tab{ 1,2,3 };
	int var = tab[0];
	if (var > 0) {
		; // coœ tam
	}
	// i var istnieje dalej

	if (int x = rand() % 10 ; x > 5) {
		cout << "tak\n";
	}
	else {
		cout << "nie\n";
	}
	cout << "Zmienna x tutaj nie istnieje.\n";
	// cout << x; // nie ma x!

	switch(int x = rand() % 5; x) {
		case 0: cout << x<<"yupi\n"; break;
		case 1: cout << x<<"juhu\n"; break;
		default: cout << "yeah\n";
	}
	cout << "Zmienna x tutaj nie istnieje.\n";	
	// cout << x; // nie ma x!



	/*
		Przestrzeñ nazw - szybkie przypomnienie

		Aby unikn¹æ konfliktu nazw dostarczanych przez ró¿ne biblioteki,
		wprowadzono przestrzeñ nazw. To nazwa z dwukropkiem poprzedzaj¹ca ró¿ne identyfikator
		(zmienne, funkcje, sta³e itp.)
		Przyk³adowo: polecenie cout znajduje siê w przestrzeni std i je¿eli
		nie poinformujemy kompilatora o chêci korzystania z tej przestrzeni poleceniem:
	using namespace std;
		to trzeba bêdzie pisaæ np: std::cout zamiast cout.

		Od C++11 mamy np.: takie przestrzenie:
		std::, std::rel_pos::, std::chrono::, std::placeholders::,
		std::regex_constants::, std::this_thread:: 
	*/
	int a = 2; // a lokalna, ale jest te¿ a globalna 
	// 1 i 2, bo ::a to jest a globalne, a drugie a jest lokalne
	std::cout << ::a << a << endl;
	// manipulator strumienia std::hex, 200 szesnastkowo
	std::cout << std::hex << 200 << endl;
	
	// manipulator std::oct, 200 ósemkowo	
	std::cout << std::oct << 200 << endl;
	
	// specjalny typ okresu czasu z przestrzeni std::chrono::	
	std::chrono::duration<int> sek20(20); // (tutaj definujê sobie 20 sekund)
	std::cout << std::dec << 200 << endl; // wracam do systemu dziesiêtnego :) manipulatorem dec
	

}

