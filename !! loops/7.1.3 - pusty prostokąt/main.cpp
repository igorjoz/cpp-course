#include <iostream>

using namespace std;

int main()
{
    int wysokosc, szerokosc;

    cout << "Podaj wysokosc: ";
    cin>>wysokosc;

    cout<<"Podaj szerokosc: ";
    cin>>szerokosc;

    for(int i=szerokosc; i>=1; i--)
    {
        cout<<"*";
    }

    cout<<endl;

    for (int i=wysokosc-2; i>=1; i--)
    {
        cout<<"*";
        for(int k=szerokosc-2; k>=1; k--)
        {
            cout<<" ";
        }
        cout<<"*"<<endl;
    }

    for(int i=szerokosc; i>=1; i--)
    {
        cout<<"*";
    }

    return 0;
}
