#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

class Ksztalt
{
public:
    virtual void oblicz_pole() = 0; // Czysta funkcja wirtualna
};

class Kolo :public Ksztalt
{
    float r;

public:
    Kolo(float x)
    {
        r = x;
    }

    virtual void oblicz_pole()
    {
        cout << "Pole kola: " << M_PI * r * r << endl;
    }
};

class Kwadrat :public Ksztalt
{
    float a;

public:
    Kwadrat(float x)
    {
        a = x;
    }

    virtual void oblicz_pole()
    {
        cout << "Pole kwadratu: " << a * a << endl;
    }
};

void obliczenia(Ksztalt* x)
{
    x->oblicz_pole();
}

int main()
{
    Kolo k(1);
    Kwadrat kw(2);

    // wazne!
    Ksztalt* wsk;

    wsk = &k;
    wsk->oblicz_pole();

    wsk = &kw;
    wsk->oblicz_pole();

    obliczenia(wsk);

    return 0;
}