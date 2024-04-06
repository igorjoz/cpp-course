#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <typeinfo>
#include <string>
#include <ctime>
#include <random>
#include <algorithm>
#include "numbers.h"

// C++17

using namespace std;
/*
Biblioteka <random> gwarantuje dobry mechanizm losowoœci i rozk³adu.
We wczeœniejszym kursie stosowaliœmy funkcjê rand() i dzielenie z reszt¹, co nie jest z³e
gdy chodzi tylko o jakieœ przyk³adowe losowe dane, ale takie podejœcie stwarza pewne problemy,
o których te¿ mówi³em. Nie poda³em jednak tego, jak to rozwi¹zaæ. <random> rozwi¹zuje wiele
problemów zwi¹zanych z losowaniem ;)
<random> jest bardzo rozbudowana i dla matematyków mo¿e byæ b. potrzebna. Tutaj skupiam siê tylko na 
kilku bardzo podstawowych aspektach.
*/
void _026() {				
	// zarodek losowoœci, ziarno losowoœci
	unsigned seed = time(0); 
	// mechanizm losowoœci
	default_random_engine rng(seed); // taka jakby maszyna losuj¹ca
	
	// dystrybucja, mo¿na to sobie tak wyobraziæ, jako taki podajnik tego, co maszyna losuj¹ca wygeneruje. Tu mamy dystrybucjê liczb ca³kowitych.
	uniform_int_distribution<int> d(1, 6); // od <1;6> w³¹cznie (numeric_limits<int>::max())

	// losowanie liczb ca³kowitych z zakresu A;B (w³¹cznie)
	vector<int> throwDice; // kolejne rzuty kostk¹
	
	for (int i = 1; i < 200; i++) { // 200 rzutów kostk¹
		throwDice.push_back(d(rng)); // d(rng) - d dostarcza liczb korzystaj¹c z rng (maszyny los.)
	}
	printSTL(throwDice, ",", false);
	sort(throwDice.begin(), throwDice.end());
	printSTL(throwDice,",",false);
	for (auto nr : { 1,2,3,4,5,6 }) {
		cout << nr << ":=" << count(throwDice.begin(), throwDice.end(), nr) << endl;
	}
	
	// losowanie liczby zmiennoprzecinkowej od A do B (w³¹cznie z A, bez B)
	vector<double> temperatures;
	uniform_real_distribution<double> dd(0, 100);
	for (int i = 1; i < 30; i++) {
		temperatures.push_back(dd(rng));
	}
	printSTL(temperatures, ",", false);
		
	// wykorzystanie mechanizmu rng do "tasowania", np. kontenera 
	shuffle(throwDice.begin(), throwDice.end(), rng);
	printSTL(throwDice, ",", false);
	// uwaga! je¿eli u¿yjesz dwukrotnie tymczasowego obiektu mechanizmu losowoœci:
	// shuffle(throwDice.begin(), throwDice.end(), default_random_engine());  np. 1,2,3 -> 3,1,2 to potem ...
	// shuffle(throwDice.begin(), throwDice.end(), default_random_engine());  ...  3,1,2 -> 2,3,1 
	// to ... potasuj¹ siê "w ten sam sposób". Przyk³adowo, jak pierwsza liczba wskoczy³a na drug¹ przy pierwszym tasowaniu, to przy drugim znowu pierwsza wskoczy na drug¹ itd.
	// zatem u¿yj obiektu, ale nietymczasowego (czyli tak jak ja to zrobi³em wy¿ej, poprzez rng)

	// powy¿szy mechanizm jest LEPSZY ni¿ to, co do tej pory pokazywa³em, czyli
	// random() % A; // mechanizm random() modulo liczba
	// w jednym z odcinków t³umaczy³em problemy takiego losowania (problem rozk³adu).
	// A teraz pokaza³em, jak tych problemów unikn¹æ. 
	
	// C++ dostarcza wiele rozk³adów. Pokaza³em 2. Dla zaawansowanych i zainteresowanych pokazujê:
	/*
	Kategoria Nazwa Typ danych
Rozk³ady równomierne 
	uniform_int_distribution	 Ca³kowitoliczbowy
	uniform_real_distribution	Zmiennoprzecinkowy
Rozk³adyBernoulliego
	bernoulli_distribution	bool
	binomial_distribution	Ca³kowitoliczbowy
	geometric_distribution Ca³kowitoliczbowy
	negative_binomial_distribution Ca³kowitoliczbowy
Rozk³ady Poissona (Zmiennoprzecinkowe)
	poisson_distribution (Ca³kowitoliczbowy)
	exponential_distribution
	gamma_distribution
	weibull_distribution
	extreme_value_distribution
Rozk³ady normalne (Zmiennoprzecinkowe)
	normal_distribution
	lognormal_distribution
	chi_squared_distribution
	cauchy_distribution
	fisher_f_distribution
	student_t_distribution
Rozk³ady próbkuj¹ce
	discrete_distribution	 Ca³kowitoliczbowy
	piecewise_constant_distribution	Zmiennoprzecinkowy
	piecewise_linear_distribution	Zmiennoprzecinkowy
*/

}
