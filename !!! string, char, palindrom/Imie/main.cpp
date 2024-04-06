#include <iostream>
#include <string>

using namespace std;

string imie;

int main()
{
    cout << "Podaj imie: ";
    cin>>imie;

    if (imie.at(imie.length()-1)=='a' || imie.at(imie.length()-1=='A'))
    {
        cout<<"Imie "<<imie<<" jest zenskie.";
    }else cout<<"Imie "<<imie<<" jest meskie.";

    cout<<"\n\n";

    return 0;
}
