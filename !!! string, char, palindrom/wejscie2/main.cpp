#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int isInt(char *ptr)
{
    char c;
    while
    (c = *ptr++) if (!isdigit(c)) return 0;
    return 1;
}

int main()
{
    char buffer[100];

    while(1)
    {
        cout<<"Wpisz"<<endl;
        cin>>buffer;
        if(isInt(buffer))
        {
            cout<<"To jest liczba"<<endl<<atoi(buffer)<<endl;
        }
        if(buffer[0] == 'q') break;
    }
}
