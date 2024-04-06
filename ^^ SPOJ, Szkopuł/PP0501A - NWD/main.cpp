#include <iostream>

using namespace std;

int k;

int nwd(int a, int b);

int main()
{
    int n, a, b;
    cin>>n;

    for (int i=0; i<n; i++)
    {
        cin>>a>>b;
        cout<<nwd(a, b)<<endl;
    }

    return 0;
}

int nwd(int a, int b)
{
    while (b!=0)
    {
        k=b;
        b=a%b;
        a=k;
    }

    return a;
}
