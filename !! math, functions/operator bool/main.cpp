#include <iostream>

using namespace std;

bool pies;
string odpowiedz;

int main()
{
    cout << "Czy mas psa?\nOdpowiedz (tak lub nie): ";
    cin>>odpowiedz;

    if (odpowiedz=="tak" || odpowiedz=="Tak" ||odpowiedz=="TAK")
    {
        pies=true;
    }

    if (pies==true)
    {
        cout<<"\nMasz psa!\n";
    }

    if (pies==false)
    {
        cout<<"\nNie masz psa!\n";
    }

    return 0;
}
