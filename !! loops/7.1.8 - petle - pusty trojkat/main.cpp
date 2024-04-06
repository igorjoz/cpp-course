#include <iostream>

using namespace std;

int main()
{
    int wysokosc, kopia_wysokosci, przerwa=1;
    char znak;

    cout<<"Program drukujacy pusty trojkat o podanej wysokosci"<<endl<<endl;

    cout<<"Podaj wysokosc: ";
    cin>>wysokosc;

    kopia_wysokosci=wysokosc;

    cout<<"Podaj znak: ";
    cin>>znak;

    cout<<endl<<endl;

    for (int i=0; i<kopia_wysokosci; i++)
    {
        cout<<" ";
    }
    kopia_wysokosci--;
    cout<<znak<<endl;

    for (int i=0; i<wysokosc-1; i++)
    {
        for (int k=0; k<kopia_wysokosci; k++)
        {
            cout<<" ";
        }
        kopia_wysokosci--;

        cout<<znak;

        for (int l=0; l<przerwa; l++)
        {
            cout<<" ";
        }
        przerwa+=2;

        cout<<znak<<endl;
    }

    for (int i=0; i<przerwa+2; i++)
    {
        cout<<znak;
    }

    cout<<endl<<endl;
    return 0;
}
