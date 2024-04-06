#include <iostream>

using namespace std;

int main()
{
    int godzina, minuta;

    cout<<"Podaj godzine: ";
    cin>>godzina;

    cout<<"Podaj minute: ";
    cin>>minuta;

    cout<<endl<<"Godzina podana przez Ciebie: "<<godzina<<":";
    if (minuta<10) cout<<"0"<<minuta;
    else cout<<minuta;

    cout<<endl<<"Godzina po modyfikacji (dodanie 45 minut): ";

    minuta=minuta+45;

    if (minuta>=60)
    {
        godzina++;
        minuta=minuta-60;
    }

    cout<<godzina<<":";
    if (minuta<10) cout<<"0"<<minuta;
    else cout<<minuta;

    cout<<endl<<endl;
    return 0;
}
