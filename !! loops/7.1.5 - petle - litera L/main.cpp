#include <iostream>

using namespace std;

int main()
{
    int grubosc, szerokosc, wysokosc;
    char znak;

    cout<<"Program drukujacy litere L o konkretnych wlasciwosciach"<<endl<<endl;

    cout<<"Podaj grubosc: ";
    cin>>grubosc;

    cout<<"Podaj szerokosc: ";
    cin>>szerokosc;

    cout<<"Podaj wysokosc: ";
    cin>>wysokosc;

    cout<<"Podaj znak: ";
    cin>>znak;

    // Pierwsza czesc litery
    for (int i=0; i<(wysokosc-grubosc); i++)
    {
        for (int k=0; k<grubosc; k++)
        {
            cout<<znak;
        }
        cout<<endl;
    }

    // Druga czesc litery
    for (int i=0; i<grubosc; i++)
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
