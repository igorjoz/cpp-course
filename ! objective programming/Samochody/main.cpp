#include <iostream>

using namespace std;

class Samochod
{
    public:

    string marka;
    string model;
    int rocznik;
    float przebieg;

    void wczytaj ()
    {
        cout<<"Wprowadzanie nowego samochodu:"<<endl;

        cout<<"Podaj marke: ";
        cin>>marka;

        cout<<"Podaj model: ";
        cin>>model;

        cout<<"Podaj rocznik: ";
        cin>>rocznik;

        cout<<"Podaj przebieg: ";
        cin>>przebieg;
    }

    void wypisz ()
    {
        cout<<marka<<" "<<model<<", "<<rocznik<<"; "<<przebieg<<" km"<<endl;
    }
};

int main()
{
    Samochod s1;
    Samochod s2;

    s1.wczytaj();
    s2.wczytaj();

    s1.wypisz();
    s2.wypisz();

    cout<<endl<<endl;
    return 0;
}
