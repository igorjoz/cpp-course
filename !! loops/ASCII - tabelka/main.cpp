#include <iostream>

using namespace std;

int i;
char a;

int main()
{
    cout<<"Program wypisujacy wszystkie znaki z ASCII"<<endl;
    for(i=0; i<=255; i++)
    {
        cout<<"|"<<i<<". "<<(char) i<<"\t|";
    }

    return 0;
}
