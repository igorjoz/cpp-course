#include <array>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <stack>
#include <typeinfo>
#include <string>
#include <ctime>
#include <sstream>
#include "numbers.h"
// C++17

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int64_t> t;

// PODZIÊKOWANIA dla PATRYKA PRUSINOWSKIEGO za pomys³ ;)
int64_t fibbonaci_dynamiczny (int64_t n) {
    if (n <= 2) return 1; 
    if (t[n] != -1) return t[n];
    else return t[n] = fibbonaci_dynamiczny(n - 1) + fibbonaci_dynamiczny(n - 2);    
}

int64_t fibbonaci_rekurencyjny(int64_t n) {
    if (n <= 2) return 1;
    return fibbonaci_rekurencyjny(n - 1) + fibbonaci_rekurencyjny(n - 2);
}


void _031() {
    setlocale(LC_ALL, ""); 
	srand(time(0));
    
    int64_t n=0; // >=0
    while (cin.fail() || n <= 0) {        
        cout << "WprowadŸ n: ";
        cin >> n;        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignorujê do koñca co by³o
    }
    
    

    t.resize(n+1, -1);

    auto start = std::chrono::high_resolution_clock::now();   

    cout << fibbonaci_dynamiczny(n) << endl;
    
    auto finish = chrono::high_resolution_clock::now();
    cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " ms\n";

    start = std::chrono::high_resolution_clock::now();
    
    cout << fibbonaci_rekurencyjny(n) << endl;
    
    finish = chrono::high_resolution_clock::now();
    cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " ms\n";
}
