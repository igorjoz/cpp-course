#include <iostream>

using namespace std;

int main()
{
    int mak;

    for (int i=0; i<5; i++)
    {
        cout<<i<<". ";
        if (cin>>mak)
        {
            cout<<"git";
        }
        else
        {
            cout<<"cos odwalil";
            mak=0;
        }
        //cin>>mak;
    }

    return 0;
}
