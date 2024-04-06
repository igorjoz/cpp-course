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

// If i switch z ograniczonym zasi�giem zmiennej. Po co to?
// Bo dbamy o zasoby. Nie chcemy przechowywa� w pami�ci nieu�ywanych obiekt�w.
void _002() {
	// czasami robimy tak
	vector<int>tab{ 1,2,3 };
	int var = tab[0];
	if (var > 0) {
		; // co� tam
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
		Przestrze� nazw - szybkie przypomnienie

		Aby unikn�� konfliktu nazw dostarczanych przez r�ne biblioteki,
		wprowadzono przestrze� nazw. To nazwa z dwukropkiem poprzedzaj�ca r�ne identyfikator
		(zmienne, funkcje, sta�e itp.)
		Przyk�adowo: polecenie cout znajduje si� w przestrzeni std i je�eli
		nie poinformujemy kompilatora o ch�ci korzystania z tej przestrzeni poleceniem:
	using namespace std;
		to trzeba b�dzie pisa� np: std::cout zamiast cout.

		Od C++11 mamy np.: takie przestrzenie:
		std::, std::rel_pos::, std::chrono::, std::placeholders::,
		std::regex_constants::, std::this_thread:: 
	*/
	int a = 2; // a lokalna, ale jest te� a globalna 
	// 1 i 2, bo ::a to jest a globalne, a drugie a jest lokalne
	std::cout << ::a << a << endl;
	// manipulator strumienia std::hex, 200 szesnastkowo
	std::cout << std::hex << 200 << endl;
	
	// manipulator std::oct, 200 �semkowo	
	std::cout << std::oct << 200 << endl;
	
	// specjalny typ okresu czasu z przestrzeni std::chrono::	
	std::chrono::duration<int> sek20(20); // (tutaj definuj� sobie 20 sekund)
	std::cout << std::dec << 200 << endl; // wracam do systemu dziesi�tnego :) manipulatorem dec
	

}

