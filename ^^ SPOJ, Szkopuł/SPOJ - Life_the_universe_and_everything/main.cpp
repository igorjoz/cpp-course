#include <iostream>

using namespace std;

bool stop=false;
int const g=10000;
int liczba, zaakceptowane[g];
int k=0;

int main()
{
    while (stop==false)
    {
        cin>>liczba;

        if (liczba==42)
        {
            stop=true;
        }
        else
        {
            zaakceptowane[k]=liczba;
            k++;
        }
    }

    for (int i=0; i<k; i++)
    {
        cout<<zaakceptowane[i]<<endl;
    }

    return 0;
}
