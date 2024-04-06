#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

int i;

int main()
{
    for (i=10; i>=0; i--)
    {
        Sleep(1000);
        system("cls");
        cout<<i<<endl;
    }
    cout<<"\n\nAAAAAAAAAAAAAAAAAAAAAAA\n\n";
    return 0;
}
