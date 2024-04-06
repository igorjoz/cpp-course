/* Uniwersalny zliczacz liczb parzystych */

#include <iostream>

using namespace std;

int najmniejsza, najwieksza, i, suma, przedzial;

int main()
{
    cout<<"Program zliczajacy liczby parzyste z dowolnego przedzialu\n\n";

    cout << "Podaj najmniejsza liczbe ze zbioru: ";
    cin>>najmniejsza;

    cout<<"Podaj najwieksza liczbe ze zbioru: ";
    cin>>najwieksza;

    for(i=najmniejsza; i<=najwieksza; i++)
    {
        if (i%2==0) suma=suma+i;
    }
    cout<<"\nSuma liczba parzystych z przedzialu " <<najmniejsza <<" do "<<najwieksza<<" wynosi: " <<suma<<"\n";

    return 0;
}
