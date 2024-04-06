#include <iostream>

using namespace std;

int main()

{
    char a;
    int b;

    cout<<"Zamiana znaku na liczbe"<<endl;
    cout<<"====================="<<endl;
    cout<<"Podaj znak: ";
    cin>>a;
    cout<<"Znak : "<<a<<" ma w tablicy ASCII numer porzadkowy: "<<(int) a<<endl;
    cout<<"====================="<<endl;

    cout<<"Zamian liczby na znak"<<endl;
    cout<<"====================="<<endl;
    cout<<"Podaj numer porzadkowy znaku (liczbe calkowita)\n";
    cin>>b;
    cout<<"Liczba: "<<b<<" reprezentuje w tablicy ASCII znak: "<<(char) b;

    cout<<endl<<endl;
    return 0;
}
