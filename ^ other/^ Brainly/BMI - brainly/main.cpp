#include <iostream>

using namespace std;

int main()
{
    float kilogramy, centymetry, metry, BMI;

    cout<<"Podaj swoja wage (kg): ";
    cin>>kilogramy;
    cout<<"Podaj swoj wzrost (w centymetrach): ";
    cin>>centymetry;

    metry = centymetry/100;
    BMI = kilogramy/(metry*metry);

    cout<<endl<<"Twoj wskaznik BMI to: "<<BMI<<endl;

    if (BMI < 18.5) cout<<"Jestes za chudy!";
    if (BMI > 25) cout<<"Jestes za gruby";

    return 0;
}
