/*
Program liczący stosunek ilości płynu do soczewek do ceny produktu
*/


#include <iostream>

using namespace std;

float objetosc, cena; //objetosc = objetosc plynu do soczewek; cena = cena plynu do soczewek

int main()

{
    cout << "Witaj w programie, dzieki ktoremu bedziesz w stanie szybko obliczyc stosunek ilosci do ceny plynu soczewek.\nMozesz go wykorzystac do porownania dwoch plynow innych marek, badz plynow tej samej marki, lecz innych zestawow.\n\n\n";

    cout<< "Podaj objetosc plynu do soczewek w ml: ";
    cin>> objetosc;

    cout<<"Podaj cene produktu (w PLN): ";
    cin>>cena;

    cout<< "\nStosunek ilosci do ceny tego produktu wynosi: ";
    cout<< objetosc/cena;
    cout<<"\n\n";
    cout<<"Im wyzszy otrzymujesz wynik, tym lepiej. Oznacza to, ze dostajesz wiecej produktu, za mniejsza cene.\nPamietaj, ze program nie uwzglednia jakosci produktu!\n\n";

    return 0;
}
