#include <iostream>

using namespace std;

int main()
{
    int i=0;
    int j;

    while (i!=5)
    {
        j=i+1;
        while (j>0)
        {
            cout<<"O";
            j--;
        }
        cout<<endl;
        i++;
    }

    return 0;
}
