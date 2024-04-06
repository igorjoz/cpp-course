#include <iostream>

using namespace std;

int populacja=1;
int t=0;

int main()


{
    while(populacja<=1000000000)
    {
        t++;
        populacja=populacja*2;
        cout<<"Minelo "<<t<<" godzin. ";
        cout<<"Populacja bakterii wynosi: "<<populacja<<"\n";
    }

    return 0;
}
