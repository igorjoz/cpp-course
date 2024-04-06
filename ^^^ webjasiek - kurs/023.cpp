#include <iostream>
#include <array>
#include <vector>
#include <typeinfo>
#include <string>
#include <ctime>
#include "numbers.h"

// C++17
using namespace std;
/*
	- VISUAL STUDIO COMMUNITY 2019 (modu³ Programowanie Aplikacji Klasycznych)
	Po za³o¿eniu projektu we w³aœciwoœciach projektu na zak³adce "Explorator Rozwi¹zañ" szukamy w "Opcjach ogólnych" standard jêzyka i ustawiamy go na C++17
	Kompilacja i uruchomienie: CTRL+F5
	Kompilacja CTRL+SHIFT+B
	Debugowanie to samo F5, Wkroczenie w debugowanie linia po linii z wkraczaniem do funkcji to F11 (F10 nie wkracza do funkcji)
	Stopuj debugowanie CTRL+SHIFT+F5		
*/


// mo¿na zwracaæ typ auto i precyzowaæ go w pewien ogólny sposób (taka wy¿sza abstrakcja, zwróæ "coœ" co ma typ jak "coœ")
template<typename T1, typename T2>
auto suma(const T1& a, const T2& b) -> decltype(a + b) { // typ bêdzie zwracany taki, jaki jest typ wyniku operacji sumy ... (patrz wywo³anie)
	return a + b;
} 
// do szablonów jeszcze wrócimy, teraz chodzi tylko o s³owa auto, decltype



void _023() {				
		
		/* 
		decltype() - podbiera typ ze swojego argumentu
		typeid().name() podpowie jakiego typu jest zmienna wg naszego kompilatora 
		Przydadz¹ siê nam do okreœlania typów (czyli jak widzi coœ kompilator) oraz pozwalaj¹ wejœæ w meta-programowanie, czyli takie bardziej
		abstrakcyjne, bardziej ogólne programowanie.
		*/
		int var1 = 0;
		decltype(var1)  var2=105; /// var2 jest tego typu, co var1  (i od razu inicjujê wartoœci¹ 105)
		cout << var2 << " " << typeid(var2).name() << endl;
		

		/* wprowadzono nullptr zamiast 0/null. nullptr ma swój typ std::nullptr_t;	 (bo w C++ wszystko musi mieæ typ!) */
		double* var3 = nullptr;	
		cout << typeid(nullptr).name() << endl;
		
		/* pojawi³o siê s³owo auto stosowane gdy chcemy ustaliæ typ z kontekstu */		
		auto b = 1; // auto - domyœla siê typu z kontekstu
		cout << typeid(b).name() << endl;
		auto c = 1.5;
		cout << typeid(c).name() << endl;	
		// funkcje mog¹ te¿ mieæ typ auto jako typ zwracany :)
		cout << suma(5, 3.6) << " " << typeid(suma(5, 3.6)).name() << endl; // sprawdzam jaki typ zwraca ta suma... DOUBLE !
		cout << suma(5, 5) << " " << typeid(suma(5, 5)).name() << endl; // sprawdzam jaki typ zwraca ta suma... INT !
		cout << suma(5.f, 5.f) << " " << typeid(suma(5.f, 5.f)).name() << endl; // 
		string txt3 = "koto"; string txt4 = "pies";		
		cout << suma(txt3, txt4) << " " << typeid(suma(txt3, txt4)).name() << endl; // sprawdzam jaki typ zwraca ta suma... basic_string!
		cout << typeid(string).name() << endl;


		// a tu auto pos³u¿y w pêtli for
		vector<int> values1{ 1,2,3,4,5 }; // zbiór-wektor z elementami typu int: 1,2,3,4,5 [taka wybajerzona tablica, o niej te¿ bêdzie]
		for (auto e : values1) cout << e << " " << typeid(e).name() << " "; // e kopia
		cout << endl; 
		
		for (auto& e : values1) cout << e++ << " ";  // e referencja, mo¿na czytaæ i modyfikowaæ
		cout << endl; 
		
		for (const auto& e : values1) cout << e << " "; // e referencja, mo¿na czytaæ i nie mo¿na modyfikowaæ
		cout << endl; 
		
		for (auto i : { 1,2,3 }) cout << i << " ";  // dzia³a, i staje siê kolejnymi elementami listy inicjalizacyjnej
		cout << endl;



		/* Litera³y napisowe z R*/
		auto txt = "abc";
		cout << endl << txt << typeid(txt).name() << endl;
		auto txt1 = R"(Teraz piszê
co mi siê tylko			spodoba. Ka¿dy znak, tabulator
czy Enter s¹ uwzglêdnione i nie muszê stosowaæ znaków specjalnych.)";		
		auto txt2 = R"ogranicznik(
Stosowanie ogranicznika jest koniecznie, gdy chcê wyœwietliæ faktycznie kombinacjê nawias i cudzys³ów )"
)ogranicznik";
		cout << endl << txt1 << " " << typeid(txt1).name() << endl;
		cout << endl << txt2 << " " << typeid(txt2).name() << endl;
	
		
}
