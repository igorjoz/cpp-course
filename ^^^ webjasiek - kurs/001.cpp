#include <iostream>
#include <map>
#include <array>

using namespace std;
// C++17
pair<int, int> function1(int x, int y) {
	return make_pair<int, int>(x*2, y*4);
}
class C1 {
public:
	string w = "s�owo";
	int a = 55;
	double b = 999.9;
	C1() {
		cout << this << " +C1=" << a << " " << b<< " " << w <<endl;
	}	
	C1(const string&& setw,const int&& seta, const double&& setb ) {
		w = setw;
		a = seta;
		b = setb;
		cout << this << " +C1=" << a << " " << b << " " << w << endl;
	}
	~C1() {
		cout << this << " -C1=" << a << " " << b << " " << w << endl;
	}
	void show() {
		cout << this << " Info:" << w << ", " << a << ", " << b << endl;
	}
};

// nie przeci��am celowo
void f(C1 o) { cout << "-f- " << &o << " "; 
	o.a = 100; 
	o.show(); 
}
void f1(C1& o) { cout << "-f1- " << &o << " "; 
	o.show(); 
}

// ROZPAKOWANIE par, krotek i struktur/klas, tablic 
void _001() {
	
	array<int, 3> ar{1};
	auto [arr1, arr2, arr3] = ar;
	cout << arr1 << arr2 << arr3 << endl;

	auto&& [v1, v2] = function1(5, 10); // podobnie� mog� zrobi� dla dowolnego tuple (krotki), lub tablicy
	cout << v1 << " " << v2 << endl;	

	C1 obiekt_c1(":D",10,-10.5);	
	auto& [v3, v4, v5] = obiekt_c1;	
	cout << v3 << " " << v4 <<" "<< v5 << endl; // v3, v4 i v5 s� i do tego maj� odpowiedni typ zgodny z sk�adowymi C1 (kolejno�� deklaracji w klasie)
	v3 = "zmiana!";
	cout << &obiekt_c1 << " " << obiekt_c1.w << endl;

	// mapa, nie jest kontenerem sekwencyjnym, wkr�tce wi�cej o niej. Teraz wyja�niam, �e w mapie wyst�puj� pary KLUCZ->WARTO��.
	// tu za klucz robi napis (string) a za warto�� obiekt C1
	map<string, C1> elements1 {
		{"raz",C1("A",1,2.5)},
		{"dwa",C1("B",2,-2.1)}
	};
	cout << &elements1["raz"] << endl;
	cout << &elements1["dwa"] << endl;

	for (auto& [key, value] : elements1) {
		cout << "[" << key << "] "; 
		value.show();		
	}
	
	f(obiekt_c1);
	f1(obiekt_c1);	
}


