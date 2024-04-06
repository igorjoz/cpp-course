#include <iostream>

using namespace std;

int prostokat (int a, int b)
{
    int pprostokata=a*b;
    return pprostokata;
}

int kwadrat (int a)
{
    int pkwadratu=a*a;
    return pkwadratu;
}

int main()
{
    int wybor, x, y;
    cout << "Program obliczajacy pole danej figury\n";
    cout<< "Wpisz 1, jesli chcesz obliczyc pole prostokata lub 2, jesli chcesz obliczyc pole kwadratu\nOdpowiedz: ";
    cin>>wybor;
    cout<<"=================================================================================================\n";

    switch(wybor)
    {
    case 1:
        cout<<"Podaj dlugosc boku a: ";
        cin>>x;
        cout<<"Podaj dlugosc boku b: ";
        cin>>y;
        cout<<"Pole prostokata o boku a="<<x<<" i b="<<y<<" wynosi: "<<prostokat(x, y);
        break;

            case 2:
        cout<<"Podaj dlugosc boku a: ";
        cin>>x;
        cout<<"Pole kwadratu o boku a="<<x<<" wynosi: "<<kwadrat(x);
        break;
    }

    cout<<"\n\n";

    return 0;
}
