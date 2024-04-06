#include <iostream>

using namespace std;

int main()
{
    int pierwsza, druga;

    cout<<"1. liczba: ";
    cin>>pierwsza;
    cout<<"2. liczba: ";
    cin>>druga;

    cout<<endl;

    if (pierwsza<druga) cout<<"Najmniejsza liczba to: "<<pierwsza;
    if (pierwsza>druga) cout<<"Najmniejsza liczba to: "<<druga;
    if (pierwsza==druga) cout<<"Te liczby sa sobie rowne!";

    return 0;
}
