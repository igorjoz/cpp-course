/*
#include <iostream>
#include <iomanip>

using namespace std;

long double fibonacci[10000000];
int i, k;
int zlota_liczba;

int main()
{
    cout<<"Program wyznaczajacy ciag fibonacciego oraz zlota liczbe";

    cout<<"\n";
    cout<<"Podaj ile razy ma sie wykonac polecenie dodawania dwoch poprzednich liczb z ciagu fibonacciego: ";
    cin>>k;

    fibonacci[0]=1;
    fibonacci[1]=1;

    cout<<setprecision(10000);

    cout<<"wyraz nr 1: 1";
    cout<<"wyraz nr 2: 1";

    for (i=1; i<k; i++)
    {
        fibonacci[i+2]=fibonacci[i]+fibonacci[i+1];
        cout<<"wyraz nr "<<i<<": "<<fibonacci[i]<<endl;
    }

    zlota_liczba=fibonacci[i-1]/fibonacci[i-2];

    cout<<"\n\n\n";
    cout<<"Zlota liczba wynosi: "<<zlota_liczba;

    return 0;
}
*/

#include <iostream>
#include <iomanip>
using namespace std;

long double fib[100000]; int n;

int main()
{
    cout << "Ile liczb Fibonacciego mam wyznaczyc: ";
    cin>>n;

    fib[0]=1;
    fib[1]=1;

    for (int i=2; i<n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

cout<<setprecision(10000);

    //for (int i=0; i<n; i++)
    //{
    //    cout<<endl<<"wyraz nr"<<i+1<<": "<<fib[i];
    //}

cout<<endl<<"wyraz nr "<<n<<":"<<fib[n-1];

//cout<<"zlota liczba: "<<fib[n-1]/fib[n-2];

    return 0;
}
