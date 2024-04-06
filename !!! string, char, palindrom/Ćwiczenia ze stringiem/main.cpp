#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string napis;
string napis2;
int dlugosc;

string szukaj;
int pozycja;

int main()
{
    cout<<"Program badajacy wlasciwosci napisu podanego przez uzytkownika\n";

    cout<<"\nPodaj napis: ";
    getline(cin, napis);

    dlugosc=napis.length();
    cout<<"\nDlugosc tego napisu wynosi: "<<dlugosc;

    cout<<"\nPierwsza litera napisu: ";
    cout<<napis[0];

    cout<<"\nOstatnia litera napisu: ";
    cout<<napis[dlugosc-1];

    if (napis[dlugosc-1]=='a') cout<<"\nJest prawdopodobienstwo, ze ten napis to imie zenskie, bo konczy sie na litere \"a\"";

    cout<<"\nNapis \""<<napis<<"\" od tylu to: ";

    for (int i=dlugosc; i>0; i--)
    {
        cout<<napis[i-1];
    }

    cout<<"\n\nPodaj drugi napis: ";
    getline(cin, napis2);

    cout<<"\n\nNapis pierwszy w polaczeniu z drugim to: ";
    cout<<napis+napis2;

    cout<<"\n\nNapis (1) z duzych liter: ";
    transform(napis.begin(), napis.end(), napis.begin(),::toupper);
    cout<<napis;

    cout<<"\nNapis (1) z malych liter: ";
    transform(napis.begin(), napis.end(), napis.begin(),::tolower);
    cout<<napis;

    cout<<"\n\nJaki wyraz chcesz wyszukac w napisie (1): ";
    cin>>szukaj;

    size_t pozycja=napis.find(szukaj);

    if (pozycja!=string::npos)
        cout<<"Znaleziono na pozycji: "<<pozycja;
        else cout<<"Nie znaleziono";

    cout<<"\n\n";
    return 0;
}
