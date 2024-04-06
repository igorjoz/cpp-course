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
	set (zbi�r), multiset (multizbi�r) to kontener asocjacyjny, porz�dkuj�cy/sortuj�cy.
	W set element mo�e wyst�pi� tylko raz. Dla multiset, elementy mog� si� powtarza� i tak�e zachowuj� porz�dek. Zbi�r to zazwyczaj zr�wnowa�one drzewo binarne. Dlatego plusem jest:
	+ szybkie wyszukiwanie element�w o okre�lonej warto�ci!
	Zbi�r jest automatycznie sortowany wg ustalonych kryteri�w. Elementy w zbiorze niezale�nie od typu powinny da� si� posortowa�. Porz�dkowanie musi mie� w�a�ciwo�ci:
	* asymetryczne (gdy x<y jest prawd�, to y<x jest fa�szem i odwrotnie),
	* przechodnie (x<y i y<z to x<z) (r�wnowa�no�� te� musi by� przechodnia, a=b i b=c to a=c)
	* niezwrotne (x<x to zawsze fa�sz)
	
	Automatyczne sortowanie w zbiorze ma jednak i wady: 
	- w c++11 bezpo�rednia zmiana przechowywanych warto�ci w zbiorze mo�e zaburzy� drzewo binarne (element usuwa�o si� i wk�ada�o ponownie, a iterator widzi elementy jako sta�e). W c++17 s� pewne rozwi�zania, kt�re to obchodz�.
	
*/

void _025() {				
	// elementami s� obiekty typu string, mo�na je porz�dkowa�
	set<string> snames{ "Kowalski","Nowak","Brz�yszczykiewicz","Kowalski" };
	printSTL(snames,", ",true);	
	snames.insert({ "Kowalski", "Adamski", "Piotrowski", "Zenonkowski", "Kowalski" });
	printSTL(snames,", ",true);
	// insert pojedy�czego elementu zwraca par� <iterator,bool> gdzie iterator to pozycja po wstawieniu, o ile si� uda�o (jak ju� by� element to si� nie uda)	
	auto [pos, success] = snames.insert("Uf");
	cout << *pos << " " << success << endl;
	if (!snames.insert("Uf").second) cout << "ju� jest!" << endl;
	
	auto [pos2,success2] = snames.insert("Kowalski");
	cout << *pos2 << " " << success2 << endl;
	

	// elementami jest int, mo�na porz�dkowa�
	set<int, greater<int>> mono = { 2,3,4,1,2,5,5,3,6,7,8,11,24 }; /// drugi parametr greater<int> zmienia spos�b sortowania dla kontener�w porz�dkuj�cych . Domy�lny jest spos�b less<>. greater i less to OBIEKTY funkcyjne (wkr�tce o nich). Teraz mo�na my�le� o nich jako o narz�dziu sortuj�cym obiekty w momencie wk�adania ich do zbioru.	
	printSTL(mono,", ",true); //  uporz�dkowane malej�co

	set<int, less<int>> mono2 = { 2,3,4,1,2,5,5,3,6,7,8,11,24 }; // less jest domy�lne ale tutaj u�y�em go jawnie
	printSTL(mono2, ", ", true);
	if (!mono2.empty()) cout << "Nie jestem pusty!\n";
	mono2.clear();
	printSTL(mono2, ": ", true);
	
	/// count(), find(), lower_bound(), upper_bound(), equal_range()
	// insert, erase, clear
	   

	// elementami s� obiekty string, a wi�c da si� je porz�dkowa�. multiset mo�e mie� wiele element�w identycznych, pami�taj o tym. Te� s� porz�dkowane.
	multiset<string> dogs{ "Burek","Reksio","Burek","Reksio","Pyra","Apofis" };
	printSTL(dogs," ",true);
	dogs.insert({ "Burek","�ulek" }); // Nowy wstawia si� na KONIEC istniej�cych a takich samych element�w. Taki insert nic nie zwraca.
	printSTL(dogs," ", true); 	
	
	// emplace - wstaw i poka� gdzie
	auto insertIt = dogs.emplace("D�d�on"); // wstawia kopie i zwraca pozycj�
	cout << *insertIt << endl; // iterator pozycji wstawionej	
	printSTL(dogs, ",", true);

	// count()
	cout << dogs.count("Burek") << endl; // ile Burk�w ?

	// find() - zwraca pozycj� pierwszego elementu
	multiset<string>::iterator it = dogs.find("Reksio");
	if (it != dogs.end()) {
		cout << *it << endl;		
		dogs.erase(it);
		printSTL(dogs, ", ", true);
	}	


	it = dogs.lower_bound("Burek"); // iterator na pierwszy element >= "Burek"
	cout << *it << endl;
	// a tu takie info, �e w sumie i find i lower_bound robi� przy takim wywo�aniu to samo i zwracaj� dok�adnie ten sam iterator
	cout << (dogs.find("Burek") == dogs.lower_bound("Burek")) << endl;
	

	it = dogs.upper_bound("Burek"); // iterator na pierwszy element > "Burek"
	cout << "Za Burkiem: " << *it << endl;
	

	// zwraca par�: lower_bound + upper_bound
	auto [first, last] = dogs.equal_range("Burek");
	cout << *first << " " << *last << endl;
	while (first != last) { // id� od operatora first do last (bez last) i pokazuje co tam jest
		cout << *first << " ";
		first++;
	} // b�d� same Burki
	
	


		
}
