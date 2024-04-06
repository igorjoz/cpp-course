#include <iostream>

using namespace std;

int main()
{
    int i, k;

    for (i=0; i<5; i++)
    {
        for (k=0; k<=i; k++)
        {
            cout<<"O";
        }
        cout<<endl;
    }
    return 0;
}
