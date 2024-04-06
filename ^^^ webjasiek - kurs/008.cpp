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
	VECTOR: kontener sekwencyjny (kolekcja uporz¹dkowana), z dostêpem bezpoœrednim do elementów, o ile znamy pozycjê elementu. Jest jak tablica ale z mo¿liwoœci¹ zmiany wielkoœci. Wektor pozwala dynamicznie zmieniaæ swoj¹ wielkoœæ, dodawanie na koniec wektora jest b. szybkie (a gdzie indziej wymusza przesuwanie elementów). Niektóre operacje realokuj¹ ca³¹ zawartoœæ wektora (przenosz¹ w inne miejsce pamiêci). 
	
	Iteratory wektorów s¹ iteratorami dostêpu swobodnego.

*/

void _008() {

	vector<int> vec1(20, 5); // wektor o 20-u elementach, ka¿da o wartoœci 5
	printSTL(vec1, " ", true);		
	
	/*
	ITERATORY : 
Reprezentuj¹ POZYCJÊ elementu w KONTENERZE ! (mo¿na myœleæ o nich jak o wskaŸnikach zawieraj¹cych pozycjê przechowywanych elementów, choæ nie s¹ wskaŸnikiem w rozumieniu jêzyka C).
	Iterator to taki obiekt, który "iteruje" po elementach kontenera, czyli "przechodzi od jednego do drugiego", nawiguje. Na iteratorach mo¿na wykonywaæ operacjê:
	* : pobierania elementu na który wskazuje iterator (wy³uskanie, zupe³nie jak wy³uskanie z jêzyka C)
	++ (niekiedy --) : pozwala przejœæ do nastêpnego (niekiedy poprzedniego) elementu
	== i != : porównuje iteratory, czy s¹ równe ? (czy wskazuj¹ na to samo)
	= : przypisuje do iteratora pozycjê elementów odpowiedniego typu
	ITERATORY maj¹ swoje kategorie:
	- postêpuj¹cy (przesuwa siê tylko "w przód" za pomoc¹ ++)
	- dwukierunkowy (operator ++ i -- s¹ dopuszczone, poruszamy siê "w przód i w ty³")
	- swobodnego dostêpu (realizuj¹ ++, -- ale mog¹ dobraæ siê do dowolnego elementu bezpoœrednio
	bez "przechodzenia" przez kolejne elementy kolekcji, mo¿na je dodawaæ, odejmowac, 
	porównywaæ (<, >)  i s¹ dostêpne dla kontenerów vector i deque (oraz w napisach, specjalnych kontenerach))

	metody zwracaj¹ce iteratory kontenerów:  
	begin(), end(), cbegin(), cend(), crbegin(), crend(), rbegin(), rend()
	*/

	// .begin() iterator na pierwszy
	// .end() iterator 'za ostatnim'
	vector<int> vec2 { 1, 2, 3, 4, 5 };			
	for (auto iter = vec2.begin(); iter != vec2.end(); ++iter) cout << *iter << " ";
	cout << endl;
	auto iter = vec2.begin() + 3; // swobodny dostêp pozwala na przejœcie
	cout << *iter << endl; // Ha! 4
	
	
	// ::const_iterator pozwala tylko odczytywaæ, a ::iterator równie¿ zmieniaæ elementy
	vector<int>::const_iterator it = vec2.begin(); // auto it te¿ oczywiœcie wystarczy ;)
	while (it != vec2.end()) cout << *it++ << " "; // pobieram *it a potem it++		
	cout << endl;
	cout << vec2.front() << endl; // pierwszy element (nie iterator) /1
	cout << vec2.back() << endl; // ostatni element (nie iterator) /5

	// cbegin() : <vector<int>>::const_iterator -  niemodyfikowalny iterator na pierwszy element
	// cend() : niemodyfikowalny iterator na 'za ostatnim' elementem
	// crbegin() : iterator odwrotny (pierwszy ale id¹c od ty³u), do tego const_iterator niemodyfikowalny
	cout << *vec2.cbegin() << endl; // 1
	cout << *--vec2.cend() << endl; // 5 (przejdŸ na iterator przed ostatnim i wy³uskaj)
	cout << *++vec2.crbegin() << endl;  // 4
	for (auto it = vec2.crbegin(); it != vec2.crend(); ++it) cout << *it << " "; // 5,4,3,2,1
	cout << endl;

	// at(pozycja) w miejsce [pozycja] - sprawdza, czy nie wyszliœmy poza zakres wektora
	// size() - ile elementów
	// push_back(coœ) - wstawia na koniec coœ
	// pop_back() - usuwa z koñca
	// reserve(TYLE) - zarezerwuje pamiêæ na TYLE elementenów
	// capacity() - na ile zarezerwowano miejsca ?
	vector<int> v { 1,2,3,4,5,6,7,8,9,10,1,2,3,4 };
	cout << &v[0] << endl;
	cout << v.size() << " " << v.at(10) << endl;
	v.push_back(5); // dodaj na koniec 5...
	v.pop_back(); // i zabierz z koñca to 5
	v.reserve(100); 
	cout << v.size() << " " << v.capacity() << endl;	

	/// ZALECANE METODY usuwania z wektora (c++17)
	/// 1 metoda
	printSTL(v, " ", true);
	cout << &v[0] << endl;
	cout << v.capacity()<<endl; // zarezerwowana iloœæ mo¿e byæ wiêksza ni¿ size()
	
	// remove(its,ite,n) (w podanym zakresie (iterator star i koniec) usuñ wszystkie wartoœci n). remove() zwraca pozycje koñca (tyle wczeœniejszy iterator ile elementów usuniêto)
	auto newEnd = remove(v.begin(), v.end(), 2); // pozbêdzie siê 2-ek, przesuwaj¹c elementy w ramach pamiêci. NIE zmieni siê alokowana pamiêæ... (nie bêdzie przeniesienia!)
	printSTL(v," ",true); // nie ma dwóch 2-ek, ale rozmiar i elementy pozosta³y (na koñcu s¹ 2 niepotrzebne elementy) .size() nie zmieni³ siê !
	cout << &v[0] << endl; // pamiêæ ta sama
	cout << v.capacity() << endl << endl;
	
	// erase(its,ite) - usuwa wszystko pomiêdzy iteratorami i zmniejsza rozmiar
	v.erase(newEnd, v.end()); // 
	printSTL(v, " ", true); // proszê: ju¿ rozmiar mniejszy...
	cout << &v[0] << endl;
	cout << v.capacity() << endl << endl; // ... ale pamiêci zarezerwowanej wci¹¿ tyle samo
	
	v.shrink_to_fit();	// a teraz pamiêæ jest OK, dopasujê size() i capacity()...
	cout << &v[0] << endl; // ... ale nast¹pi³o przeniesienie wszystkiego w inny rejon pamiêci
	cout << v.capacity() << string(3,'\n');

	// 2 matoda
	// usuwanie mo¿na przeprowadziæ poprzez zamianê z ostatnim i wywalenie ostatniego :)	
	// fajne, gdy nie zale¿y mi na posortowaniu elementów wektora
	// poni¿sza pêtla usuwa wszystkie wyst¹pienia liczby 5
	do {
		if (auto foundIndex = find(v.begin(), v.end(), 5); foundIndex != v.end()) {
			*foundIndex = v.back(); // w miejsce gdzie by³o 5 wstawiam to co sta³o na koñcu
			v.pop_back();			
		}
		else break;
	} while (true);
	printSTL(v, " ", true);
	cout << &v[0] << endl; //
	cout << v.capacity() << endl << endl;
	v.shrink_to_fit(); // zmieniam rozmiar
	cout << v.capacity() << " " << v.size() << " " << &v[0] << endl;
	v.resize(50, 0); // zwiêksza size do 50, nowe zape³nia zerami
	cout << v.size() << " " << v.capacity() << " " << &v[0] << endl;
	printSTL(v, " ", true);
}



/*

KONTENERY ASOCJACYJNE / KOLEKCJE SORTOWANE
Pozycja elementu zale¿y od jego wartoœci, lub klucza gdy mamy doczynienia z par¹ klucz-wartoœæ.
Elementy tego kontenera s¹ sortowane domyœlnie wed³ug pewnego kryterium. Kolejnoœæ czy moment wstawiania elementu nie ma wiêc znaczenia.
Domyœlnie sortowanie jest wg algorytmu "od mniejszego do wiêkszego" ( operator < ). Mo¿na to zmieniæ.
set, multiset, map, multimap
KONTENERY NIEPORZ¥DKUJ¥CE - pozycja elementów nie jest okreœlona/istotna bo nie ma znaczenia wartoœæ czy klucz
elementów ani moment ich wk³adania do kolekcji. Zg³ównym zadaniem tych kontenerów jest okreœlenie - czy dany element 
wystêpuje w kolekcji (a nie gdzie).
unordered_set, unordered_multiset, unordered_map, unordered_multimap (œwietna jako s³ownik!)

Ró¿ne kontenery maj¹ swoje zalety i wady - g³ównie chodzi o prêdkoœæ dzia³añ na kontenerach, czas wyszukiwania elementów co siê przek³ada na zu¿ycie zasobów komputera. Dobór w³aœciwego konetenera jest zale¿ny od tego, co chcemy zrobiæ. Najczêœciej konetenery sekwencyjne bêd¹ listami i tablicami.
Kontenery asocjacyjne implementowane s¹ jako drzewa binarne (jeden rodzic, dwóch potomków) co daje szybkie 
wyszukanie elementów o okreœlonej wartoœci.
Kontenery nieporz¹dkuj¹ce implementowane s¹ jako tablice mieszaj¹ce.



*/





