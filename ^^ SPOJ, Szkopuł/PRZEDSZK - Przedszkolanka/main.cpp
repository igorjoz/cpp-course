#include <iostream>

using namespace std;

int main()
{
    int n, a, b, k, kopia_a, kopia_b, wynik;

    cin>>n;

    for (int i=0; i<n; i++)
    {
        cin>>a>>b;
        kopia_a=a;
        kopia_b=b;

        while (b!=0)
    {
        k=b;
        b=a%b;
        a=k;
    }
    wynik=kopia_a*kopia_b/a;
    cout<<wynik<<endl;
    }

    return 0;
}
