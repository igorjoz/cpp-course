#include <iostream>

using namespace std;

int main()
{
    int a, b, kopia_a, kopia_b;

    cout<<"Podal liczbe a: ";
    cin>>a;
    kopia_a=a;
    cout<<"Podal liczbe b: ";
    cin>>b;
    kopia_b=b;

    while (a!=b)
    {
        if (a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }

    cout<<"NWD("<<kopia_a<<", "<<kopia_b<<") = "<<a;

    cout<<endl<<endl;
    return 0;
}
