#include <iostream>
#include <string>

using namespace std;

string imie, nazwisko, email, numertelefonu;
int dlugosc, i;

int main()
{
    cout << "Program tworzacy uniwersalna wizytowke\n\n";
    cout<<"Podaj swoje imie: ";
    cin>>imie;

    cout<<"\n\n";

        for (i=1; i<=3*(imie.length)(); i++)
    {
        cout<<"*";
    }

    cout<<"\n*";
        for (i=1; i<=3*(imie.length)()-2; i++)
    {
        cout<<" ";
    }
    cout<<"*";

    cout<<"\n*";
        for (i=1; i<=(imie.length)()-1; i++)
    {
        cout<<" ";
    }
    cout<<imie;

        for (i=1; i<=(imie.length)()-1; i++)
    {
        cout<<" ";
    }

    cout<<"*\n";

    cout<<"*";

        for (i=1; i<=3*(imie.length)()-2; i++)
    {
        cout<<" ";
    }

    cout<<"*\n";

        for (i=1; i<=3*(imie.length)(); i++)
    {
        cout<<"*";
    }

    cout<<"\n\n";

return 0;
}
