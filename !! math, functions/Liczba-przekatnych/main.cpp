#include <iostream>

using namespace std;

int boki;

int liczba_przekatnych (int boki)
{
    int przekatne;

    przekatne=(((boki-3) * boki)/ 2);

    return przekatne;
}

int main()
{
    cout<<"Podaj ile bokow ma twoja figura: ";
    cin>>boki;

    cout<<endl<<endl;

    cout<<"Liczba przekatnych w "<<boki<<"-kacie wynosi: "<<liczba_przekatnych(boki);

    cout<<endl<<endl;
    return 0;
}
