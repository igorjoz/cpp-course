#include <iostream>
#include <string>

using namespace std;

int main()
{
    int liczba;

    cout<<"Podaj liczbe: ";
    cin>>liczba;

    string napis = "a b c";

    napis = napis + " " + to_string(liczba);

    cout<<napis;

    return 0;
}
