/*
Program liczacy stosunek ilosci plynu do soczewek do ceny produktu - wersja porownujaca
*/


#include <iostream>

using namespace std;

float objetosc1, cena1, objetosc2, cena2, stosunek1, stosunek2; //objetosc = objetosc plynu do soczewek; cena = cena plynu do soczewek

int main()

{
    cout << "Program obliczajacy stosunek ilosci do ceny plynu soczewek.\nMozna go wykorzystac do porownania dwoch plynow innych marek, badz plynow tej samej marki, lecz w roznych zestawach.\n\n";

    cout<< "Podaj objetosc pierwszego plynu do soczewek w ml: ";
    cin>> objetosc1;

    cout<<"Podaj cene pierwszego produktu (w PLN): ";
    cin>>cena1;

    cout<< "\nPodaj objetosc drugiego plynu do soczewek w ml: ";
    cin>> objetosc2;

    cout<<"Podaj cene drugiego produktu (w PLN): ";
    cin>>cena2;

    cout<< "\nStosunek ilosci do ceny pierwszego produktu wynosi: ";
    stosunek1=objetosc1/cena1;
    cout<<stosunek1;

    cout<< "\nStosunek ilosci do ceny drugiego produktu wynosi: ";
    stosunek2=objetosc2/cena2;
    cout<<stosunek2;

    cout<<"\n\nLepszy stosunek ilosci do ceny ma produkt: ";
    if (stosunek1>stosunek2) cout<<"pierwszy.";
    if (stosunek1<stosunek2) cout<<"drugi.";
    if (stosunek1==stosunek2) cout<<"zaden! Oba maja taki sam stosunek.";

    cout<<"\n\n";
    cout<<"Im wyzszy otrzymujesz wynik, tym lepiej. Oznacza to, ze dostajesz wiecej produktu, za mniejsza cene.\nPamietaj, ze program nie uwzglednia jakosci produktu!\n\n";

    return 0;
}
