#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

long double Kn; // kapital po okresach kapitalizacji

void procent_skladany (float K0, float p, int k, int n)
{
    Kn = K0*pow(1+(p/(100*k)), n);
}

int main()
{
     float K0; // kapital poczatkowy
     float p; // ROCZNA stopa procentowa
     int k; // ilosc okresow kapitalizacji w ciagu jednego roku
     int n; // Ilosc okresow kapitalizacji w ciagu trwania calej lokaty

    cout<<"Program obliczajacy procent skladany (wartosc kapitalu)"<<endl<<endl;

    cout<<"Podaj kapital poczatkowy (K0): ";
    cin>>K0;

    cout<<"Podaj roczna stope procentowa (p): ";
    cin>>p;

    cout<<"Podaj ilosc okresow w ciagu jednego roku (k): ";
    cin>>k;

    cout<<"Podaj ilosc okresow kapitalizacji w ciagu trwania calej lokaty (n): ";
    cin>>n;

    procent_skladany (K0, p, k, n);

    cout<<endl<<"Kapital po okresach kapitalizacji wynosi: "<<Kn<<endl<<endl;

    cout<<"Nacisnij ENTER przycisk aby zakonczyc program";
    getchar();getchar();

    return 0;
}
