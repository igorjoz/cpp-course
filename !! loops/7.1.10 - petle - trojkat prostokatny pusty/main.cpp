#include <iostream>

using namespace std;

int main()
{
    int wysokosc, przerwa=0;
    char znak;

    cout<<"Program drukujacy pusty trojkat prostokatny o podanej wysokosci"<<endl<<endl;

    cout<<"Podaj wysokosc: ";
    cin>>wysokosc;

    cout<<"Podaj znak: ";
    cin>>znak;

    cout<<endl<<endl;

    cout<<znak<<endl;

    for (int i=0; i<wysokosc-1; i++)
    {
        cout<<znak;

        for (int k=0; k<przerwa; k++)
        {
            cout<<" ";
        }
        przerwa++;

        cout<<znak<<endl;
    }

    for (int i=0; i<przerwa+2; i++)
    {
        cout<<znak;
    }

    cout<<endl<<endl;
    return 0;
}
