#include <iostream>

using namespace std;

int main()
{
    int n, ilosc;
    cin>>n;
    int *liczby;

    for (int i=0; i<n; i++)
    {
        cin>>ilosc;
        liczby = new int [ilosc];

        for (int k=ilosc-1; k>=0; k--)
        {
            cin>>liczby[k];
        }

        for (int k=0; k<ilosc; k++)
        {
            cout<<liczby[k]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
