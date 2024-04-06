#include <iostream>

using namespace std;

int main()
{
    int n, ilosc;
    int *liczby;

    cin>>n;

    for (int i=0; i<n; i++)
    {
        int suma=0;

        cin>>ilosc;
        liczby = new int [ilosc];

        for (int j=0; j<ilosc; j++)
        {
            cin>>liczby[j];
            suma+=liczby[j];
        }
        cout<<suma<<endl;
    }

    return 0;
}
