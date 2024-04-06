#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <map>
#include <ctime>
#include <typeinfo>
#include <type_traits>
#include "numbers.h"


// C++17
using namespace std;
/*		
	VECTOR: kontener sekwencyjny (kolekcja uporz�dkowana), z dost�pem bezpo�rednim do element�w, o ile znamy pozycj� elementu. Jest jak tablica ale z mo�liwo�ci� zmiany wielko�ci. Wektor pozwala dynamicznie zmienia� swoj� wielko��, dodawanie na koniec wektora jest b. szybkie (a gdzie indziej wymusza przesuwanie element�w). Niekt�re operacje realokuj� ca�� zawarto�� wektora (przenosz� w inne miejsce pami�ci). 
	
	Iteratory wektor�w s� iteratorami dost�pu swobodnego.

*/

void _008() {

	vector<int> vec1(20, 5); // wektor o 20-u elementach, ka�da o warto�ci 5
	printSTL(vec1, " ", true);		
	
	/*
	ITERATORY : 
Reprezentuj� POZYCJ� elementu w KONTENERZE ! (mo�na my�le� o nich jak o wska�nikach zawieraj�cych pozycj� przechowywanych element�w, cho� nie s� wska�nikiem w rozumieniu j�zyka C).
	Iterator to taki obiekt, kt�ry "iteruje" po elementach kontenera, czyli "przechodzi od jednego do drugiego", nawiguje. Na iteratorach mo�na wykonywa� operacj�:
	* : pobierania elementu na kt�ry wskazuje iterator (wy�uskanie, zupe�nie jak wy�uskanie z j�zyka C)
	++ (niekiedy --) : pozwala przej�� do nast�pnego (niekiedy poprzedniego) elementu
	== i != : por�wnuje iteratory, czy s� r�wne ? (czy wskazuj� na to samo)
	= : przypisuje do iteratora pozycj� element�w odpowiedniego typu
	ITERATORY maj� swoje kategorie:
	- post�puj�cy (przesuwa si� tylko "w prz�d" za pomoc� ++)
	- dwukierunkowy (operator ++ i -- s� dopuszczone, poruszamy si� "w prz�d i w ty�")
	- swobodnego dost�pu (realizuj� ++, -- ale mog� dobra� si� do dowolnego elementu bezpo�rednio
	bez "przechodzenia" przez kolejne elementy kolekcji, mo�na je dodawa�, odejmowac, 
	por�wnywa� (<, >)  i s� dost�pne dla kontener�w vector i deque (oraz w napisach, specjalnych kontenerach))

	metody zwracaj�ce iteratory kontener�w:  
	begin(), end(), cbegin(), cend(), crbegin(), crend(), rbegin(), rend()
	*/

	// .begin() iterator na pierwszy
	// .end() iterator 'za ostatnim'
	vector<int> vec2 { 1, 2, 3, 4, 5 };			
	for (auto iter = vec2.begin(); iter != vec2.end(); ++iter) cout << *iter << " ";
	cout << endl;
	auto iter = vec2.begin() + 3; // swobodny dost�p pozwala na przej�cie
	cout << *iter << endl; // Ha! 4
	
	
	// ::const_iterator pozwala tylko odczytywa�, a ::iterator r�wnie� zmienia� elementy
	vector<int>::const_iterator it = vec2.begin(); // auto it te� oczywi�cie wystarczy ;)
	while (it != vec2.end()) cout << *it++ << " "; // pobieram *it a potem it++		
	cout << endl;
	cout << vec2.front() << endl; // pierwszy element (nie iterator) /1
	cout << vec2.back() << endl; // ostatni element (nie iterator) /5

	// cbegin() : <vector<int>>::const_iterator -  niemodyfikowalny iterator na pierwszy element
	// cend() : niemodyfikowalny iterator na 'za ostatnim' elementem
	// crbegin() : iterator odwrotny (pierwszy ale id�c od ty�u), do tego const_iterator niemodyfikowalny
	cout << *vec2.cbegin() << endl; // 1
	cout << *--vec2.cend() << endl; // 5 (przejd� na iterator przed ostatnim i wy�uskaj)
	cout << *++vec2.crbegin() << endl;  // 4
	for (auto it = vec2.crbegin(); it != vec2.crend(); ++it) cout << *it << " "; // 5,4,3,2,1
	cout << endl;

	// at(pozycja) w miejsce [pozycja] - sprawdza, czy nie wyszli�my poza zakres wektora
	// size() - ile element�w
	// push_back(co�) - wstawia na koniec co�
	// pop_back() - usuwa z ko�ca
	// reserve(TYLE) - zarezerwuje pami�� na TYLE elementen�w
	// capacity() - na ile zarezerwowano miejsca ?
	vector<int> v { 1,2,3,4,5,6,7,8,9,10,1,2,3,4 };
	cout << &v[0] << endl;
	cout << v.size() << " " << v.at(10) << endl;
	v.push_back(5); // dodaj na koniec 5...
	v.pop_back(); // i zabierz z ko�ca to 5
	v.reserve(100); 
	cout << v.size() << " " << v.capacity() << endl;	

	/// ZALECANE METODY usuwania z wektora (c++17)
	/// 1 metoda
	printSTL(v, " ", true);
	cout << &v[0] << endl;
	cout << v.capacity()<<endl; // zarezerwowana ilo�� mo�e by� wi�ksza ni� size()
	
	// remove(its,ite,n) (w podanym zakresie (iterator star i koniec) usu� wszystkie warto�ci n). remove() zwraca pozycje ko�ca (tyle wcze�niejszy iterator ile element�w usuni�to)
	auto newEnd = remove(v.begin(), v.end(), 2); // pozb�dzie si� 2-ek, przesuwaj�c elementy w ramach pami�ci. NIE zmieni si� alokowana pami��... (nie b�dzie przeniesienia!)
	printSTL(v," ",true); // nie ma dw�ch 2-ek, ale rozmiar i elementy pozosta�y (na ko�cu s� 2 niepotrzebne elementy) .size() nie zmieni� si� !
	cout << &v[0] << endl; // pami�� ta sama
	cout << v.capacity() << endl << endl;
	
	// erase(its,ite) - usuwa wszystko pomi�dzy iteratorami i zmniejsza rozmiar
	v.erase(newEnd, v.end()); // 
	printSTL(v, " ", true); // prosz�: ju� rozmiar mniejszy...
	cout << &v[0] << endl;
	cout << v.capacity() << endl << endl; // ... ale pami�ci zarezerwowanej wci�� tyle samo
	
	v.shrink_to_fit();	// a teraz pami�� jest OK, dopasuj� size() i capacity()...
	cout << &v[0] << endl; // ... ale nast�pi�o przeniesienie wszystkiego w inny rejon pami�ci
	cout << v.capacity() << string(3,'\n');

	// 2 matoda
	// usuwanie mo�na przeprowadzi� poprzez zamian� z ostatnim i wywalenie ostatniego :)	
	// fajne, gdy nie zale�y mi na posortowaniu element�w wektora
	// poni�sza p�tla usuwa wszystkie wyst�pienia liczby 5
	do {
		if (auto foundIndex = find(v.begin(), v.end(), 5); foundIndex != v.end()) {
			*foundIndex = v.back(); // w miejsce gdzie by�o 5 wstawiam to co sta�o na ko�cu
			v.pop_back();			
		}
		else break;
	} while (true);
	printSTL(v, " ", true);
	cout << &v[0] << endl; //
	cout << v.capacity() << endl << endl;
	v.shrink_to_fit(); // zmieniam rozmiar
	cout << v.capacity() << " " << v.size() << " " << &v[0] << endl;
	v.resize(50, 0); // zwi�ksza size do 50, nowe zape�nia zerami
	cout << v.size() << " " << v.capacity() << " " << &v[0] << endl;
	printSTL(v, " ", true);
}



/*

KONTENERY ASOCJACYJNE / KOLEKCJE SORTOWANE
Pozycja elementu zale�y od jego warto�ci, lub klucza gdy mamy doczynienia z par� klucz-warto��.
Elementy tego kontenera s� sortowane domy�lnie wed�ug pewnego kryterium. Kolejno�� czy moment wstawiania elementu nie ma wi�c znaczenia.
Domy�lnie sortowanie jest wg algorytmu "od mniejszego do wi�kszego" ( operator < ). Mo�na to zmieni�.
set, multiset, map, multimap
KONTENERY NIEPORZ�DKUJ�CE - pozycja element�w nie jest okre�lona/istotna bo nie ma znaczenia warto�� czy klucz
element�w ani moment ich wk�adania do kolekcji. Zg��wnym zadaniem tych kontener�w jest okre�lenie - czy dany element 
wyst�puje w kolekcji (a nie gdzie).
unordered_set, unordered_multiset, unordered_map, unordered_multimap (�wietna jako s�ownik!)

R�ne kontenery maj� swoje zalety i wady - g��wnie chodzi o pr�dko�� dzia�a� na kontenerach, czas wyszukiwania element�w co si� przek�ada na zu�ycie zasob�w komputera. Dob�r w�a�ciwego konetenera jest zale�ny od tego, co chcemy zrobi�. Najcz�ciej konetenery sekwencyjne b�d� listami i tablicami.
Kontenery asocjacyjne implementowane s� jako drzewa binarne (jeden rodzic, dw�ch potomk�w) co daje szybkie 
wyszukanie element�w o okre�lonej warto�ci.
Kontenery nieporz�dkuj�ce implementowane s� jako tablice mieszaj�ce.



*/





