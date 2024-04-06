#include <iostream>
#include <array> // tablica
#include <vector> // wektor
#include <deque> // kolejka z dwoma koñcami
#include <list> // lista
#include <forward_list> // lista jednokierunkowa
#include <set> // zbiór
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
#include <memory> // inteligentne wskaŸniki
#include <functional> // reference_wrapper<>
#include <chrono> // czas
#include <iomanip> // manipulatory io
#include <string> // wiadomo
#include <thread> // w¹tki 
#include <ctime>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "numbers.h"

// C++17
using namespace std;
/*
	 numeric_limits
oraz
	 predykaty (funkcje pomocnicze dla algorytmów) - ALE KORZYSTAMY JU¯ Z LAMBD gdy to mo¿liwe
*/
bool predykat1(int& n) {
	// sprawdzam, czy liczba jest parzysta i podzielna przez 7 (taki kaprys)
	n = abs(n); // jej znak nie ma znaczenia
	return (n % 2 == 0 && n % 7 == 0);
}
void _017() {
	/* z klasy numeric_limits korzystamy, gdy ...*/
	cout << numeric_limits<int>::max() << endl; // chcemy zobaczyæ zakresy typów liczbowych
	cout << numeric_limits<short>::max() << endl;
	cout << numeric_limits<long long>::min() << endl;
	cout << numeric_limits<float>::min() << endl;
	cout << numeric_limits<long double>::max() << endl;
	cout << numeric_limits<int>::is_signed << endl; // sprawdziæ znak typu liczbowego
	cout << numeric_limits<int>::is_exact << endl; // b³êdy zaokr¹gleñ (dla ca³kowitych nie ma b³êdów, true)	
	cout << numeric_limits<int>::digits << endl; // liczba bitów bez znaku 
	cout << numeric_limits<int>::digits10 << endl; // liczba cyfr dec
	cout << numeric_limits<int>::is_modulo << endl; // czy dodanie liczb mo¿e daæ mniejsza sumê przy przekroczeniu zakresu ? (2+2 dla zbioru 0-3 to 0)
	cout << numeric_limits<float>::epsilon() << endl; // ró¿nica wartoœci 1 i najmniejszej wartoœci wiêkszej od 1
	cout << numeric_limits<long double>::infinity() << endl; // wartoœæ dodatkniej nieskoñczonoœci o ile jest
	cout << numeric_limits<float>::quiet_NaN() << endl; // niesygnalizowana wartoœæ nieliczbowa o ile jest
	
	/* predykaty:
		funkcje pomocnicze dla algorytmów, które zwracaj¹ bool. Okreœlaj¹ sposoby wyszukiwania, sortowania poprzez np. porównanie (1-2 argumentowe).
		predykaty musz¹ jednoznacznie zwracaæ wyniki (ta sama wartoœæ musi zwracaæ ten sam wynik).
		(je¿eli to mo¿liwe, w miejsce predykatów u¿ywaj lambd)
	*/
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}
	printSTL(v, ",", true);
	auto pos = v.begin();
	do {
		pos = find_if(pos, v.end(), predykat1); // find_if to algorytm ogólny
		if (pos != v.end()) {
			cout << *pos << " ";
			pos++;
		}
	} while (pos != v.end()); // szukam wszystkie spe³niaj¹ce warunek podzielnoœci przez 2 i 7
	// predykaty dwuargumentowe zazwyczaj zajmuj¹ siê jakimiœ porównaniami bardziej z³o¿onych elementów
	/*
		dla wyimagowanego, z³o¿onego obiektu, predykat 2-arg móg³by np. sprawdzaæ kilka pól
		bool kryteriumSortowania(const class& obj1, const class& obj2) {
			return (obj1.p1 < obj2.p1) ||
			(obj1.p2 <= obj2.p2) ||
			(obj1.p3 > obj2.p3);
		}
		sort(collection.begin(), collection.end(), kryteriumSortowania);		
		Predykat uznaje obj1 za mniejszy gdy jest spe³niony jeden z warunków konkretnego pola (w tym wypadku wystarczy jeden).
		Je¿eli ¿aden warunek nie bêdzie OK, obiekt uznany zostanie za wiêkszy
		Taki predykat mo¿e byæ wywo³any w algorytmie sort:		
	*/	
	// stosowanie lambd w miejsce predykatów jest lepsze, czytelniejsze, unikamy szukania predykatu i wygl¹daj¹ "magiczniej" :-D
	// spróbujemy lambd¹ posortowaæ zbiór pod k¹tem parzystoœci: parzyte rosn¹co najpierw, potem nieparzyste rosn¹co
	long long C(0);
	sort(v.begin(), v.end(),
		[&](int& i, int& j) {
			C++;
			return ((i % 2 == 0) && (j % 2 != 0) ||   // parzyste na lewo nieparzyste na prawo
				(i % 2 == 0 && j % 2 == 0 && i < j) || // mniejsze parzyste na lewo
				(i % 2 != 0 && j % 2 != 0 && i < j)); // mniejsze nieparzyste na lewo
		});
	cout << endl << endl;
	for (auto& e : v) cout << e << " "; // i proszê !
	cout << endl << "Algorytm sortuj¹cy wywo³a³ lambdê " << C << " razy" << endl;

}

