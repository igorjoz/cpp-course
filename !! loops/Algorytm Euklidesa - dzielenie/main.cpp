#include <iostream>

using namespace std;

int main()
{
    int a, b, k, kopia_a, kopia_b;

    cout<<"Podal liczbe a: ";
    cin>>a;
    kopia_a=a;
    cout<<"Podal liczbe b: ";
    cin>>b;
    kopia_b=b;

    while (b!=0)
    {
        k=b;
        b=a%b;
        a=k;
    }

    cout<<"NWD("<<kopia_a<<", "<<kopia_b<<") = "<<a;

    cout<<endl<<endl;
    return 0;
}
