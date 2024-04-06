#include <iostream>

using namespace std;

int main()
{
    int n;
    int liczba;
    bool czy_pierwsza;

    cin >> n;

    for (int k = 0; k < n; k++)
    {
        czy_pierwsza = true;
        cin >> liczba;

        if (liczba == 1) czy_pierwsza = false;
        else if (liczba == 2) czy_pierwsza = true;
        else
        {
            for (int i = 2; i < liczba; i++)
            {
                if (liczba % i == 0) czy_pierwsza = false;
            }
        }
        if (czy_pierwsza == true)
        {
            cout << "TAK";
        }
        if (czy_pierwsza == false)
        {
            cout << "NIE";
        }
        cout << endl;
    }

    return 0;
}
