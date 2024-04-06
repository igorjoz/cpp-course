#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int *primes;
    int n;

    cout<<"n: ";
    cin>>n;

    primes = new int [n+1];

    for (int i=0; i<=n; i++)
    {
        primes[i]=1;
    }

    primes[0]=0;
    primes[1]=0;

    for (int i=2; i<=n; i++)
    {
        if (primes[i]==1)
        {
            for (int j=2; i*j<=n; j++)
            {
                primes[i*j]=0;
            }
        }
    }

    for (int i=0; i<n; i++)
    {
        cout<<i<<": "<<primes[i]<<endl;
    }

    cout<<endl;
    return 0;
}
