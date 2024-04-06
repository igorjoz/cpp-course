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


    for (litera='Z'; litera>='A'; litera--)
    {
        cout<<litera<<"\n";
    }



    return 0;
}
