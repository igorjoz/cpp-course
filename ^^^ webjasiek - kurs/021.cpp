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

Kontenery nieporz¹dkuj¹ce implementowane s¹ jako tablice mieszaj¹ce (a nie drzewa binarne!).
Istnieje tylko operator ++ (w przód). Nie ma np. rbegin(), rend().
Operacji dostêpu do elementu w mapie nieuporz¹dkowanej jest zamortyzowany i sta³y bez wzglêdu na d³ugoœæ i pozycjê.

*/
/*
	Ma³e wyjaœnienie ogólne. Ucz¹c siê C++ niekiedy trzeba siê "cofaæ" i powtarzaæ (albo pog³êbiaæ) rozumienie pewnych elementów. Dzieje siê tak dlatego, ¿e wiele elementów jêzyka jest mocno powi¹zanych i chc¹c dog³êbnie wyt³umaczyæ jedn¹ rzecz, musielibyœmy t³umaczyæ powi¹zania, a te z kolejnymi powi¹zaniami itd. Dlatego niekiedy pewne rzeczy omawiam krótko a nawet nie omawiam, zostawiaj¹c tylko pewn¹ ogóln¹ informacjê. W innym odcinku bêdzie to pewnie wyjaœnione. Wtedy warto wróciæ do wczeœniejszego odcinka - wiedza siê uzupe³ni, a potem pog³êbi i z ka¿dym kolejnym elementem rozumienie dzia³ania ró¿nych technik bêdzie pe³niejsze. Uczenie siê (w tym uczenie C++ szczególnie) przypomina trochê fale przyp³ywu. Wchodzimy w temat trochê (¿eby zacz¹æ, ¿eby ju¿ coœ umieæ), potem siê cofamy, potem podchodzimy do tematu znowu, ale trochê g³êbiej. Ka¿da kolejna fala niby robi coœ podobnego, ale zag³êbia siê w l¹d i poziom wody siê podnosi. I o to chodzi!
	Przegl¹da³em kilka podrêczników do C++ i sporo z nich jest zorganizowane mniej wiêcej tak:
	- 1 czêœæ: ogólnie o wszystkim, ale p³ytko, bez wchodzenia w szczegó³y
	- 2 czêœæ: dok³adniej, pokazuj¹c zale¿noœci, t³umacz¹c wiêcej, ale wci¹¿ pozostawiaj¹c pytania
	- 3 czêœæ: do koñca, ca³a specyfikacja (jednak i tu nie ma wszystkiego, dlatego czêsto pe³ne rozumienie jakiejœ funkcji/biblioteki/kodu wymaga po prostu STUDIOWANIA KODU, RÓD£A itp.)
	(mówi³em o tym w jednej z lekcji)
*/

namespace hehe_space {
	const int ABC = 100;
}

struct myKey {
	string a;
	string b;
};
namespace std {
	bool operator==(const myKey& l, const myKey& r) { // operator porównania dwóch elementów myKey
		return l.a == r.a && l.b == r.b;
	}
	template <>
	class hash<myKey> { // klasa hash'uj¹ca, oblicza do jakiego kube³ka trafi element myKey
	public:
		using argument_type = myKey;
		using result_type = size_t;
		result_type operator()(const argument_type& c) const {
			size_t suma = 0;
			for (auto& znak : c.a) suma += znak;
			for (auto& znak : c.b) suma += znak;
			cout << "("<<suma<<")\n";
			return static_cast<result_type>(suma); // to nie jest za m¹dre, ale przyk³ad ok
			// elementy s¹ przypisane do tego hash'a (poka¿ê na rysunku !) HASH powinien byæ tak obliczany, aby by³o jak najmniej powtórzeñ dla elementu. static_cast to rzutowanie, omówimy w przysz³oœci
		}
	};
	// bucket_count() - iloœæ kube³ków :)
	// rehash(n) - przemieszanie i ustawienie conajmniej n kube³ków
	// reserve(n) - przemieszanie kontenera by by³o miejsce dla minimum n elementów
	// max_load_factor(0.7) - wartoœæ do 1, ustawia maksymalny wspó³czynnik obci¹¿enia 0.7,0.8 OK
	// max_load_factor() - zwraca ten maksymalny wspó³czynnik
	// load_factor() - zwraca obecny wspó³czynnik obci¹¿enia
	// Uwaga! Mo¿na siê dobraæ do tych kube³ków metodami:
	// bucket(val) - id kube³ka dla wartoœci val
	// begin(id_bucket) - zwraca iterator na element o podanym id kube³ka
	
}
void _021() {	
	// definiowanie czegoœ-tam we w³asnej przestrzeni (tak przy okazji)
	cout << hehe_space::ABC << endl; // ABC z przestrzeni hehe_space::
	// ABC; // bez hehe_space:: nie jest znane!

	/// unordered_set, unordered_multiset (nieuporz¹dkowane zbiory i multizbiory)
	unordered_set<int> uset;
	uset = { 1,2,5,6,7,7,2,1,1,4,4,1 }; // elementy bêd¹ wystêpowaæ tylko RAZ i w nieuporz¹dkowany sposób ...
	printSTL(uset,",",true); // ... oto dowód.
	uset.insert({ 1, 2, 3, 100, 1, 100 }); // 1 i 2 ju¿ by³o, 3 i 100 siê wstawi¹
	printSTL(uset, ",", true); // zwróæ uwagê, ¿e elementy nie s¹ zgodne z sekwencj¹ dodawania


	unordered_multiset<int> umset;
	umset = { 1,2,5,6,7,7,2,1,1,4,4,1 };  
	printSTL(umset, ",", true); // wszystkie s¹
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
	cout << "Elf str: " << elf["str"] << endl; // mo¿na odwo³aæ siê do klucza i u¿ywaæ jakby to by³a tablica, ale nie z indeksem ca³kowitym
	// co ciekawe, mogê "w locie" towrzyæ nowy klucz !
	elf["quickness"] = 17;
	cout << "Elf quickness: " << elf["quickness"] << "!!!" << endl;
	// elf.at("ten atrybut nie istnieje") = 1; // zg³osi B£¥D. Metoda at() daje dostêp do wartoœci poprzez klucz, ale klucz musi istnieæ.

	unordered_multimap<string, int>orc;
	orc = { {"str",20},{"int",9},{"con",18},{"luck",10},{"hp",400},{"hp",600} }; // i tak zostanie pierwsze hp
	orc.insert({ { "str",21 }, {"dex",6} });
	cout << "Orc information:\n";
	for (auto& elem : orc) {
		cout << elem.first << "==" << elem.second << endl;
	}
	///////////////// dziwne klucze wymagaj¹ obs³ugi
	unordered_map<myKey, int> umapWithMyKey = {
		{{"ab","bc"},10}, // !
		{{"c","d"},11}, // !
		{{"a","d"},12}, // !
		{{"ab","bc"},13}, // - (dubel klucza, nie przejdzie)
		{{"b","a"},14}, // ! 
		{{"a","a"},15}, // !
		{{"a","b"},16} // ! jak 14, ten sam kube³ek
	};
	for (auto [k, v] : umapWithMyKey) {
		cout << k.a << " " << k.b << "=" << v << endl;
	}

	/// a tu coœ z kube³kami:
	cout << umapWithMyKey.bucket_size(umapWithMyKey.bucket({"a","b"})) << endl; // ile elementów w kuble?
	cout << umapWithMyKey.bucket_count() << endl; // ile kube³ków dla mapy

	/// UWAGA! Je¿eli uporz¹dkowanie elementów w mapie (map) nie jest jakimœ priorytetem dla Ciebie, korzystaj raczej z unordered_map. Koszt 
	
}
//////////////////////////////////
/*
Kiedy co stosowaæ?

* Wektor jest czêsto wystarczaj¹cym rozwi¹zaniem. Posiada on najprostsz¹ strukturê wewnêtrzna i zapewnia dostêp bezpoœredni. Dostêp do danych jest zatem wygodny, elastyczny i szybki. Pamiêtaæ jednak nale¿y, ¿e wektory uniewa¿niaj¹ wszystkie swoje iteratory, wskaŸniki i referencje
przy ka¿dym przekroczeniu pojemnoœci wektora oraz czêœæ iteratorów, wskaŸników i referencji przy operacjach wstawiania lub usuwania.

* Kolejka deque (o dwóch koñcach) przydaje siê, gdy czêsto wykonujesz operacje na koñcach zbioru i gdy istotna jest redukcja wykorzystywanej pamiêci wewnêtrznej przy usuwaniu elementów. Kolejka mo¿e teoretycznie pomieœciæ wiêcej elementów ni¿ taki wektor. Wektor bowiem to jeden blok w pamiêci, a kolejka mo¿e mieæ ich wiêcej. 
  Iteratory, wskaŸniki i referencje uniewa¿niane s¹ przy zmianie rozmiaru kolejek.

* Gdy wykonujemy du¿o przemieszczeñ wewn¹trz kontenera, oraz dodajemy i usuwamy elementy z wnêtrza kontenera, nale¿y rozwa¿yæ zastosowanie list. Udostêpniaj¹ dodatkowo funkcje przenosz¹ce elementy pomiêdzy kontenerami. Niestety listy nie oferuj¹ dostêpu swobodnego — pojawia siê wiêc spadek wydajnoœci przy dostêpie do elementów wewn¹trz listy, jeœli znajdujemy siê na jej pocz¹tku (musimy przsuwaæ siê po jej elementach). Listy - tak jak wszystkie kontenery oparte na wêz³ach - nie uniewa¿niaj¹ iteratorów odnosz¹cych siê do ich elementów, kiedy np. dokonujemy operacji usuwania czy przesuwania. 
	Gdy potrzebny jest kontener sprawdzaj¹cy czy operacja (np. wstawiania) koñczy siê powodzeniem lub nie powoduje ¿adnego skutku, nale¿y u¿yæwaæ listy, kontenera asocjacyjnego albo nieuporz¹dkowanego.

* Jeœli wymagane jest czêste wyszukiwanie elementów stosuj nieuporz¹dkowany zbiór/wielozbiór mieszaj¹cy elementy. Kontenery nieuporz¹dkowane powinny byæ wybierane nad porz¹dkuj¹ce, gdy porz¹dek nie jest dla nas istotny.

* Gdy organizujemy dane w modelu klucz-wartoœæ (para) nale¿y u¿yæ nieuporz¹dkowanej mapy/multimapy (a gdy kolejnoœæ elementów ma znaczenie, sortuj¹cej mapy/multimapy).

* Gdy chcesz skorzystaæ z mechaniki tablicy asocjacyjnej, bierz siê za nieuporz¹dkowan¹ mapê (a w przypadku oczekiwania na porz¹dek - mapê sortuj¹c¹)

* Tzw. s³owniki uzyskujemy korzystaj¹c z nieuporz¹dkowanej multimapy i mapy gdy oczekujemy sortowania.
UWAGA!
Spotka³em siê z tak¹ oto opini¹ wyra¿on¹ w podrêczniku do C++11:
"W praktyce trudno jest czêsto przewidzieæ, który typ kontenerowy bêdzie
najlepszy. Wielk¹ zalet¹ biblioteki STL jest mo¿liwoœæ wypróbowania ró¿nych
wersji bez wiêkszego trudu. G³ówna praca — implementacja ró¿nych struktur
danych i algorytmów — zosta³a ju¿ wykonana. My musimy jedynie powi¹zaæ je
w sposób dla nas najkorzystniejszy".

Przegl¹da³em ró¿ne testy i przyk³adowo ten sam program w pewnych sytuacjach robi¹cy to samo, ale korzystaj¹cy z ró¿nych kontenerów, zmienia³ znacz¹co swoj¹ wydajnoœæ +-10-40% A przecie¿ to by³o tylko kilka testów. Pokazuje to jednak, ¿e dobór kontenera MA ZNACZENIE! (szczególnie gdy w kontenerze przechowujemy du¿o du¿ych obiektów)
*/