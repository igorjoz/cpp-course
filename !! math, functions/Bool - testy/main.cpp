#include <iostream>

using namespace std;

bool sto;
int liczba;

int main()
{
    cout<<"Bool na poczatku: "<<sto<< endl;

    cout<<"Podaj liczbe: ";
    cin>>liczba;

    if (liczba==100) sto=true;

    cout<<"\nBool teraz: "<<sto;
    return 0;
}
