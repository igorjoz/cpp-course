#include <iostream>

using namespace std;

int main()
{
    int wysokosc, kopia_wysokosci;
    char znak;

    cout<<"Program drukujacy pelny trojkat prostokatny o podanej wysokosci"<<endl<<endl;

    cout<<"Podaj wysokosc: ";
    cin>>wysokosc;

    kopia_wysokosci=wysokosc;

    cout<<"Podaj znak: ";
    cin>>znak;

    cout<<endl<<endl;

    for (int i=0; i<wysokosc; i++)
    {
        for (int k=wysokosc; k<=kopia_wysokosci; k++)
        {
            cout<<znak;
        }
        kopia_wysokosci++;
        cout<<endl;
    }

    cout<<endl<<endl;
    return 0;
}
