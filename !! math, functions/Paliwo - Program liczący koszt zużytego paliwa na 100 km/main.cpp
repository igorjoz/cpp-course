/*

Program licz�cy koszt zu�ytego paliwa na 100 km

*/

#include <iostream>
using namespace std;

float dystans, litry, paliwo, cena, koszt;

int main()
{

    cout<<"Witaj w programie, sluzacym do szybkiego obliczenia kosztu przejechania 100 km twoim samochodem.\n\nZalozenia programu:\nCena litra benzyny to 5.12 z�\nCena litra oleju napedowego to 4.95 z�\nCena litra LPG to 2.21 z�\n\n\n";

    cout<<"Podaj przejechany dystans (w kilometrach): ";
    cin>>dystans;

    cout<<"\nPodaj ile litrow paliwa zuzyles: ";
    cin>>litry;

    cout<<"\n1 - Benzyna\n2 - Olej napedowy\n3 - LPG\n";
    cout<<"Podaj rodzaj paliwa, z ktorego korzystales - wpisz odpowiedni numer: ";
    cin>> paliwo;


    if (paliwo==1)
    {
        cena=5.12;
    }

    if
    (paliwo==2)
    {
        cena=4.95;
    }

    if
    (paliwo==3)
    {
        cena=2.21;
    }

    cout<<"\n";
    (koszt=cena*litry/dystans*100);
    cout<<"Koszt przejechania 100 km twoim samochodem wynosi: ";
    cout<< koszt <<" z�\n\n\n";

    return 0;
}
