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
Biblioteka <random> gwarantuje dobry mechanizm losowo�ci i rozk�adu.
We wcze�niejszym kursie stosowali�my funkcj� rand() i dzielenie z reszt�, co nie jest z�e
gdy chodzi tylko o jakie� przyk�adowe losowe dane, ale takie podej�cie stwarza pewne problemy,
o kt�rych te� m�wi�em. Nie poda�em jednak tego, jak to rozwi�za�. <random> rozwi�zuje wiele
problem�w zwi�zanych z losowaniem ;)
<random> jest bardzo rozbudowana i dla matematyk�w mo�e by� b. potrzebna. Tutaj skupiam si� tylko na 
kilku bardzo podstawowych aspektach.
*/
void _026() {				
	// zarodek losowo�ci, ziarno losowo�ci
	unsigned seed = time(0); 
	// mechanizm losowo�ci
	default_random_engine rng(seed); // taka jakby maszyna losuj�ca
	
	// dystrybucja, mo�na to sobie tak wyobrazi�, jako taki podajnik tego, co maszyna losuj�ca wygeneruje. Tu mamy dystrybucj� liczb ca�kowitych.
	uniform_int_distribution<int> d(1, 6); // od <1;6> w��cznie (numeric_limits<int>::max())

	// losowanie liczb ca�kowitych z zakresu A;B (w��cznie)
	vector<int> throwDice; // kolejne rzuty kostk�
	
	for (int i = 1; i < 200; i++) { // 200 rzut�w kostk�
		throwDice.push_back(d(rng)); // d(rng) - d dostarcza liczb korzystaj�c z rng (maszyny los.)
	}
	printSTL(throwDice, ",", false);
	sort(throwDice.begin(), throwDice.end());
	printSTL(throwDice,",",false);
	for (auto nr : { 1,2,3,4,5,6 }) {
		cout << nr << ":=" << count(throwDice.begin(), throwDice.end(), nr) << endl;
	}
	
	// losowanie liczby zmiennoprzecinkowej od A do B (w��cznie z A, bez B)
	vector<double> temperatures;
	uniform_real_distribution<double> dd(0, 100);
	for (int i = 1; i < 30; i++) {
		temperatures.push_back(dd(rng));
	}
	printSTL(temperatures, ",", false);
		
	// wykorzystanie mechanizmu rng do "tasowania", np. kontenera 
	shuffle(throwDice.begin(), throwDice.end(), rng);
	printSTL(throwDice, ",", false);
	// uwaga! je�eli u�yjesz dwukrotnie tymczasowego obiektu mechanizmu losowo�ci:
	// shuffle(throwDice.begin(), throwDice.end(), default_random_engine());  np. 1,2,3 -> 3,1,2 to potem ...
	// shuffle(throwDice.begin(), throwDice.end(), default_random_engine());  ...  3,1,2 -> 2,3,1 
	// to ... potasuj� si� "w ten sam spos�b". Przyk�adowo, jak pierwsza liczba wskoczy�a na drug� przy pierwszym tasowaniu, to przy drugim znowu pierwsza wskoczy na drug� itd.
	// zatem u�yj obiektu, ale nietymczasowego (czyli tak jak ja to zrobi�em wy�ej, poprzez rng)

	// powy�szy mechanizm jest LEPSZY ni� to, co do tej pory pokazywa�em, czyli
	// random() % A; // mechanizm random() modulo liczba
	// w jednym z odcink�w t�umaczy�em problemy takiego losowania (problem rozk�adu).
	// A teraz pokaza�em, jak tych problem�w unikn��. 
	
	// C++ dostarcza wiele rozk�ad�w. Pokaza�em 2. Dla zaawansowanych i zainteresowanych pokazuj�:
	/*
	Kategoria Nazwa Typ danych
Rozk�ady r�wnomierne 
	uniform_int_distribution	 Ca�kowitoliczbowy
	uniform_real_distribution	Zmiennoprzecinkowy
Rozk�adyBernoulliego
	bernoulli_distribution	bool
	binomial_distribution	Ca�kowitoliczbowy
	geometric_distribution Ca�kowitoliczbowy
	negative_binomial_distribution Ca�kowitoliczbowy
Rozk�ady Poissona (Zmiennoprzecinkowe)
	poisson_distribution (Ca�kowitoliczbowy)
	exponential_distribution
	gamma_distribution
	weibull_distribution
	extreme_value_distribution
Rozk�ady normalne (Zmiennoprzecinkowe)
	normal_distribution
	lognormal_distribution
	chi_squared_distribution
	cauchy_distribution
	fisher_f_distribution
	student_t_distribution
Rozk�ady pr�bkuj�ce
	discrete_distribution	 Ca�kowitoliczbowy
	piecewise_constant_distribution	Zmiennoprzecinkowy
	piecewise_linear_distribution	Zmiennoprzecinkowy
*/

}
