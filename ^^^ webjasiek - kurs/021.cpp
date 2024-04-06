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

Kontenery nieporz�dkuj�ce implementowane s� jako tablice mieszaj�ce (a nie drzewa binarne!).
Istnieje tylko operator ++ (w prz�d). Nie ma np. rbegin(), rend().
Operacji dost�pu do elementu w mapie nieuporz�dkowanej jest zamortyzowany i sta�y bez wzgl�du na d�ugo�� i pozycj�.

*/
/*
	Ma�e wyja�nienie og�lne. Ucz�c si� C++ niekiedy trzeba si� "cofa�" i powtarza� (albo pog��bia�) rozumienie pewnych element�w. Dzieje si� tak dlatego, �e wiele element�w j�zyka jest mocno powi�zanych i chc�c dog��bnie wyt�umaczy� jedn� rzecz, musieliby�my t�umaczy� powi�zania, a te z kolejnymi powi�zaniami itd. Dlatego niekiedy pewne rzeczy omawiam kr�tko a nawet nie omawiam, zostawiaj�c tylko pewn� og�ln� informacj�. W innym odcinku b�dzie to pewnie wyja�nione. Wtedy warto wr�ci� do wcze�niejszego odcinka - wiedza si� uzupe�ni, a potem pog��bi i z ka�dym kolejnym elementem rozumienie dzia�ania r�nych technik b�dzie pe�niejsze. Uczenie si� (w tym uczenie C++ szczeg�lnie) przypomina troch� fale przyp�ywu. Wchodzimy w temat troch� (�eby zacz��, �eby ju� co� umie�), potem si� cofamy, potem podchodzimy do tematu znowu, ale troch� g��biej. Ka�da kolejna fala niby robi co� podobnego, ale zag��bia si� w l�d i poziom wody si� podnosi. I o to chodzi!
	Przegl�da�em kilka podr�cznik�w do C++ i sporo z nich jest zorganizowane mniej wi�cej tak:
	- 1 cz��: og�lnie o wszystkim, ale p�ytko, bez wchodzenia w szczeg�y
	- 2 cz��: dok�adniej, pokazuj�c zale�no�ci, t�umacz�c wi�cej, ale wci�� pozostawiaj�c pytania
	- 3 cz��: do ko�ca, ca�a specyfikacja (jednak i tu nie ma wszystkiego, dlatego cz�sto pe�ne rozumienie jakiej� funkcji/biblioteki/kodu wymaga po prostu STUDIOWANIA KODU, �R�D�A itp.)
	(m�wi�em o tym w jednej z lekcji)
*/

namespace hehe_space {
	const int ABC = 100;
}

struct myKey {
	string a;
	string b;
};
namespace std {
	bool operator==(const myKey& l, const myKey& r) { // operator por�wnania dw�ch element�w myKey
		return l.a == r.a && l.b == r.b;
	}
	template <>
	class hash<myKey> { // klasa hash'uj�ca, oblicza do jakiego kube�ka trafi element myKey
	public:
		using argument_type = myKey;
		using result_type = size_t;
		result_type operator()(const argument_type& c) const {
			size_t suma = 0;
			for (auto& znak : c.a) suma += znak;
			for (auto& znak : c.b) suma += znak;
			cout << "("<<suma<<")\n";
			return static_cast<result_type>(suma); // to nie jest za m�dre, ale przyk�ad ok
			// elementy s� przypisane do tego hash'a (poka�� na rysunku !) HASH powinien by� tak obliczany, aby by�o jak najmniej powt�rze� dla elementu. static_cast to rzutowanie, om�wimy w przysz�o�ci
		}
	};
	// bucket_count() - ilo�� kube�k�w :)
	// rehash(n) - przemieszanie i ustawienie conajmniej n kube�k�w
	// reserve(n) - przemieszanie kontenera by by�o miejsce dla minimum n element�w
	// max_load_factor(0.7) - warto�� do 1, ustawia maksymalny wsp�czynnik obci��enia 0.7,0.8 OK
	// max_load_factor() - zwraca ten maksymalny wsp�czynnik
	// load_factor() - zwraca obecny wsp�czynnik obci��enia
	// Uwaga! Mo�na si� dobra� do tych kube�k�w metodami:
	// bucket(val) - id kube�ka dla warto�ci val
	// begin(id_bucket) - zwraca iterator na element o podanym id kube�ka
	
}
void _021() {	
	// definiowanie czego�-tam we w�asnej przestrzeni (tak przy okazji)
	cout << hehe_space::ABC << endl; // ABC z przestrzeni hehe_space::
	// ABC; // bez hehe_space:: nie jest znane!

	/// unordered_set, unordered_multiset (nieuporz�dkowane zbiory i multizbiory)
	unordered_set<int> uset;
	uset = { 1,2,5,6,7,7,2,1,1,4,4,1 }; // elementy b�d� wyst�powa� tylko RAZ i w nieuporz�dkowany spos�b ...
	printSTL(uset,",",true); // ... oto dow�d.
	uset.insert({ 1, 2, 3, 100, 1, 100 }); // 1 i 2 ju� by�o, 3 i 100 si� wstawi�
	printSTL(uset, ",", true); // zwr�� uwag�, �e elementy nie s� zgodne z sekwencj� dodawania


	unordered_multiset<int> umset;
	umset = { 1,2,5,6,7,7,2,1,1,4,4,1 };  
	printSTL(umset, ",", true); // wszystkie s�
	umset.insert({ 1, 2, 3, 100, 1, 100 });
	printSTL(umset, ",", true);
	


	/// unordered_map
	unordered_map<string, int>elf;
	elf = { {"str",10},{"int",14},{"con",12},{"luck",10},{"hp",100},{"hp",200} }; // i tak zostanie pierwsze hp
	elf.insert({ { "str",11 }, {"dex",16} });
	cout << "Elf information:\n";
	for (auto& elem : elf) {
		cout << elem.first << "==" << elem.second << endl;
	}
	cout << "Elf str: " << elf["str"] << endl; // mo�na odwo�a� si� do klucza i u�ywa� jakby to by�a tablica, ale nie z indeksem ca�kowitym
	// co ciekawe, mog� "w locie" towrzy� nowy klucz !
	elf["quickness"] = 17;
	cout << "Elf quickness: " << elf["quickness"] << "!!!" << endl;
	// elf.at("ten atrybut nie istnieje") = 1; // zg�osi B��D. Metoda at() daje dost�p do warto�ci poprzez klucz, ale klucz musi istnie�.

	unordered_multimap<string, int>orc;
	orc = { {"str",20},{"int",9},{"con",18},{"luck",10},{"hp",400},{"hp",600} }; // i tak zostanie pierwsze hp
	orc.insert({ { "str",21 }, {"dex",6} });
	cout << "Orc information:\n";
	for (auto& elem : orc) {
		cout << elem.first << "==" << elem.second << endl;
	}
	///////////////// dziwne klucze wymagaj� obs�ugi
	unordered_map<myKey, int> umapWithMyKey = {
		{{"ab","bc"},10}, // !
		{{"c","d"},11}, // !
		{{"a","d"},12}, // !
		{{"ab","bc"},13}, // - (dubel klucza, nie przejdzie)
		{{"b","a"},14}, // ! 
		{{"a","a"},15}, // !
		{{"a","b"},16} // ! jak 14, ten sam kube�ek
	};
	for (auto [k, v] : umapWithMyKey) {
		cout << k.a << " " << k.b << "=" << v << endl;
	}

	/// a tu co� z kube�kami:
	cout << umapWithMyKey.bucket_size(umapWithMyKey.bucket({"a","b"})) << endl; // ile element�w w kuble?
	cout << umapWithMyKey.bucket_count() << endl; // ile kube�k�w dla mapy

	/// UWAGA! Je�eli uporz�dkowanie element�w w mapie (map) nie jest jakim� priorytetem dla Ciebie, korzystaj raczej z unordered_map. Koszt 
	
}
//////////////////////////////////
/*
Kiedy co stosowa�?

* Wektor jest cz�sto wystarczaj�cym rozwi�zaniem. Posiada on najprostsz� struktur� wewn�trzna i zapewnia dost�p bezpo�redni. Dost�p do danych jest zatem wygodny, elastyczny i szybki. Pami�ta� jednak nale�y, �e wektory uniewa�niaj� wszystkie swoje iteratory, wska�niki i referencje
przy ka�dym przekroczeniu pojemno�ci wektora oraz cz�� iterator�w, wska�nik�w i referencji przy operacjach wstawiania lub usuwania.

* Kolejka deque (o dw�ch ko�cach) przydaje si�, gdy cz�sto wykonujesz operacje na ko�cach zbioru i gdy istotna jest redukcja wykorzystywanej pami�ci wewn�trznej przy usuwaniu element�w. Kolejka mo�e teoretycznie pomie�ci� wi�cej element�w ni� taki wektor. Wektor bowiem to jeden blok w pami�ci, a kolejka mo�e mie� ich wi�cej. 
  Iteratory, wska�niki i referencje uniewa�niane s� przy zmianie rozmiaru kolejek.

* Gdy wykonujemy du�o przemieszcze� wewn�trz kontenera, oraz dodajemy i usuwamy elementy z wn�trza kontenera, nale�y rozwa�y� zastosowanie list. Udost�pniaj� dodatkowo funkcje przenosz�ce elementy pomi�dzy kontenerami. Niestety listy nie oferuj� dost�pu swobodnego � pojawia si� wi�c spadek wydajno�ci przy dost�pie do element�w wewn�trz listy, je�li znajdujemy si� na jej pocz�tku (musimy przsuwa� si� po jej elementach). Listy - tak jak wszystkie kontenery oparte na w�z�ach - nie uniewa�niaj� iterator�w odnosz�cych si� do ich element�w, kiedy np. dokonujemy operacji usuwania czy przesuwania. 
	Gdy potrzebny jest kontener sprawdzaj�cy czy operacja (np. wstawiania) ko�czy si� powodzeniem lub nie powoduje �adnego skutku, nale�y u�y�wa� listy, kontenera asocjacyjnego albo nieuporz�dkowanego.

* Je�li wymagane jest cz�ste wyszukiwanie element�w stosuj nieuporz�dkowany zbi�r/wielozbi�r mieszaj�cy elementy. Kontenery nieuporz�dkowane powinny by� wybierane nad porz�dkuj�ce, gdy porz�dek nie jest dla nas istotny.

* Gdy organizujemy dane w modelu klucz-warto�� (para) nale�y u�y� nieuporz�dkowanej mapy/multimapy (a gdy kolejno�� element�w ma znaczenie, sortuj�cej mapy/multimapy).

* Gdy chcesz skorzysta� z mechaniki tablicy asocjacyjnej, bierz si� za nieuporz�dkowan� map� (a w przypadku oczekiwania na porz�dek - map� sortuj�c�)

* Tzw. s�owniki uzyskujemy korzystaj�c z nieuporz�dkowanej multimapy i mapy gdy oczekujemy sortowania.
UWAGA!
Spotka�em si� z tak� oto opini� wyra�on� w podr�czniku do C++11:
"W praktyce trudno jest cz�sto przewidzie�, kt�ry typ kontenerowy b�dzie
najlepszy. Wielk� zalet� biblioteki STL jest mo�liwo�� wypr�bowania r�nych
wersji bez wi�kszego trudu. G��wna praca � implementacja r�nych struktur
danych i algorytm�w � zosta�a ju� wykonana. My musimy jedynie powi�za� je
w spos�b dla nas najkorzystniejszy".

Przegl�da�em r�ne testy i przyk�adowo ten sam program w pewnych sytuacjach robi�cy to samo, ale korzystaj�cy z r�nych kontener�w, zmienia� znacz�co swoj� wydajno�� +-10-40% A przecie� to by�o tylko kilka test�w. Pokazuje to jednak, �e dob�r kontenera MA ZNACZENIE! (szczeg�lnie gdy w kontenerze przechowujemy du�o du�ych obiekt�w)
*/