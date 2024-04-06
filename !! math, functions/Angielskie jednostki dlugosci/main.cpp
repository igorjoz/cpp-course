#include <iostream>

using namespace std;

float wartosc_wprowadzona;
float metry;

int wybor;
int blad;

void zamiana_na_metry(int wybor, float wartosc_wprowadzona)
{
    if (wybor==1)
    {
        metry=wartosc_wprowadzona;
    }

    if (wybor==2)
    {
        metry=1000*wartosc_wprowadzona;
    }

    if (wybor==3)
    {
        metry=wartosc_wprowadzona/100;
    }
}

float zamiana_na_yardy(float metry)
{
    float yard=metry*0.9144;
    return yard;
}

float zamiana_na_cale(float metry)
{
    float cal=metry*0.0254;
    return cal;
}

float zamiana_na_mile(float metry)
{
    float mila=metry/1609.344;
    return mila;
}

int main()
{
    cout << "Program zamieniajacy dlugosc w metrach, kilometrach lub centymetrach na wartosci w calach, yardach i milach";
    cout<<"\n\n";

    cout<<"Wybierz jaka jednostke chcialbys zamienic\n";
    cout<<"1. Metr\n";
    cout<<"2. Kilometr\n";
    cout<<"3. Centymetr\n";

    cout<<"\nTwoj wybor: ";
    cin>>wybor;

    cout<<"\nWprowadz dlugosc (bedzie ona w zaznaczonej przez Ciebie jednostce): ";
    cin>>wartosc_wprowadzona;

    cout<<"\n\n";

    zamiana_na_metry(wybor, wartosc_wprowadzona);

    cout<<wartosc_wprowadzona;
    if (wybor==1)
    {
      cout<<" metrow to:";
    }
    if (wybor==2)
    {
        cout<<" kilometrow to:";
    }
    if (wybor==3)
    {
        cout<<" centymetrow to:";
    }
    cout<<"\n\n";

    cout<<zamiana_na_cale(metry)<<" cali,\n";
    cout<<zamiana_na_yardy(metry)<<" yardow,\n";
    cout<<zamiana_na_mile(metry)<<" mil";

    cout<<"\n\n";
    return 0;
}
