#include <iostream>

using namespace std;

int polep(int a, int b)
{
    return a*b;
}

int a, b;

int main()
{
    cout << "Podaj dlugosc boku a: ";
    cin>>a;

    cout<<"\n";

    cout<<"Podaj dlugosc boku b: ";
    cin>>b;

    cout<<"\n\n";

    cout<<"Pole prostokata o pierwszym boku o dlugosci: "<<a<<" i drugim bokiem o dlugosci: "<<b<<" wynosi: "<<polep(a,b);

    cout<<"\n\n";

    return 0;
}
