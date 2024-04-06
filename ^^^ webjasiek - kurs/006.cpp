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

/*  
W³¹czenie bibliotek w postaci samych nag³ówków zawieraj¹cych osadzone zmienne (006.h).
Od C++17 oprócz osadzania funkcji mo¿na deklarowaæ zmienne jako zmienne osadzone.
---
/inline sprawia, ¿e je¿eli linker znajdzie wiele symboli o tej samej sygnaturze, wybierze pierwszy/
*/
#include "006.h"

void _006() {
	cout << global_object.txt << endl; // global_object dostarcza mi sama biblioteka
	Temp t;
	cout << t.txt << endl;
}





