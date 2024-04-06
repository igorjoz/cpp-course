#include <iostream>

using namespace std;

int boki;

int kat;
int suma;

void suma_oraz_kat (int boki)
{
    suma = ((boki - 2) * 180);
    kat = suma / boki;
}

int main()
{
    cout<<"Podaj liczbe bokow w twojej figurze: ";
    cin>>boki;

    cout<<endl<<endl;

    suma_oraz_kat(boki);

    cout<<"Wartosc jednego kata w "<<boki<<"-kacie foremnym wynosi: "<<kat;
    cout<<endl<<"Suma katow wewnetrznych w tej figurze to: "<<suma;

    cout<<endl<<endl;
    return 0;
}
