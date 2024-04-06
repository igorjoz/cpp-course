#include <iostream>
#include <math.h>

using namespace std;

int a, b, c;
float x0, x1, x2, delta;

int main()
{
    cout << "Podaj a: ";
    cin>> a;

    cout<<"\n";

    cout<<"Podaj b: ";
    cin>>b;

    cout<<"\n";

    cout<<"Podaj c: ";
    cin>>c;

    delta=b*b-4*a*c;

    cout<<"\nWartosc delty wynosi: "<<delta;

    cout<<"\n\n";

    if (a!=0)
    {

       if (delta>0)
       {
           x1=(-b-sqrt(delta))/2*a;
           x2=(-b+sqrt(delta))/2*a;
           cout<<"Sa dwia rozwiazania:\nx1 wynosi: "<<x1<<"\nx2 wynosi: "<<x2<<".";
       }
       if (delta==0)
       {
           x0=(-b)/2*a;
           cout<<"Rozwiazanie to: x = "<<x0<<".";
       }

       if (delta<0)
       {
           cout<<"Dla danych podanych przez Ciebie nie ma rozwiazana (delta jest ujemna).";
       }
   } else cout<<"Dla podanych przez Ciebie danych nie ma rozwiazania (a wynosi 0, a przez 0 nie mozna dzielic).";

    cout<<"\n\n\n";

    return 0;
}
