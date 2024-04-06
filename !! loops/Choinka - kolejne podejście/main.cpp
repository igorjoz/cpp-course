#include <iostream>

using namespace std;

int i1, i2, i3, i4, i5;
int il_pieter;
char znak;

int main()
{
    cout<<"Programie tworzacy choinke (bez czubka)\n\n";
    cout<<"Podaj ile choinka ma miec pieter: ";
    cin>>il_pieter;
    cout<<"Podaj z jakiego znaku ma sie skladac ta choinka: ";
    cin>>znak;
    cout<<"\n\n";

    for (i1=1; i1<=il_pieter; i1++)
    {
        for (i4=il_pieter; i4>=i1; i4--)
        {
            cout<<" ";
        }
        for (i3=1; i3<=i1; i3++)
        {
        cout<<znak<<znak;
        }
        cout<<"\n";
    }
    for (i5=1; i5<=il_pieter; i5++)
        {
            cout<<" ";
        }
     cout<<"#";

    cout<<"\n\n";
    return 0;
}
