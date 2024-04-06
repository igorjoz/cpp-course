#include <iostream>

using namespace std;

int ile;

char znak;

int main()
{
    cout<<"Ile poziomow ma miec choinka: ";
    cin>>ile;

    cout<<endl<<"Z jakich znakow ma byc choinka?: ";
    cin>>znak;

    cout<<endl<<endl;

    int ilosc_znakow=1;
    int ilosc_spacji=ile;



    for (int i=0; i<ile; i++)
    {
        for (int k=1; k<ilosc_spacji; k++)
        {
            cout<<" ";
        }
        ilosc_spacji--;

        for (int k=0; k<ilosc_znakow; k++)
        {
            cout<<znak<<znak;
        }
        ilosc_znakow++;

        cout<<endl;
    }

    return 0;
}
