#include <iostream>

using namespace std;

char litera;

int main()
{
    cout<<"Program wypisujacy po kolei duze litery alfabetu\n";
    litera='A';


    /* WERSJA Z WHILE
    while(litera<='Z')
    {
       if (litera<'Z') cout<<litera<<",";
       else cout<<litera<<".";
       litera++;
    }
    */


    /*
    for (litera='A'; litera<'Z'; litera++)
    {
        cout<<litera<<"\n";
    }
    */

    do
    {
        cout<<litera;
        litera++;
    } while (litera<'Z');


    return 0;
}
