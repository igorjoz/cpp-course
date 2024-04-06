#include <iostream>

using namespace std;

int a, b;

int main()
{
    cout << "Podaj liczbe a: ";
    cin>>a;
    cout<<"Podaj liczbe b: ";
    cin>>b;

{
    if(a<5) cout<<"\nA jest mniejsze od 5\n";
    if(a>5) cout<<"\nA jest wieksze od 5\n";
    if(a==5) cout<<"\nA jest rowne 5\n";
}
{
    if(b<10) cout<<"\nB jest mniejsze od 10\n";
    if(b>10) cout<<"\nB Jest wieksze od 10\n";
    if(b==10) cout<<"\nB jest rowne 10\n";
}
    return 0;
}
