#include <iostream>

using namespace std;

int n;

int f(int n)
{
    if (n==0) return 3;
    else return f (n-1) + 2;
}

int main()
{
    cout<<"Podaj n: ";
    cin>>n;

    cout<<endl<<endl<<"Wynik: "<<f(n);

    return 0;
}
