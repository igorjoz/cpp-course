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
#include "numbers.h"


// C++17		

using namespace std;
void _010() {				
/*
	array - tablica, do korzystania w miejsce tablic z C.

	Kontenery sekwencyjne (kolekcje uporz�dkowanane) cechuje to, �e
	ka�dy element w kontenerze ma okre�lon� pozycj� zale�n� od momentu wstawienia
	i miejsca wstawienia i niezale�n� od warto�ci wk�adanej do kontenera.

	array to prosty przedstawiciel takich kontener�w. 
	Tablica (array) musi przy tworzeniu mie� jasno okre�lon� ilo�� element�w,
	bo nie mo�na zmienia� jej wielko�ci a tylko warto�� element�w.
	Do element�w tablicy dost�p mamy przez indeks/pozycj� w tablicy.
	Array przechowuje dane w spos�b zwarty, dok�adnie jak tablica z C,
	ale dodaje lepsz� kontrol� i jest cz�ci� kontener�w STL'owych.
	
	Tablice by�y jeszcze w j�zyku C i z racji na prost� konstrukcj� tej starszej wersji
	tablicy korzystam z niej w edukacji dla pocz�tkuj�cych do teraz.	
	Kiedy celem jest poznania samej idei programowania, 
	bardziej abstrakcyjny/skomplikowany zapis staje si� barier� i ro�nie
	pr�b wej�cia w j�zyk. Czym innym jest bowiem zrozumienie idei programowania 
	a niekiedy czym innym dok�adne poznanie jakiego� j�zyka. 
	Niestety w procesie	edukacji te dwa elementy 
	(w przypadku skomplikowanego j�zyka jakim jest C++) stanowi� (na pocz�tku!) trudne
	do pogodzenia zagadnienia i przyznaj� - nie wiem do ko�ca, jak to m�drze pogodzi�.
	Dlatego np.: ukazuj� ide� tablicy jeszcze z j�zyka C, a potem powoli przechodz�
	do kontener�w, takich jak array.

	
*/
		/// TAKI "wkl�s�y" kod b�d� omija� - jest jako pewne informacja do wgl�du
		/// samodzielnego, ale nie jest potrzebny do zagadnienia jako takiego
		/// tablica jeszcze z C, tak dla przypomnienia
		int ctab[2];
		ctab[0] = 5; ctab[1] = 10;
		cout << ctab[0] << " " << --ctab[1] << endl; // 5 i 9

// O! Takiej tablicy powinni�my u�ywa� (tak si� zaleca) 
// (nie, �e si� do kogo� zaleca, tylko si� zaleca, jasne chyba...)
	// 6 element�w, ale inicjuj� tylko 3, reszta b�dzie domy�lnie pustym napisem
	array<string, 6> names{ "Janusz", "Gra�yna", "Czesiek" };

	// poruszanie po tablicy mo�e by� po indeksie
	for (int i = 0; i < names.size(); i++)
		cout << i << ":=" << names[i] << " " << endl;

	// albo bardziej elegancko: e stanie si� ka�dym elementem 
	// z tablicy (array) names (kopi� kolejnych) | auto domy�li si� typu z kontekstu
	for (auto e : names) cout << e << " ";
	cout << endl;
	// jak wy�ej, ale referencja (zmiana e zmieni elementy names)
	for (auto& e : names) cout << e << " ";
	cout << endl;
	printSTL(names, " ", true); // a tu moja funkcyjka	

	// Jak nie mo�na inicjowa� tablicy?
	// int a4 = 10; 
	// array<int, a4> tab1{ 1,2,3 }; // nie p�jdzie, bo a4 nie jest sta�e
	
	// ITERATOR to obiekty wskazuj�ce na elementy w kontenerach. Mo�na o nich 
	// my�le�, jak o wska�nikach - ale to nie jest wska�nik w rozumieniu j�zyka C (*)
	// chocia� korzysta np. z operatora wy�uskania :) 
	// ITERATORY dok�adniej om�wi� w odcinkach po�wi�conych WEKTOROM, ok?
	// teraz tylko zajawka
	cout << "Korzystam z iterator�w: ";
	for (auto iterator = names.begin(); iterator != names.end(); iterator++) {
		cout << *iterator << " "; // *iterator - wy�uskuj� to, na co wskazuje iterator		
	} 
	cout << endl;
	// iterator++ przesuwa si� na nast�pny element, przypomina to ruch jak w li�cie 
	// jednokierunkowej, w praktyce to po prostu kolejny element w tablicy
	
	// a taki typ ma �w iterator...
	auto it = names.begin(); // it b�dzie typu jak nasz iterator na pierwszy element
	cout << typeid(it).name() << endl; // nasz iterator taki ma typ w przypadku names

	array<int, 20>tab{ 1,2,3 }; // 20 element�w, pierwsze to 1,2,3 a potem same 0	
	cout << "tab.size()=" << tab.size() << endl;
	printSTL(tab, " ", false);

	// warto korzysta� z metody .at(indeks) bo		
	cout << tab.at(0) << endl; // kontrola zakresu, b�dzie b��d zg�oszony
	// cout << tab.at(20) << endl; // kontrola zakresu, b�dzie b��d zg�oszony
	// cout << tab[20] << endl; // brak kontroli zakresu, gdy korzystamy z []

	cout << tab.front() << endl; // pierwszy (nie iterator, warto�� przechowywana)
	cout << tab.back() << endl; // ostatni (nie iterator, ostatnia warto��)



	// .data() adres pierwszego, to samo co &ac[0] ale uwaga, 
	// to nie jest ITERATOR (bo iteratorem jest tutaj to, co zwraca ac.begin())
	array<float, 10> f10{ 0.5 };	
	cout << &f10[0] << " " << f10.data() << endl;

	// a to dow�d, �e array w pami�ci jest taki jak tablica z C
	array<char, 100> ac = {}; // tablica stu znak�w
	strcpy_s(ac.data(), ac.size(), "du�o\0"); // kopiuj� do pami�ci s�owo "du�o" ...
	// ... zaczynaj�c od adresu pierwszego elementu tablicy ac i nie przekraczaj�c ac.size()
	
	// ac.data() to *char a wi�c wy�wietli si� jakby by� zmienn� napisow� w stylu starego C
	cout << ac.data() << " " << ac.size() << endl; 
	
	
}










