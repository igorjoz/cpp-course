#include <iostream>
#include <math.h>

using namespace std;

int a, b, c;
float p, s;

int main()
{

    cout<<"Program obliczajacy pole trojkata wzorem Herona";


    cout << "\n\n\nPodaj dlugosc boku a: ";
    cin>>a;

    cout << "\nPodaj dlugosc boku b: ";
    cin>>b;

    cout << "\nPodaj dlugosc boku c: ";
    cin>>c;

    p=((a+b+c)/2);
    s=(sqrt(p*(p-a)*(p-b)*(p-c)));

    cout<<"\n\nPole trojkata o podanych przez Ciebie danych wynosi: " <<s <<"\n\n\n";

    return 0;
}
