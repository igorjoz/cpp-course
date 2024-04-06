#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float liczba;

    cout<<"Rozne rodzaje zaokraglania:"<<endl<<endl;

    cout<<"Podaj liczbe: ";
    cin>>liczba;

    cout<<endl<<"round(x): "<<round(liczba)<<endl;
    cout<<"ceil(x): "<<ceil(liczba)<<endl;
    cout<<"floor(x): "<<floor(liczba)<<endl;
    cout<<"trunc(x): "<<trunc(liczba)<<endl<<endl;

    return 0;
}
