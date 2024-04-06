#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <map>
#include <ctime>
#include <typeinfo>
#include <type_traits>
#include "numbers.h"
// C++17
using namespace std;


/*  constexpr, constexpr-if
	constexpr : s³owo kluczowe: wymusza obliczenie wyra¿enia w czasie kompilacji. 
	constexpr-if : w instrukcji warunkowej if mo¿na dodaæ constexpr, co powoduje
	sprawdzenie warunku na etapie kompilacji. Kod uruchomieniowy programu nie bêdzie zawiera³ wszystkich poleceñ ga³êzi constexpr-if, a tylko tê odpowiedni¹.
	Wyra¿enie constexpr-if upraszcza podejmowanie decyzji podczas kompilacji.
*/
template <typename T>
class A {
	T value;
public:
	A(T&& v) : value{ v } {}			
	void show() {
		if constexpr (is_same_v<T,std::string> || is_convertible_v<T, double>) {
			std::cout << value << std::endl;
		}				
		else if constexpr (is_same_v<T, vector<std::string>> || 
			is_same_v<T, vector<double>> || 
			is_same_v<T, vector<float>> || 
			is_same_v<T, vector<int>>) 
		{ // T to wektor z liczbami			
			for (auto& element : value) {
				std::cout << element << " ";
			}
			std::cout << std::endl;
		}
		else {
			std::cout << "Brak mo¿liwoœci wyœwietlenia. Brak implementacji w show()." << std::endl;
		}
		std::cout << std::endl;
	}
	template <typename X>
	void multiple(X&& m) {		
		if constexpr (std::is_convertible_v<X, double>&& std::is_convertible_v<T, double>) { // liczby ?
			value *= m;
		}
		else if constexpr (is_same_v<T, string>&& is_convertible_v<X, int>) {
			string temp = value;
			for (int i = 1; i <= abs((int)m)-1; i++) value += " " + temp;
		}
		else if constexpr (std::is_convertible_v<X, double> && 
			(std::is_same_v<T, vector<double>> || std::is_same_v<T, vector<float>>) ) { // vektor<double> * liczba ? (float * liczba)
			for (auto& element : value) {
				element *= m;
			}
		}		
		else {
			std::cout << "Nie nast¹pi³o mno¿enie. Brak implementacji w multiple()." << std::endl;
		}
		
	}	
};

constexpr size_t wow() { return 10; } // dzia³a jakby wow() by³o sta³¹.
void _005() {
	constexpr int x = 10; // zmienna x bêdzie traktowana jak sta³a
	array<int, x> arr1{}; // wiemy, ¿e array potrzebuje sta³ej gdy okreœlamy typ, x jednak jest sta³¹ obliczan¹ w czasie kompilacji.
	cout << arr1.size() << endl;
	array<int, wow()> arr2{}; // funkcja mo¿e byæ interpretowana jak sta³a 
	cout << arr2.size() << endl;
	printSTL(arr2, ", ", true);

	// je¿eli u¿yjemy konstrukcji
	if constexpr (x > 0) { // constrexpr u¿yte w if-else sprawia, ¿e warunek jest sprawdzony podczas kompilacji. Niby skutek taki sam, ale w kodzie jest umieszczona jedna ga³¹Ÿ a nie wszystkie.
		cout << "hejka!\n";
	}
	else {
		cout << " --- \n";
	}	
	
	A o1(string("rabarbar"));
	o1.show();
	o1.multiple(5);
	o1.show();

	A o2(100);
	o2.multiple(1.5);
	o2.show();

	A o3(vector<double>{1.0, 2.0, 3.0, 4.0});
	o3.show();
	o3.multiple(2);
	o3.show();


	A o4(vector<string>{"Ala", "ma", "kota"});
	o4.show();

	A o5(vector<float>{1,2,3});
	o5.show();
	o5.multiple(10);
	o5.show();

	A o6(vector<unsigned>{1});
	o6.show();

}


