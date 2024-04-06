/*
Program dla Jasia (æwiczenia).
Program licz¹cy iloœæ cukierków dla ka¿dego kolegi i ile zostanie dla Ciebie.
*/

#include <iostream>

using namespace std;

int uczniowie, cukierki, x, y; //x - liczba cukierków, które otrzyma ka¿dy uczeñ; y - liczba cukierków pozosta³ych dla Jasia

int main()
{

    cout<<"Jas poprosil mnie w dniu swoich imienin o stworzenie dla niego programu, \nktory policzlyby, po ile cukierkow musi dac kazdemu koledze w szkole, aby bylo sprawiedliwie. \nPowiedzial tez, ze chcialby od razu wiedziec ile zostanie mu dla siebie.\n\nProgram ten po wprowadzeniu odpowiednich danych obliczy:\n1. Ile cukierkow powinienes dac kazdemu koledze.\n2. Ile cukierkow zostanie dla Ciebie.\n\n\n\n";

    cout<<"Liczba uczniow w klasie (wlacznie z Toba): ";
    cin>> uczniowie;
    cout<<"Liczba cukierkow, ktore posidasz: ";
    cin>> cukierki;

    cout<<"\n";

    x=cukierki/(uczniowie-1);
    cout<<"Liczba cukierkow, dla kazdego ucznia (bez Ciebie): " <<x;

    cout<<"\n\n";

    y=cukierki-(x*(uczniowie-1));
    cout<<"Liczba cukierkow pozostalych dla Ciebie: " <<y;

    cout<<"\n\n";

    return 0;
}
