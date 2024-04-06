#include <iostream>

using namespace std;

int najmniejsza, najwieksza, i, suma, odpowiedz;

int main()
{
    cout << "Uniwersalny zliczacz liczb ze zbioru liczb parzystych lub nieparzystych lub wszystkich\n\n";
    cout<<"Wpisz najmniejsza liczbe ze zbioru: ";
    cin>>najmniejsza;

    cout<<"Wpisz najwieksza liczbe ze zbioru: ";
    cin>>najwieksza;

    cout<<"\n";

    cout<<"Jesli chcesz aby program obliczyl sume liczb nieparzystych to wpisz 0\nJesli chcesz aby program obliczyl sume liczb parzystych wpisz 1\nJesli chcesz aby program obliczyl sume wszystkich liczb calkowitych z tego przedzialu wpisz 2\nOdpowiedz: ";
    cin>>odpowiedz;

    switch(odpowiedz)
    {
        case 0:
            for(i=najmniejsza; i<=najwieksza; i++)
            {
               if (i%2!=0)
               {
                   suma=suma+i;
               }
            }
            break;

            case 1:
            for(i=najmniejsza; i<=najwieksza; i++)
            {
               if(i%2==0)
               {
                   suma=suma+i;
               }
            }
            break;

            case 2:
            for(i=najmniejsza; i<=najwieksza; i++)
            {
               suma=suma+i;
            }
            break;
    }

    cout<<"\nSuma tego zbioru wynosi: "<<suma<<"\n";

    return 0;
}
