#include <iostream>

using namespace std;

void wypisz (int &a)
{
    cout<<"a + 5 = "<<a+5;

    a=(a+5)*15;
}

int main()
{
    int a=5;
    cout<<"a = "<<a<<endl<<endl;

    wypisz (a);

    cout<<endl<<endl<<"(a + 5) * 15 = "<<a;

    return 0;
}
