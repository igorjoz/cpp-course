#include <iostream>
#include <cmath>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------------------------------------

class Punkt
{
    float x,y;
    string nazwa;

public:

    void wyswietl()
    {
        cout<<nazwa<<"("<<x<<";"<<y<<")"<<endl;
    }

    Punkt(string npunktu="S", float xx=0, float yy=0)
    {
        nazwa=npunktu;
        x=xx;
        y=yy;
    }
};

// ---------------------------------------------------------------------------------------------------------------------------------------------------

class Kolo :public Punkt
{
protected:

    float r;
    string nazwa;

public:

    void wyswietl()
    {
        cout<<"Kolo: "<<nazwa<<endl;
        cout<<"Srodek: ";Punkt::wyswietl();
        cout<<"Promien: "<<r<<endl;
        cout<<"Pole: "<<M_PI*r*r<<endl;
    }

    Kolo(float rr=1, string nkola="Kolo", string npunktu="S", float xx=0, float yy=0)
    :Punkt(npunktu, xx, yy)
    {
        r=rr;
        nazwa=nkola;
    }

};

// ---------------------------------------------------------------------------------------------------------------------------------------------------

class Kula :public Kolo
{
    string nazwa;

public:

    void wyswietl()
    {
        cout<<"Kula: "<<nazwa<<endl;
        cout<<"Promien: "<<r<<endl;
        cout<<"Objetosc: "<<(4.0/3.0)*M_PI*r*r*r<<endl;
    }

    Kula(float rr=1, string nkuli="Kula", string nkola="Kolo", string npunktu="S", float xx=0, float yy=0)
    :Kolo(rr,nkola,npunktu,xx,yy)
    {
        nazwa=nkuli;
    }

};

// ---------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    Punkt p1("Punkcik Igora", 5, 2);
    Kolo k1(12, "Kolo Igora", "O", -20, -5);
    Kula kula1(3, "Kula Igora");

    p1.wyswietl();

    k1.wyswietl();

    kula1.wyswietl();

    return 0;
}