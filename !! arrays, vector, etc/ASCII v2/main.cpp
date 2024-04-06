#include <iostream>

using namespace std;

int i;
char a;

int main()
{
    cout<<"Program wypisujacy wszystkie znaki z ASCII";
    for(i=0; i<=255; i++)
    {
        if(i<=9 && i>=0)
        {
        cout<<"|"<<i<<". "<<char(i)<<"  |";
        }
        if(i<=99 && i>=10)
        {
        cout<<"|"<<i<<". "<<char(i)<<" |";
        }
        if(i<=255 && i>=100)
        {
        cout<<"|"<<i<<". "<<char(i)<<"|";
        }

    }

    return 0;
}
