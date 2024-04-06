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
	KONTENERY ASOCJACYJNE / KOLEKCJE SORTOWANE : Pozycja elementu zale¿y od jego wartoœci, lub klucza gdy mamy doczynienia z par¹ klucz-wartoœæ. Elementy tego kontenera s¹ sortowane domyœlnie wed³ug pewnego kryterium. Kolejnoœæ czy moment wstawiania elementu nie ma wiêc znaczenia.Domyœlnie sortowanie jest wg algorytmu "od mniejszego do wiêkszego" ( operator < ). Mo¿na to zmieniæ.
	
	map przechowuje pary klucz-wartoœæ, gdzie klucz nie mo¿e siê powtarzaæ, a w multimap - mo¿e  w obu przypadkach wartoœci klucza nie mo¿na zmieniaæ, a ta para to w rzeczywistoœci typ pair<const klucz,wartoœæ>; Mapa jest najczêœciej implementowana z pomoc¹ drzewa binarnego (chodzi o wyszukiwanie klucza i wstawianie klucza o z³o¿onoœci log(n), obie operacje tyle samo kosztuj¹, bo wyszukanie i wstawianie szuka miejsca w drzewie. Mapa ma swoje algorytmy równowa¿enia drzewa, niemniej odsy³am do poznania drzewa i zwi¹zanych z nim mechanik. Tutaj nie skupiam siê na tych bebechach mapy, co raczej na tym, jak z niej korzystaæ).
	*/
	
	map<int, string> ids;
	ids = {
		{21,"gor¹ca woda"},
		{8,"fili¿anka"},
		{11,"cukier"},
		{3,"³y¿ka"},
		{19,"herbatka"}
	};
	ids.insert({ {11,"cytrynka"},{12,"imbir"} }); // cytrynka siê nie doda :( 11 ju¿ jest !	
	ids[1000] = "kropla mi³oœci"; // HA ! dzia³a bez insert ;) Doda siê nowy element. Ale uwaga! To nie jest indeks jak w tablicach, jest to tzw. tablica asocjacyjna a 1000 to klucz. Równie dobrze kluczem tu mo¿e byæ napis itp.
	for (auto& elem : ids) {
		cout << elem.first << "==" << elem.second << endl;
	}	

	// obiekty funkcyjne do sortowania podobnie jak w zbiorze
	map<float, float, greater<float>> malej{ {1,2},{2.4,2.1},{0,10} };
	for (auto [k, v] : malej) cout << k << "=" << v << " ";
	cout << "[" << malej.size() << "]" << endl;

	for_each(
		malej.begin(), malej.end(),
		[](pair<const float,float>& element) { // mo¿na te¿ decltype(malej)::value_type
			element.second += 1;
		}
	);
	for (auto [k, v] : malej) cout << k << "=" << v << " ";
	cout << "[" << malej.size() << "]" << endl;

	// funkcje takie jak w zbiorze: count(klucz), find(klucz),
	// lower_bound, upper_bound, equal_range

	
	// c++17
	map<unsigned int, pair<const string, string>> m1{ {1,{"kod","123"}}, {2,{"kod","234"}} };	
	// try_emplace - warunkowe tworzenie elementu (je¿eli klucz istnieje, nie utworzy pary)
	// jak nie istnieje ,dopiero zrobi parê z dwóch pozosta³ych elementów. Wczeœniej korzystaliœmy z wci¹¿ sensownych metod insert i emplace
	auto [it, ok] = m1.try_emplace(1, "kod","456");
	cout << it->first << " " << it->second.second << " " << ok << endl; // iterator do elementu koliduj¹cego z potencjalnie wstawianyn, oraz wartoœæ false (po nie uda³o siê wstawiæ)
	auto [it2, ok2] = m1.try_emplace(3, "kod", "456");
	cout << it2->first << " " << it2->second.second << " " << ok2 << endl;  // iterator do nowo wstawionego elementu i true (bo uda³o siê wstawiæ)

	// rozpakowanie
	for(auto & e : m1) {
		auto& [key, value] = e;
			cout << key << "=>" << value.first << ", " << value.second << endl;
	}
	// rozpakowanie bez poœrednika jak wy¿ej, od razu siorbiê klucz i vartoœæ
	for (auto& [k, v] : m1) {
		cout << k << "=>" << v.first << v.second << " ";
	} 
	cout << endl;

	// Wstawianie mo¿e byæ poprzedzone tzw. PODPOWIEDZI¥. Jest to podanie pewnego elementu
	// w drzewie, który mo¿e byæ prawid³ow¹ podpowiedzi¹ (lub nie).
	// Gdy podpowiedŸ jest prawid³owa czas takiego w³o¿enia jest O(1). Gdyby podpowiedŸ okaza³a siê b³êdna, to element zostanie w³o¿ony normaln¹ drog¹ (poprzedzone wyszukiwaniem o z³o¿noœci O(log(n)).
	/* 
	PodpowiedŸ poprawna jest iteratorem istniej¹cego elementu, który jest wiêkszy (chodzi o klucz) ni¿ element przeznaczony do wstawienia. Dlatego nowy klucz zostanie umieszczony w miejscu znajduj¹cym siê tu¿ przed elementem wskazanym przez podpowiedŸ. 
	*/
	auto podpow = m1.end(); // na pocz¹tku nie mam lepszej podpowiedzi, biorê coœ...
	podpow = m1.insert(podpow, { 10, {"kod","500"} } );
	podpow = m1.insert(podpow, { 4, {"kod","750"} } );
	podpow = m1.insert(podpow, { 0, {"kod","900"} } );
	for (auto& [k, v] : m1) {
		cout << k << "=>" << v.first << v.second << " ";
	} 
	cout << endl;

	// Normalnie klucza nie wolno modyfikowaæ, dlatego elementy siê usuwa³o i potem ponownie dodawa³o zgodnie z logik¹ wewnêtrznego drzewa. ALE od C++17 jest mo¿liwa pewna operacja...
	map<int, string> m2{ {1,"Mleko"},{2,"Woda"},{3,"Herbata"},{4,"Kawa"},{5,"Maœlanka"},{6,"Podpiwek"},{7,"Serwatka"} }; // hierarchia ulubionych napojów
	for (auto& [k, v] : m2) {
		cout << k << "=>" << v << " ";
	}
	cout << endl;
	/// ... mianowicie jest nowa funkcja, extract(klucz) - która usuwa element z mapy ale nie ma skutków ubocznych zwi¹zanych z alokowan¹ pamiêci¹ (elementy, ich struktura w pamiêci nie zaburza siê). 
	/// Powiedzmy, ¿e nagle polubi³em Serwatkê a Mleko spad³o na koniec napojów ulubionych.
	{
		auto temp1 = m2.extract(1); // podejê klucz, mo¿na te¿ podaæ iterator, bêdzie szybciej
		auto temp2 = m2.extract(7);
				// cout << typeid(temp1).name() << endl; // spradŸcie jaki to typ :-D
		swap(temp1.key(), temp2.key()); // klucze s¹ niemodyfikowalne w mapie, ale te pobrane przez extract ju¿ s¹
		m2.insert(move(temp1));
		m2.insert(move(temp2)); // insert od c++17 ma mo¿liwoœæ przesuniêcia wyodrêbnionego wêz³a.
	}
	for (auto& [k, v] : m2) {
		cout << k << "=>" << v << " ";
	}
	// powy¿szy mechanizm niejako podmienia miejscami ca³e pary w mapie. Mo¿na je tak podmieniaæ równie¿ pomiêdzy ró¿nymi mapami, ale musz¹ byæ zachowane typy
	cout << string(3, '\n');
	
	// multimapa
	multimap<int, string> ids2; // po prostu wiele kluczy
	ids2 = {
		{21,"gor¹ca woda"},
		{8,"fili¿anka"},
		{11,"cukier"},
		{3,"³y¿ka"},
		{19,"herbatka"}
	};  
	ids2.insert({ {11,"cytrynka"},{12,"imbir"} }); // cytrynka siê doda pod tym samym kluczem
	for (auto& elem : ids2) {
		cout << elem.first << "==" << elem.second << endl;
	}

}
