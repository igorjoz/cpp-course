#include <iostream>
#include <iomanip>

using namespace std;

long double fib[100000];
int n;
int i;

int main()
{
    cout << "Ktora liczbe Fibonacciego chcesz wyznaczyc: ";
    cin>>n;

    fib[0]=1;
    fib[1]=1;

    for (i=2; i<n; i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }

    cout<<setprecision(10000);

    /*
    for (i=0; i<n; i++)
    {
        cout<<"\n"<<"Wyraz numer "<<i+1<<": "<<fib[i];
    }
    */

    cout<<"\nWyraz numer "<<n<<": "<<fib[n-1];

    cout<<"\n\nZlota liczba wynosi: "<<fib[n-1] / fib[n-2];

    cout<<"\n\n";
    return 0;
}
