#include <iostream>
#include <deque>
#include <vector>
#include "numbers.h"
using namespace std;
// C++17
/*
deque - kolejka o dw�ch ko�cach: Jest to kontener sekwencyjny podobny do wektora. Wstawianie i usuwanie element�w na pocz�tku i ko�cu kolejki jest operacj� bardzo szybk�.
Gdy wstawiam/usuwam co� ze �rodka, nast�puje uniwa�nienie wszystkich iterator�w do element�w a do tego ta operacja jest wolna. deque nie oferuje mo�liwo�ci sterowania pojemno�ci�, nie pozwala sterowa� realokacj� element�w.
Iteratory deque s� iteratatorami swobodnego dost�pu. 
Interfejs deque jest bardzo podobny do interfajsu wektor�w (posiada podobne/te same 
metody, kt�re pozwalaj� z niego korzysta�).
*/
void _004() {	
	
	deque<int> years;
	for (int i = 1; i <= 7; i++) years.push_front(2019 + i); 
	printSTL(years, ",", true);
	// max_size() - ile mog� wpakowa� takich element�w ?
	cout << years.size() << " " << years.max_size() << endl;
	years.pop_front(); // kasuj 2020 (szybko) // jest te� pop_back()	
	printSTL(years,",",true);
	
	years.push_back(3500); /// jest te� push_front	
	// mo�na korzysta� z indeks�w i metody at()
	for (int i = 0; i < years.size(); i++)
		cout << ((i % 2) ? years[i] : years.at(i)) << " "; // wyra�enie warunkowe
	cout << endl;
	years.pop_back(); // wywalam te 3500


	// resize(nowaIlo��) - zwi�ksza wielko��, nowe elementy odpalaj� si� z konstruktorem domy�lnym
	// resize(nowaIlo��, E) - nowe elementy s� kopi� E
	cout << &years[0] << endl;
	years.resize(years.size() + 5);
	printSTL(years, ",", true);
	cout << &years[0] << endl;



	// wstaw do �rodka za 3 elementem 1-k�
	years.insert(years.begin()+3,1); // wolna operacja w por�wnaniu z operacjami na ko�cach
	printSTL(years, ",", true);
	cout << &years[0] << endl;

	years.insert(years.end() - 3, 5, -1); // przed 3 elementem od ko�ca wstawiam 5 razy -1
	printSTL(years, ",", true);
	cout << &years[0] << endl;

	vector<int> v{ 999,998,997 }; // ten vektor da si� wstawi� do kolejki !
	auto in = years.insert(years.begin() + 1, v.begin(), v.end()); // wstawiam za pierwszym elementem wszystko co jest pomi�dzy iteratorami wektora v (w praktyce ca�y wektor v)
	printSTL(years, ",", true); 
	cout << &years[0] << endl;
	cout << *in << "!" << endl; // iterator na pierwszy spo�r�d wk�adanych element�w 

	auto next = years.erase(years.begin() + 1); // kasuj drugi element 999
	printSTL(years, ",", true);
	cout << &years[0] << endl;
	cout << *next << endl; // next - iterator nast�pnego elementu (za tym skasowanym)


	next = years.erase(years.begin()+3, years.end()-5); // kasuj� zakres
	printSTL(years, ",", true);	
	cout << *next << endl; // next - iterator nast�pnego elementu (za tym skasowanym)

	auto& it = years.emplace_front(100); // wstawia kopi�, zwraca referencj� do w�o�onego obiektu
	cout << it << endl;
	it = 200;
	printSTL(years, ",", true);

}




