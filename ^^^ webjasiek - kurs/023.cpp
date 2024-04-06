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
	- VISUAL STUDIO COMMUNITY 2019 (modu� Programowanie Aplikacji Klasycznych)
	Po za�o�eniu projektu we w�a�ciwo�ciach projektu na zak�adce "Explorator Rozwi�za�" szukamy w "Opcjach og�lnych" standard j�zyka i ustawiamy go na C++17
	Kompilacja i uruchomienie: CTRL+F5
	Kompilacja CTRL+SHIFT+B
	Debugowanie to samo F5, Wkroczenie w debugowanie linia po linii z wkraczaniem do funkcji to F11 (F10 nie wkracza do funkcji)
	Stopuj debugowanie CTRL+SHIFT+F5		
*/


// mo�na zwraca� typ auto i precyzowa� go w pewien og�lny spos�b (taka wy�sza abstrakcja, zwr�� "co�" co ma typ jak "co�")
template<typename T1, typename T2>
auto suma(const T1& a, const T2& b) -> decltype(a + b) { // typ b�dzie zwracany taki, jaki jest typ wyniku operacji sumy ... (patrz wywo�anie)
	return a + b;
} 
// do szablon�w jeszcze wr�cimy, teraz chodzi tylko o s�owa auto, decltype



void _023() {				
		
		/* 
		decltype() - podbiera typ ze swojego argumentu
		typeid().name() podpowie jakiego typu jest zmienna wg naszego kompilatora 
		Przydadz� si� nam do okre�lania typ�w (czyli jak widzi co� kompilator) oraz pozwalaj� wej�� w meta-programowanie, czyli takie bardziej
		abstrakcyjne, bardziej og�lne programowanie.
		*/
		int var1 = 0;
		decltype(var1)  var2=105; /// var2 jest tego typu, co var1  (i od razu inicjuj� warto�ci� 105)
		cout << var2 << " " << typeid(var2).name() << endl;
		

		/* wprowadzono nullptr zamiast 0/null. nullptr ma sw�j typ std::nullptr_t;	 (bo w C++ wszystko musi mie� typ!) */
		double* var3 = nullptr;	
		cout << typeid(nullptr).name() << endl;
		
		/* pojawi�o si� s�owo auto stosowane gdy chcemy ustali� typ z kontekstu */		
		auto b = 1; // auto - domy�la si� typu z kontekstu
		cout << typeid(b).name() << endl;
		auto c = 1.5;
		cout << typeid(c).name() << endl;	
		// funkcje mog� te� mie� typ auto jako typ zwracany :)
		cout << suma(5, 3.6) << " " << typeid(suma(5, 3.6)).name() << endl; // sprawdzam jaki typ zwraca ta suma... DOUBLE !
		cout << suma(5, 5) << " " << typeid(suma(5, 5)).name() << endl; // sprawdzam jaki typ zwraca ta suma... INT !
		cout << suma(5.f, 5.f) << " " << typeid(suma(5.f, 5.f)).name() << endl; // 
		string txt3 = "koto"; string txt4 = "pies";		
		cout << suma(txt3, txt4) << " " << typeid(suma(txt3, txt4)).name() << endl; // sprawdzam jaki typ zwraca ta suma... basic_string!
		cout << typeid(string).name() << endl;


		// a tu auto pos�u�y w p�tli for
		vector<int> values1{ 1,2,3,4,5 }; // zbi�r-wektor z elementami typu int: 1,2,3,4,5 [taka wybajerzona tablica, o niej te� b�dzie]
		for (auto e : values1) cout << e << " " << typeid(e).name() << " "; // e kopia
		cout << endl; 
		
		for (auto& e : values1) cout << e++ << " ";  // e referencja, mo�na czyta� i modyfikowa�
		cout << endl; 
		
		for (const auto& e : values1) cout << e << " "; // e referencja, mo�na czyta� i nie mo�na modyfikowa�
		cout << endl; 
		
		for (auto i : { 1,2,3 }) cout << i << " ";  // dzia�a, i staje si� kolejnymi elementami listy inicjalizacyjnej
		cout << endl;



		/* Litera�y napisowe z R*/
		auto txt = "abc";
		cout << endl << txt << typeid(txt).name() << endl;
		auto txt1 = R"(Teraz pisz�
co mi si� tylko			spodoba. Ka�dy znak, tabulator
czy Enter s� uwzgl�dnione i nie musz� stosowa� znak�w specjalnych.)";		
		auto txt2 = R"ogranicznik(
Stosowanie ogranicznika jest koniecznie, gdy chc� wy�wietli� faktycznie kombinacj� nawias i cudzys��w )"
)ogranicznik";
		cout << endl << txt1 << " " << typeid(txt1).name() << endl;
		cout << endl << txt2 << " " << typeid(txt2).name() << endl;
	
		
}
