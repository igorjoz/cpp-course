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
	 numeric_limits
oraz
	 predykaty (funkcje pomocnicze dla algorytm�w) - ALE KORZYSTAMY JU� Z LAMBD gdy to mo�liwe
*/
bool predykat1(int& n) {
	// sprawdzam, czy liczba jest parzysta i podzielna przez 7 (taki kaprys)
	n = abs(n); // jej znak nie ma znaczenia
	return (n % 2 == 0 && n % 7 == 0);
}
void _017() {
	/* z klasy numeric_limits korzystamy, gdy ...*/
	cout << numeric_limits<int>::max() << endl; // chcemy zobaczy� zakresy typ�w liczbowych
	cout << numeric_limits<short>::max() << endl;
	cout << numeric_limits<long long>::min() << endl;
	cout << numeric_limits<float>::min() << endl;
	cout << numeric_limits<long double>::max() << endl;
	cout << numeric_limits<int>::is_signed << endl; // sprawdzi� znak typu liczbowego
	cout << numeric_limits<int>::is_exact << endl; // b��dy zaokr�gle� (dla ca�kowitych nie ma b��d�w, true)	
	cout << numeric_limits<int>::digits << endl; // liczba bit�w bez znaku 
	cout << numeric_limits<int>::digits10 << endl; // liczba cyfr dec
	cout << numeric_limits<int>::is_modulo << endl; // czy dodanie liczb mo�e da� mniejsza sum� przy przekroczeniu zakresu ? (2+2 dla zbioru 0-3 to 0)
	cout << numeric_limits<float>::epsilon() << endl; // r�nica warto�ci 1 i najmniejszej warto�ci wi�kszej od 1
	cout << numeric_limits<long double>::infinity() << endl; // warto�� dodatkniej niesko�czono�ci o ile jest
	cout << numeric_limits<float>::quiet_NaN() << endl; // niesygnalizowana warto�� nieliczbowa o ile jest
	
	/* predykaty:
		funkcje pomocnicze dla algorytm�w, kt�re zwracaj� bool. Okre�laj� sposoby wyszukiwania, sortowania poprzez np. por�wnanie (1-2 argumentowe).
		predykaty musz� jednoznacznie zwraca� wyniki (ta sama warto�� musi zwraca� ten sam wynik).
		(je�eli to mo�liwe, w miejsce predykat�w u�ywaj lambd)
	*/
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}
	printSTL(v, ",", true);
	auto pos = v.begin();
	do {
		pos = find_if(pos, v.end(), predykat1); // find_if to algorytm og�lny
		if (pos != v.end()) {
			cout << *pos << " ";
			pos++;
		}
	} while (pos != v.end()); // szukam wszystkie spe�niaj�ce warunek podzielno�ci przez 2 i 7
	// predykaty dwuargumentowe zazwyczaj zajmuj� si� jakimi� por�wnaniami bardziej z�o�onych element�w
	/*
		dla wyimagowanego, z�o�onego obiektu, predykat 2-arg m�g�by np. sprawdza� kilka p�l
		bool kryteriumSortowania(const class& obj1, const class& obj2) {
			return (obj1.p1 < obj2.p1) ||
			(obj1.p2 <= obj2.p2) ||
			(obj1.p3 > obj2.p3);
		}
		sort(collection.begin(), collection.end(), kryteriumSortowania);		
		Predykat uznaje obj1 za mniejszy gdy jest spe�niony jeden z warunk�w konkretnego pola (w tym wypadku wystarczy jeden).
		Je�eli �aden warunek nie b�dzie OK, obiekt uznany zostanie za wi�kszy
		Taki predykat mo�e by� wywo�any w algorytmie sort:		
	*/	
	// stosowanie lambd w miejsce predykat�w jest lepsze, czytelniejsze, unikamy szukania predykatu i wygl�daj� "magiczniej" :-D
	// spr�bujemy lambd� posortowa� zbi�r pod k�tem parzysto�ci: parzyte rosn�co najpierw, potem nieparzyste rosn�co
	long long C(0);
	sort(v.begin(), v.end(),
		[&](int& i, int& j) {
			C++;
			return ((i % 2 == 0) && (j % 2 != 0) ||   // parzyste na lewo nieparzyste na prawo
				(i % 2 == 0 && j % 2 == 0 && i < j) || // mniejsze parzyste na lewo
				(i % 2 != 0 && j % 2 != 0 && i < j)); // mniejsze nieparzyste na lewo
		});
	cout << endl << endl;
	for (auto& e : v) cout << e << " "; // i prosz� !
	cout << endl << "Algorytm sortuj�cy wywo�a� lambd� " << C << " razy" << endl;

}

