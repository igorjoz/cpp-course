#include <iostream>

using namespace std;

int main()
{
    int wysokosc;
    int czesc;
    int przerwa=1;

    char znak;

    cout<<"Program drukujacy litere a o okreslonej dlugosci"<<endl<<endl;

    cout<<"Podaj wysokosc: ";
    cin>>wysokosc;

    czesc=(wysokosc-1)/2;

    cout<<"Podaj znak z ktorych ma byc zbudowana litera: ";
    cin>>znak;

    cout<<endl<<endl;

    // Pierwsza litera
    for (int i=0; i<wysokosc; i++)
    {
        cout<<" ";
    }
    cout<<znak<<endl;
    wysokosc--;

    // Pierwsza czesc litery
    for (int i=0; i<czesc; i++)
    {
        for (int k=0; k<wysokosc; k++)
        {
            cout<<" ";
        }
        wysokosc--;

        cout<<znak;

        for (int l=0; l<przerwa; l++)
        {
            cout<<" ";
        }
        przerwa+=2;

        cout<<znak<<endl;
    }
    przerwa+=2;

    // Belka litery
    for (int i=0; i<czesc+1; i++)
    {
        cout<<" ";
    }
    for (int i=0; i<przerwa; i++)
    {
        cout<<znak;
    }
    cout<<endl;

    wysokosc--;

    // Druga czesc litery
    for (int i=0; i<czesc-1; i++)
    {
        for (int k=0; k<wysokosc; k++)
        {
            cout<<" ";
        }
        wysokosc--;

        cout<<znak;

        for (int l=0; l<przerwa; l++)
        {
            cout<<" ";
        }
        przerwa+=2;

        cout<<znak<<endl;
    }

    cout<<endl<<endl;
    return 0;
}
