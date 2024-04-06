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
	 Cechy typowe: okre�laj� pewne rzeczy w czasie kompilacji, takie jak np. typ 
	 R�wnie� podnosz� nasz� umiej�tno�� programowania og�lnego
*/
template <typename T>
void cecha_wsk(T& v, std::true_type) { // albo to
	cout << *v;
	cout << "\twska�nik\n";
}

template <typename T>
void cecha_wsk(T& v, std::false_type) { // albo to
	cout << v;
	cout << "\twarto��\n";
}
template <typename T>
void cecha(const T& arg) {
	cecha_wsk(arg, is_pointer<T>()); // is_pointer<T>() b�dzie albo true_type, albo false_type w efekcie wywo�a si� odpowiednia funkcja
	// inne cechy
	if (is_integral<T>::value)
		cout << "\ttyp ca�kowity\n";
	else cout << "\ttyp nie-ca�kowity\n";
	if (!is_void<T>::value) cout << "\ttyp nie void\n";
	else cout << "\tvoid\n";
	if (is_floating_point_v<T>) cout << "\ttyp floating_point\n"; // _v zamiast ::value
	else cout << "\t nie floating_point\n";
	if (is_signed_v<T>) cout << "\ttyp ze znakiem\n";
	else cout << "\ttyp bez znaku\n";
	if (!is_array_v<T>) cout << "\ttyp nie tablicowy[] (nie array<>)\n";
	else cout << "\ttyp tablicowy[] (ale nie array<>)\n";
	if (!is_class_v<T>) cout << "\tnie klasa\n";
	else cout << "\tklasa\n";
	if (is_convertible_v<T, double>) cout << "\tda si� konwertowa� do double\n";
	else "\tnie da si� konwertowa� do double\n";
	if (is_same_v<T, unsigned int>) cout << "\ttyp zgodny z unsigned int\n";
	else cout << "\ttyp niezgodny z unsigned int\n";
	
	// istniej� te� cechy typowe dla klas
	// oraz cechy typowych relacji jak np 
	// is_same<T1,T2>
	// kt�re sprawdzaj� czy T1 i T2 s� takie same, albo 
	// is_convertible<T1,T2> gdzie sprawdzamy, czy T1 da si� konwertowa� na T2 itp.		
}

class A {
public:
	int x;
	A(int&& rv, int&& rv2) {
		x = rv;
		y = rv2;
	}
	friend ostream& operator<< (ostream& out, const A& ob); // pozwoli operatorowi << dobra� si� r�wnie� do zmiennych prywatnych, normalnie bym nie m�g� (spr�bujcie wykasowa� t� lini� - nast�pi bulwers kompilatora)
private:
	int y;
};
// abym m�g� zrobi� cout << a; gdzie a to obiekt klasy A, przeci��am operator <<
ostream& operator<< (ostream& out, const A& ob) { // teraz da si� "wy�wietli�" obiekt klasy A
	return out << "From class A, x=" << ob.x << " y=" << ob.y << endl; // Uwaga! .x musi by� publiczny
}


void _019() {
	unsigned int a = 100;
	float* b = new float(5.5);
	cecha(a);
	cecha(&a);
	cecha(*b);
	cecha(b);
	A c(10,20);
	cecha(c);
	
	// istnieje mo�liwo�� modyfikowania dzi�ki cechom modyfikuj�cym typy np. mo�na jak�� cech� typowi nada�, albo usun��
	typedef make_signed<unsigned int>::type sint; // dla bezznakowego dodaj� znak
	if (is_signed_v<sint>) cout << "!!!\n"; // i ju�

	typedef remove_pointer_t<int*> rint;
	if (!is_pointer_v<rint>) cout << "???\n";

}
