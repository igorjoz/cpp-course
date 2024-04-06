#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>

#include <typeinfo>
#include <string>
#include <ctime>
#include "numbers.h"

#include <stack>
#include <sstream>
#include <iterator>

// C++17

using namespace std;
/*
UWAGA! Do tego odcinka przyda Ci siê przypomnieæ rzeczy, które ju¿ omówiliœmy, szczególnie: 
stack, iteratory, lambdy, map.

ONP/RPN Odwrotna Notacja Polska/Reverse Polish Notation
W ONP nie korzystamy z nawiasów a dzia³ania zapisujemy w innej postaci.
Zamiast a + b Piszemy a b +  
(najpierw s¹ operandy lewy i prawy, a na koniec operator)
np.
Zamiast  (100 + 5) * 2  Piszemy 100 5 + 2 *
Zamiast 1 * (2 + 3) - 4  Piszemy  1 2 3 + * 4 -


Specyfikacja:
WEJŒCIE:
X - wyra¿enie ONP w postaci napisu (string). [ograniczamy siê do operacji +,-,*,/
WYJŒCIE:
W - Wartoœæ wyra¿enia X po obliczeniu. (Wykonaj dzia³ania (obliczaj wynik) na wyra¿eniach ONP)

(wykorzystaj stos w celu wykonania operacji ale jak nie chcesz to kombinuj)

Algorytm: gdy pobrana wartoœæ to operand (liczba) dodaj j¹ na stos.
Je¿eli to operacja (np. +) pobierz dwa operandy ze stosu, wykonaj dzia³anie, zwróæ wynik na stos. Uwaga, pobrane dwa operandy ze stosu maj¹ kolejnoœæ prawy,lewy czyli operacjê trzeba wykonaæ
odwrotnie : lewy operator prawy np. jak pobiorê ze stosu 5 a potem 10 to wykonujê 
dzia³eni: 10 operator 5.
Gdy skoñcz¹ siê elementy wyra¿enia wynik ca³ego wyra¿enia znajduje siê na stosie :)
*/

/// Uwaga! We wczeœniejszym kursie z C++ jest taki "dodatek 5" i tam by³o o wyj¹tkach :)

template <typename ITERATOR>
double calcExprRPN(ITERATOR iter, ITERATOR end)
{
	stack<double> operands; // operandy (liczby po prostu ;))
	
	// obiekt funkcyjny: operacja zdjêcia ze stosu i zwrócenie elementu
	// uwaga: wci¹gam do lambdy zmienn¹ stack<double> operands jako referencjê.
	auto pop_operands([&operands](){ 
		if (operands.empty()) throw string("Nie mo¿na pobraæ operandów. Popraw wyra¿enie.");
		auto top (operands.top());		
		operands.pop();				
		return top;
	}); // wywo³anie pop_operands() zwróci wierzcho³kowy element stosu operands i usunie go.


	// mapa z par¹ OPERACJA -> LAMBDA, gdzie double(*)(double, double) to typ obiektu funkcyjnego, który tutaj jest na potrzebny a œciœle wskaŸnik do dowolnej funkcji, która przyjmie jako argumenty dwa typy double i zwróci double.
	map<string, double(*)(double, double)> operators{
		{"+", [](double a, double b) {return a + b; }},
		{"-", [](double a, double b) {return a - b; }},
		{"*", [](double a, double b) {return a * b; }},
		{"/", [](double a, double b) {return a / b; }}
	};

	// iter - iterator na pierwszy element, zak³adam
	while (iter != end) { // zak³adam na razie, ¿e wprowadzono prawid³owe wyra¿enie ONP/RPN
		stringstream ss{ *iter }; // ss jest strumieniem napisowym utworzonym na podstawie tego, na co wskazuje iter(ator). iter siê nie zmienia, ss jest jakby "kopi¹" obok
		// teraz "przeczytam" ze strumienia ss to, co tam jest
		if (double value; ss >> value) { // je¿eli odczyt do double (value jest typu double) siê powiedzie, to zostanie ta liczba wprowadzona na stos.
			operands.push(value); 
		}
		else { // a jak siê nie powiedzie, to znaczy, ¿e mia³em operator, a nie operand!		
			// na stos wynik operacji - g³owa paruje ;)			
			try {
				operators.at(*iter);
			}
			catch (...) {
				throw string("Nie istnieje operacja <" + *iter + ">.");
			}
			auto right = pop_operands();
			auto left = pop_operands();
			try {
				operands.push(operators.at(*iter)(left, right));
			}
			catch (...) {
				throw string("Nieudane dzia³anie <" + *iter + ">. Popraw wyra¿enie.");
			}

			// pytanie, dlaczego nie zapisaæ tak?
			// operands.push(operators.at(*iter)(pop_operands(),pop_operands())); 
			// bo standard nie okreœla, która wartoœæ zostanie obliczona jako pierwsza :(
			// PATRZ: https://en.cppreference.com/w/cpp/language/eval_order
		}
		iter++;
	}
	if (operands.size() > 1) throw string("Za du¿o operandów, za ma³o operacji.");
	return operands.top(); //po zakoñczeniu pêtli na stosie zostanie wynik, wiêc go zwracam
}
void _001cw() {
	// string expr = "1 2 3 - * 4 +";  // 1*(2-3)+4 = 3 OK !
	
	//Ok, bo 12abc jest interpretowane do double z pominiêciem 'abc' i 'n'
	// Kiedy jest ta instrukcja :
	// if (double value; ss >> value) - to w³aœnie wtedy 12abc i tak zostanie konwertowane na 12
	//string expr = "12abc 1n +";  
	
	//string expr = "1 2 3 - * 4 + +";  // B£¥D
	//string expr = "1 +";  // B£¥D	
	//string expr = "1 2 3 - * 4 + 1 2 a";  // B£¥D
	//string expr = "1 2 3 - * 4 ^";  // B£¥D	
	//string expr = "1 2 3 +";  // B£¥D	
	
	string expr = "";  // B£¥D	
	
	stringstream s1{ expr };
	try {
		cout << calcExprRPN(istream_iterator<string>{s1}, {}) << endl;		
	}
	catch (string e) {
		cout << e;
	}
	//vector<string> v{ "1", "2", "3", "-", "*", "4", "+", "3", "/" }; // (1*(2-3)+4)/3 =1
	//cout << calcExprRPN(v.begin(), v.end()) << endl;
	// mo¿emy te¿ pobraæ to z cin... Uwaga! CTRL+Z koñczy wprowadzanie.
	//cout << calcExprRPN(istream_iterator<string>{cin}, {}) << endl;
	
}
