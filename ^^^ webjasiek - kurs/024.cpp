#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <typeinfo>
#include <string>
#include <ctime>
#include <set>
#include <algorithm>
#include <iterator>
#include "numbers.h"


// C++17
using namespace std;

void _024() {				
	/*
	mapa, multimapa (kontener asocjacyjny/sortowany) (set, multiset, map, multimap)
	KONTENERY ASOCJACYJNE / KOLEKCJE SORTOWANE : Pozycja elementu zale�y od jego warto�ci, lub klucza gdy mamy doczynienia z par� klucz-warto��. Elementy tego kontenera s� sortowane domy�lnie wed�ug pewnego kryterium. Kolejno�� czy moment wstawiania elementu nie ma wi�c znaczenia.Domy�lnie sortowanie jest wg algorytmu "od mniejszego do wi�kszego" ( operator < ). Mo�na to zmieni�.
	
	map przechowuje pary klucz-warto��, gdzie klucz nie mo�e si� powtarza�, a w multimap - mo�e  w obu przypadkach warto�ci klucza nie mo�na zmienia�, a ta para to w rzeczywisto�ci typ pair<const klucz,warto��>; Mapa jest najcz�ciej implementowana z pomoc� drzewa binarnego (chodzi o wyszukiwanie klucza i wstawianie klucza o z�o�ono�ci log(n), obie operacje tyle samo kosztuj�, bo wyszukanie i wstawianie szuka miejsca w drzewie. Mapa ma swoje algorytmy r�wnowa�enia drzewa, niemniej odsy�am do poznania drzewa i zwi�zanych z nim mechanik. Tutaj nie skupiam si� na tych bebechach mapy, co raczej na tym, jak z niej korzysta�).
	*/
	
	map<int, string> ids;
	ids = {
		{21,"gor�ca woda"},
		{8,"fili�anka"},
		{11,"cukier"},
		{3,"�y�ka"},
		{19,"herbatka"}
	};
	ids.insert({ {11,"cytrynka"},{12,"imbir"} }); // cytrynka si� nie doda :( 11 ju� jest !	
	ids[1000] = "kropla mi�o�ci"; // HA ! dzia�a bez insert ;) Doda si� nowy element. Ale uwaga! To nie jest indeks jak w tablicach, jest to tzw. tablica asocjacyjna a 1000 to klucz. R�wnie dobrze kluczem tu mo�e by� napis itp.
	for (auto& elem : ids) {
		cout << elem.first << "==" << elem.second << endl;
	}	

	// obiekty funkcyjne do sortowania podobnie jak w zbiorze
	map<float, float, greater<float>> malej{ {1,2},{2.4,2.1},{0,10} };
	for (auto [k, v] : malej) cout << k << "=" << v << " ";
	cout << "[" << malej.size() << "]" << endl;

	for_each(
		malej.begin(), malej.end(),
		[](pair<const float,float>& element) { // mo�na te� decltype(malej)::value_type
			element.second += 1;
		}
	);
	for (auto [k, v] : malej) cout << k << "=" << v << " ";
	cout << "[" << malej.size() << "]" << endl;

	// funkcje takie jak w zbiorze: count(klucz), find(klucz),
	// lower_bound, upper_bound, equal_range

	
	// c++17
	map<unsigned int, pair<const string, string>> m1{ {1,{"kod","123"}}, {2,{"kod","234"}} };	
	// try_emplace - warunkowe tworzenie elementu (je�eli klucz istnieje, nie utworzy pary)
	// jak nie istnieje ,dopiero zrobi par� z dw�ch pozosta�ych element�w. Wcze�niej korzystali�my z wci�� sensownych metod insert i emplace
	auto [it, ok] = m1.try_emplace(1, "kod","456");
	cout << it->first << " " << it->second.second << " " << ok << endl; // iterator do elementu koliduj�cego z potencjalnie wstawianyn, oraz warto�� false (po nie uda�o si� wstawi�)
	auto [it2, ok2] = m1.try_emplace(3, "kod", "456");
	cout << it2->first << " " << it2->second.second << " " << ok2 << endl;  // iterator do nowo wstawionego elementu i true (bo uda�o si� wstawi�)

	// rozpakowanie
	for(auto & e : m1) {
		auto& [key, value] = e;
			cout << key << "=>" << value.first << ", " << value.second << endl;
	}
	// rozpakowanie bez po�rednika jak wy�ej, od razu siorbi� klucz i varto��
	for (auto& [k, v] : m1) {
		cout << k << "=>" << v.first << v.second << " ";
	} 
	cout << endl;

	// Wstawianie mo�e by� poprzedzone tzw. PODPOWIEDZI�. Jest to podanie pewnego elementu
	// w drzewie, kt�ry mo�e by� prawid�ow� podpowiedzi� (lub nie).
	// Gdy podpowied� jest prawid�owa czas takiego w�o�enia jest O(1). Gdyby podpowied� okaza�a si� b��dna, to element zostanie w�o�ony normaln� drog� (poprzedzone wyszukiwaniem o z�o�no�ci O(log(n)).
	/* 
	Podpowied� poprawna jest iteratorem istniej�cego elementu, kt�ry jest wi�kszy (chodzi o klucz) ni� element przeznaczony do wstawienia. Dlatego nowy klucz zostanie umieszczony w miejscu znajduj�cym si� tu� przed elementem wskazanym przez podpowied�. 
	*/
	auto podpow = m1.end(); // na pocz�tku nie mam lepszej podpowiedzi, bior� co�...
	podpow = m1.insert(podpow, { 10, {"kod","500"} } );
	podpow = m1.insert(podpow, { 4, {"kod","750"} } );
	podpow = m1.insert(podpow, { 0, {"kod","900"} } );
	for (auto& [k, v] : m1) {
		cout << k << "=>" << v.first << v.second << " ";
	} 
	cout << endl;

	// Normalnie klucza nie wolno modyfikowa�, dlatego elementy si� usuwa�o i potem ponownie dodawa�o zgodnie z logik� wewn�trznego drzewa. ALE od C++17 jest mo�liwa pewna operacja...
	map<int, string> m2{ {1,"Mleko"},{2,"Woda"},{3,"Herbata"},{4,"Kawa"},{5,"Ma�lanka"},{6,"Podpiwek"},{7,"Serwatka"} }; // hierarchia ulubionych napoj�w
	for (auto& [k, v] : m2) {
		cout << k << "=>" << v << " ";
	}
	cout << endl;
	/// ... mianowicie jest nowa funkcja, extract(klucz) - kt�ra usuwa element z mapy ale nie ma skutk�w ubocznych zwi�zanych z alokowan� pami�ci� (elementy, ich struktura w pami�ci nie zaburza si�). 
	/// Powiedzmy, �e nagle polubi�em Serwatk� a Mleko spad�o na koniec napoj�w ulubionych.
	{
		auto temp1 = m2.extract(1); // podej� klucz, mo�na te� poda� iterator, b�dzie szybciej
		auto temp2 = m2.extract(7);
				// cout << typeid(temp1).name() << endl; // sprad�cie jaki to typ :-D
		swap(temp1.key(), temp2.key()); // klucze s� niemodyfikowalne w mapie, ale te pobrane przez extract ju� s�
		m2.insert(move(temp1));
		m2.insert(move(temp2)); // insert od c++17 ma mo�liwo�� przesuni�cia wyodr�bnionego w�z�a.
	}
	for (auto& [k, v] : m2) {
		cout << k << "=>" << v << " ";
	}
	// powy�szy mechanizm niejako podmienia miejscami ca�e pary w mapie. Mo�na je tak podmienia� r�wnie� pomi�dzy r�nymi mapami, ale musz� by� zachowane typy
	cout << string(3, '\n');
	
	// multimapa
	multimap<int, string> ids2; // po prostu wiele kluczy
	ids2 = {
		{21,"gor�ca woda"},
		{8,"fili�anka"},
		{11,"cukier"},
		{3,"�y�ka"},
		{19,"herbatka"}
	};  
	ids2.insert({ {11,"cytrynka"},{12,"imbir"} }); // cytrynka si� doda pod tym samym kluczem
	for (auto& elem : ids2) {
		cout << elem.first << "==" << elem.second << endl;
	}

}
