#include <iostream>
#include <cmath>

using namespace std;

int const poprawna=100;
int roznica_a, roznica_b;
string blizej;

void najblizsza (int poprawna, int a, int b)
{
    roznica_a = abs(poprawna - a);
    roznica_b = abs(poprawna - b);
    if (roznica_a<roznica_b) blizej = 'a';
    else if (roznica_b<roznica_a) blizej = 'b';
    else if (roznica_a==roznica_b) blizej = "a i b sa tak samo blisko poprawnej odpowiedzi";
}

int main()
{
    int a, b;

    cout<<"Podaj a: ";
    cin>>a;
    cout<<"Podaj b: ";
    cin>>b;

    cout<<endl<<"Poprawna odpowiedz: "<<poprawna<<endl;

    najblizsza(poprawna, a, b);

    cout<<"Blizej wyniku byla odpowiedz: "<<blizej<<endl<<endl;
    return 0;
}
