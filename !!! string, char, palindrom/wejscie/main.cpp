#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int isInt(char *ptr)
{
    char c;
    while(( c = *ptr++ ) != 0)
    {
        if((c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z' ))
            return 0;
    }
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
        if(buffer[0] == 'q')
            break;
    }
}
