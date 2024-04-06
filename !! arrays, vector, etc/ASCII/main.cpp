#include <iostream>

using namespace std;

char a;
int b;

int main()

{

    cout<<"Zamiana znaku na liczbe\n";
    cout<<"========================================================================\n";
    cout<<"Podaj znak: ";
    cin>> a;
    cout<<"Znak : "<<a<<" ma w tablicy ASCII numer porzadkowy: "<<int(a)<<"\n";
    cout<<"========================================================================\n";
    cout<<"Zamian liczby na znak\n";
    cout<<"========================================================================\n";
    cout<<"Podaj numer porzadkowy znaku (liczbe calkowita)\n";
    cin>>b;
    cout<<"Liczba: "<<b<<" reprezentuje w tablicy ASCII znak: "<<char(b)<<"\n";



    return 0;
}
