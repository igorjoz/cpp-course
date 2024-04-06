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
UWAGA! Do tego odcinka przyda Ci si� przypomnie� rzeczy, kt�re ju� om�wili�my, szczeg�lnie: 
stack, iteratory, lambdy, map.

ONP/RPN Odwrotna Notacja Polska/Reverse Polish Notation
W ONP nie korzystamy z nawias�w a dzia�ania zapisujemy w innej postaci.
Zamiast a + b Piszemy a b +  
(najpierw s� operandy lewy i prawy, a na koniec operator)
np.
Zamiast  (100 + 5) * 2  Piszemy 100 5 + 2 *
Zamiast 1 * (2 + 3) - 4  Piszemy  1 2 3 + * 4 -


Specyfikacja:
WEJ�CIE:
X - wyra�enie ONP w postaci napisu (string). [ograniczamy si� do operacji +,-,*,/
WYJ�CIE:
W - Warto�� wyra�enia X po obliczeniu. (Wykonaj dzia�ania (obliczaj wynik) na wyra�eniach ONP)

(wykorzystaj stos w celu wykonania operacji ale jak nie chcesz to kombinuj)

Algorytm: gdy pobrana warto�� to operand (liczba) dodaj j� na stos.
Je�eli to operacja (np. +) pobierz dwa operandy ze stosu, wykonaj dzia�anie, zwr�� wynik na stos. Uwaga, pobrane dwa operandy ze stosu maj� kolejno�� prawy,lewy czyli operacj� trzeba wykona�
odwrotnie : lewy operator prawy np. jak pobior� ze stosu 5 a potem 10 to wykonuj� 
dzia�eni: 10 operator 5.
Gdy sko�cz� si� elementy wyra�enia wynik ca�ego wyra�enia znajduje si� na stosie :)
*/







template <typename ITERATOR>
double calcExprRPN(ITERATOR iter, ITERATOR end)
{
	stack<double> operands; // operandy (liczby po prostu ;))
	
	// obiekt funkcyjny: operacja zdj�cia ze stosu i zwr�cenie elementu
	// uwaga: wci�gam do lambdy zmienn� stack<double> operands jako referencj�.
	auto pop_operands([&operands](){ 
		auto top (operands.top());
		operands.pop();
		return top;
	}); // wywo�anie pop_operands() zwr�ci wierzcho�kowy element stosu operands i usunie go.


	// mapa z par� OPERACJA -> LAMBDA, gdzie double(*)(double, double) to typ obiektu funkcyjnego, kt�ry tutaj jest na potrzebny a �ci�le wska�nik do dowolnej funkcji, kt�ra przyjmie jako argumenty dwa typy double i zwr�ci double.
	map<string, double(*)(double, double)> operators{
		{"+", [](double a, double b) {return a + b; }},
		{"-", [](double a, double b) {return a - b; }},
		{"*", [](double a, double b) {return a * b; }},
		{"/", [](double a, double b) {return a / b; }}
	};

	// iter - iterator na pierwszy element, zak�adam
	while (iter != end) { // zak�adam na razie, �e wprowadzono prawid�owe wyra�enie ONP/RPN
		stringstream ss{ *iter }; // ss jest strumieniem napisowym utworzonym na podstawie tego, na co wskazuje iter(ator). iter si� nie zmienia, ss jest jakby "kopi�" obok
		// teraz "przeczytam" ze strumienia ss to, co tam jest
		if (double value; ss >> value) { // je�eli odczyt do double (value jest typu double) si� powiedzie, to zostanie ta liczba wprowadzona na stos.
			operands.push(value); 
		}
		else { // a jak si� nie powiedzie, to znaczy, �e mia�em operator, a nie operand!		
			// na stos wynik operacji - g�owa paruje ;)
			auto right = pop_operands();
			auto left = pop_operands();
			operands.push(operators.at(*iter)(left,right)); 
			// pytanie, dlaczego nie zapisa� tak?
			// operands.push(operators.at(*iter)(pop_operands(),pop_operands())); 
			// bo standard nie okre�la, kt�ra warto�� zostanie obliczona jako pierwsza :(
			// PATRZ: https://en.cppreference.com/w/cpp/language/eval_order
		}
		iter++;
	}
	return operands.top(); //po zako�czeniu p�tli na stosie zostanie wynik, wi�c go zwracam
}
void _001cw() {
	string expr = "1 2 3 - * 4 +";  // 1*(2-3)+4 = 3
	stringstream s1{ expr };
	cout << calcExprRPN(istream_iterator<string>{s1}, {}) << endl;


	vector<string> v{ "1", "2", "3", "-", "*", "4", "+", "3", "/" }; // (1*(2-3)+4)/3 =1
	cout << calcExprRPN(v.begin(), v.end()) << endl;	
	
	// mo�emy te� pobra� to z cin... Uwaga! CTRL+Z ko�czy wprowadzanie.
	cout << calcExprRPN(istream_iterator<string>{cin}, {}) << endl;	
	
}
//  W nast�pnym odcinku dodamy operacje sprawdzaj�ce b��dny strumie� danych i spr�bujemy obs�u�y� wyj�tki z tym zwi�zane


