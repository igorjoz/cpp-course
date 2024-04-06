#include <iostream>

using namespace std;

int main()
{
    int wysokosc;
    char znak;

    cout<<"Podaj wysokosc trojkata: ";
    cin>>wysokosc;

    cout<<"Podaj znak z ktorego ma byc zbudowany trojkat: ";
    cin>>znak;

    cout<<endl<<endl;

    for(int i=0; i<(wysokosc-1); i++)
    {
        for(int k=0; k<(wysokosc-i-1); k++)
        {
            cout<<" ";
        }
        for(int l=0; l<(2*i-1); l++)
        {
            cout<<znak;
        }
        cout<<endl;
    }

    cout<<endl<<endl;

    return 0;
}
