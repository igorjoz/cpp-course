#include <iostream>

using namespace std;

int main()
{
    int wysokosc, szerokosc;
    char znak;

    cout<<"Program drukujacy prostokat o podanej wysokosci i szerokosci"<<endl<<endl;

    cout<<"Podaj wysokosc prostokata: ";
    cin>>wysokosc;

    cout<<"Podaj szerokosc prostokata: ";
    cin>>szerokosc;

    cout<<"Podaj znak, z ktorego ma byc zbudowany prostokat: ";
    cin>>znak;

    cout<<endl<<endl;

    for (int i=0; i<wysokosc; i++)
    {
        for (int k=0; k<szerokosc; k++)
        {
            cout<<znak;
        }
        cout<<endl;
    }

    cout<<endl<<endl;
    return 0;
}
