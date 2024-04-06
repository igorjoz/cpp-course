#include <iostream>
#include <deque>
#include <vector>
#include "numbers.h"
using namespace std;
// C++17
/*
deque - kolejka o dwóch koñcach: Jest to kontener sekwencyjny podobny do wektora. Wstawianie i usuwanie elementów na pocz¹tku i koñcu kolejki jest operacj¹ bardzo szybk¹.
Gdy wstawiam/usuwam coœ ze œrodka, nastêpuje uniwa¿nienie wszystkich iteratorów do elementów a do tego ta operacja jest wolna. deque nie oferuje mo¿liwoœci sterowania pojemnoœci¹, nie pozwala sterowaæ realokacj¹ elementów.
Iteratory deque s¹ iteratatorami swobodnego dostêpu. 
Interfejs deque jest bardzo podobny do interfajsu wektorów (posiada podobne/te same 
metody, które pozwalaj¹ z niego korzystaæ).
*/
void _004() {	
	
	deque<int> years;
	for (int i = 1; i <= 7; i++) years.push_front(2019 + i); 
	printSTL(years, ",", true);
	// max_size() - ile mogê wpakowaæ takich elementów ?
	cout << years.size() << " " << years.max_size() << endl;
	years.pop_front(); // kasuj 2020 (szybko) // jest te¿ pop_back()	
	printSTL(years,",",true);
	
	years.push_back(3500); /// jest te¿ push_front	
	// mo¿na korzystaæ z indeksów i metody at()
	for (int i = 0; i < years.size(); i++)
		cout << ((i % 2) ? years[i] : years.at(i)) << " "; // wyra¿enie warunkowe
	cout << endl;
	years.pop_back(); // wywalam te 3500


	// resize(nowaIloœæ) - zwiêksza wielkoœæ, nowe elementy odpalaj¹ siê z konstruktorem domyœlnym
	// resize(nowaIloœæ, E) - nowe elementy s¹ kopi¹ E
	cout << &years[0] << endl;
	years.resize(years.size() + 5);
	printSTL(years, ",", true);
	cout << &years[0] << endl;



	// wstaw do œrodka za 3 elementem 1-kê
	years.insert(years.begin()+3,1); // wolna operacja w porównaniu z operacjami na koñcach
	printSTL(years, ",", true);
	cout << &years[0] << endl;

	years.insert(years.end() - 3, 5, -1); // przed 3 elementem od koñca wstawiam 5 razy -1
	printSTL(years, ",", true);
	cout << &years[0] << endl;

	vector<int> v{ 999,998,997 }; // ten vektor da siê wstawiæ do kolejki !
	auto in = years.insert(years.begin() + 1, v.begin(), v.end()); // wstawiam za pierwszym elementem wszystko co jest pomiêdzy iteratorami wektora v (w praktyce ca³y wektor v)
	printSTL(years, ",", true); 
	cout << &years[0] << endl;
	cout << *in << "!" << endl; // iterator na pierwszy spoœród wk³adanych elementów 

	auto next = years.erase(years.begin() + 1); // kasuj drugi element 999
	printSTL(years, ",", true);
	cout << &years[0] << endl;
	cout << *next << endl; // next - iterator nastêpnego elementu (za tym skasowanym)


	next = years.erase(years.begin()+3, years.end()-5); // kasujê zakres
	printSTL(years, ",", true);	
	cout << *next << endl; // next - iterator nastêpnego elementu (za tym skasowanym)

	auto& it = years.emplace_front(100); // wstawia kopiê, zwraca referencjê do w³o¿onego obiektu
	cout << it << endl;
	it = 200;
	printSTL(years, ",", true);

}




