#include <iostream>
#include <cstdlib>

using namespace std;

int miesiac, rok;

int main()
{
    cout<<"Program odpowiadajacy ile dni ma dany miesiac\n";
    cout<<"\nWpisz numer miesiaca: ";

    if (!(cin>>miesiac))
    {
        cerr<<"\nTo nie jest liczba!\n\n";
        exit(0);
    }

    cout<<"\n";

    switch(miesiac)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout<<"Miesiac z numerem: "<<miesiac<<" ma 31 dni";
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        cout<<"Miesiac z numerem: "<<miesiac<<" ma 30 dni";

    case 2:
        {
        cout<<"Wpisz obecny rok: ";
        cin>>rok;
        if (((rok%4==0) && (rok%100!=0)) || (rok%400==0))
        {
           cout<<"Miesiac z numerem: "<<miesiac<<" ma 29 dni";
        }
        if (rok%4!=0)
        {
            cout<<"Miesiac z numerem: "<<miesiac<<" ma 28 dni";
        }
        }
        break;
    default: cout<<"Nie ma takiego miesiaca";
    }

    cout<<"\n\n";

    return 0;
}
