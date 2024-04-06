#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int kat;

    cout<<"Podaj kat: ";
    cin>>kat;

    cout<<"Sinus (sin): "<<sin(kat*M_PI/180.0)<<endl;
    cout<<"Cosinus (cos): "<<cos(kat*M_PI/180.0)<<endl;
    cout<<"Tangens (tg): "<<tan(kat*M_PI/180.0)<<endl;
    cout<<"Cotangens (ctg): "<<1/tan(kat*M_PI/180.0)<<endl<<endl;

    return 0;
}
