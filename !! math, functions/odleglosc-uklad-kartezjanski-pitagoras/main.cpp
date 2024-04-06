#include <iostream>
#include <cmath>

using namespace std;

float d;

void obl_odleglosci (float x1, float x2, float y1, float y2)
{
    d = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
}

int main()
{
    float x1, x2, y1, y2;

    cout<<"Podaj wspolrzedne 1. punktu:"<<endl;
    cout<<"Os x1: ";
    cin>>x1;
    cout<<"Os y1: ";
    cin>>y1;

    cout<<endl<<"Podaj wspolrzedne 2. punktu:"<<endl;
    cout<<"Os x2: ";
    cin>>x2;
    cout<<"Os y2: ";
    cin>>y2;

    obl_odleglosci (x1, x2, y1, y2);
    cout<<endl<<endl<<"Odleglosc: "<<d<<endl<<sqrt(4);

    return 0;
}
