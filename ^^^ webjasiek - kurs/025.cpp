#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <typeinfo>
#include <string>
#include <ctime>
#include "numbers.h"

// C++17

using namespace std;

/*
	set (zbiór), multiset (multizbiór) to kontener asocjacyjny, porz¹dkuj¹cy/sortuj¹cy.
	W set element mo¿e wyst¹piæ tylko raz. Dla multiset, elementy mog¹ siê powtarzaæ i tak¿e zachowuj¹ porz¹dek. Zbiór to zazwyczaj zrównowa¿one drzewo binarne. Dlatego plusem jest:
	+ szybkie wyszukiwanie elementów o okreœlonej wartoœci!
	Zbiór jest automatycznie sortowany wg ustalonych kryteriów. Elementy w zbiorze niezale¿nie od typu powinny daæ siê posortowaæ. Porz¹dkowanie musi mieæ w³aœciwoœci:
	* asymetryczne (gdy x<y jest prawd¹, to y<x jest fa³szem i odwrotnie),
	* przechodnie (x<y i y<z to x<z) (równowa¿noœæ te¿ musi byæ przechodnia, a=b i b=c to a=c)
	* niezwrotne (x<x to zawsze fa³sz)
	
	Automatyczne sortowanie w zbiorze ma jednak i wady: 
	- w c++11 bezpoœrednia zmiana przechowywanych wartoœci w zbiorze mo¿e zaburzyæ drzewo binarne (element usuwa³o siê i wk³ada³o ponownie, a iterator widzi elementy jako sta³e). W c++17 s¹ pewne rozwi¹zania, które to obchodz¹.
	
*/

void _025() {				
	// elementami s¹ obiekty typu string, mo¿na je porz¹dkowaæ
	set<string> snames{ "Kowalski","Nowak","Brzê¿yszczykiewicz","Kowalski" };
	printSTL(snames,", ",true);	
	snames.insert({ "Kowalski", "Adamski", "Piotrowski", "Zenonkowski", "Kowalski" });
	printSTL(snames,", ",true);
	// insert pojedyñczego elementu zwraca parê <iterator,bool> gdzie iterator to pozycja po wstawieniu, o ile siê uda³o (jak ju¿ by³ element to siê nie uda)	
	auto [pos, success] = snames.insert("Uf");
	cout << *pos << " " << success << endl;
	if (!snames.insert("Uf").second) cout << "ju¿ jest!" << endl;
	
	auto [pos2,success2] = snames.insert("Kowalski");
	cout << *pos2 << " " << success2 << endl;
	

	// elementami jest int, mo¿na porz¹dkowaæ
	set<int, greater<int>> mono = { 2,3,4,1,2,5,5,3,6,7,8,11,24 }; /// drugi parametr greater<int> zmienia sposób sortowania dla kontenerów porz¹dkuj¹cych . Domyœlny jest sposób less<>. greater i less to OBIEKTY funkcyjne (wkrótce o nich). Teraz mo¿na myœleæ o nich jako o narzêdziu sortuj¹cym obiekty w momencie wk³adania ich do zbioru.	
	printSTL(mono,", ",true); //  uporz¹dkowane malej¹co

	set<int, less<int>> mono2 = { 2,3,4,1,2,5,5,3,6,7,8,11,24 }; // less jest domyœlne ale tutaj u¿y³em go jawnie
	printSTL(mono2, ", ", true);
	if (!mono2.empty()) cout << "Nie jestem pusty!\n";
	mono2.clear();
	printSTL(mono2, ": ", true);
	
	/// count(), find(), lower_bound(), upper_bound(), equal_range()
	// insert, erase, clear
	   

	// elementami s¹ obiekty string, a wiêc da siê je porz¹dkowaæ. multiset mo¿e mieæ wiele elementów identycznych, pamiêtaj o tym. Te¿ s¹ porz¹dkowane.
	multiset<string> dogs{ "Burek","Reksio","Burek","Reksio","Pyra","Apofis" };
	printSTL(dogs," ",true);
	dogs.insert({ "Burek","¯ulek" }); // Nowy wstawia siê na KONIEC istniej¹cych a takich samych elementów. Taki insert nic nie zwraca.
	printSTL(dogs," ", true); 	
	
	// emplace - wstaw i poka¿ gdzie
	auto insertIt = dogs.emplace("D¿d¿on"); // wstawia kopie i zwraca pozycjê
	cout << *insertIt << endl; // iterator pozycji wstawionej	
	printSTL(dogs, ",", true);

	// count()
	cout << dogs.count("Burek") << endl; // ile Burków ?

	// find() - zwraca pozycjê pierwszego elementu
	multiset<string>::iterator it = dogs.find("Reksio");
	if (it != dogs.end()) {
		cout << *it << endl;		
		dogs.erase(it);
		printSTL(dogs, ", ", true);
	}	


	it = dogs.lower_bound("Burek"); // iterator na pierwszy element >= "Burek"
	cout << *it << endl;
	// a tu takie info, ¿e w sumie i find i lower_bound robi¹ przy takim wywo³aniu to samo i zwracaj¹ dok³adnie ten sam iterator
	cout << (dogs.find("Burek") == dogs.lower_bound("Burek")) << endl;
	

	it = dogs.upper_bound("Burek"); // iterator na pierwszy element > "Burek"
	cout << "Za Burkiem: " << *it << endl;
	

	// zwraca parê: lower_bound + upper_bound
	auto [first, last] = dogs.equal_range("Burek");
	cout << *first << " " << *last << endl;
	while (first != last) { // idê od operatora first do last (bez last) i pokazuje co tam jest
		cout << *first << " ";
		first++;
	} // bêd¹ same Burki
	
	


		
}
