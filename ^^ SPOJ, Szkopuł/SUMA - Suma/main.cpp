#include <iostream>

using namespace std;

int main()
{
    int suma=0;
    int liczba;

    while (cin>>liczba)
    {
        suma+=liczba;
        cout<<suma<<endl;
    }

    return 0;
}
