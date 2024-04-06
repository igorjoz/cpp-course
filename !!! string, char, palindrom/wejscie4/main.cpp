#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int isInt(char buffer)
{
    if (!isdigit(buffer)) return 0;
    return 1;
}

int main()
{
    char test;

    cin>>test;

    if (isdigit(test)) cout<<"to jest liczba";
    /*
    char buffer;

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
    */
}
