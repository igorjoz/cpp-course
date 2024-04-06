#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

int i, i1, liczba;

int main()
{
    cout<<"LOTTO\nLosowanie 6 liczb rozpocznie sie za 3 sekund.\n\n";

    for (i1=3; i1>=1; i1--)
    {
        cout<<i1<<"\n\a";
        Sleep(1000);
    }

    cout<<"\n";

    srand(time(NULL));

    for(i=1; i<=6; i++)
    {
           cout<<i<<" liczba: ";
           liczba=rand()%49+1;
           cout<<liczba<<"\n\a";
           Sleep(1000);
    }
    cout<<"\n\n";

    return 0;
}
