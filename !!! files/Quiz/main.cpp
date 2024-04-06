#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

string temat, nick;
string tresc[5];
string odp_a[5], odp_b[5], odp_c[5], odp_d[5];
string poprawna[5];

string odpowiedz;
int punkty=0;

int main()
{
    int nr_linii=1;
    string linia;

    int numer_pytania=0;

    fstream plik;
    plik.open("quiz.txt", ios::in);

    if (plik.good()==false)
    {
        cout<<"Blad opercaji! NIe udalo sie otworzyc pliku.";
        exit(0);
    }

    while (getline(plik, linia))
    {
        switch (nr_linii)
        {
            case 1: temat=linia;                     break;
            case 2: nick=linia;                      break;
            case 3: tresc[numer_pytania]=linia;      break;

            case 4: odp_a[numer_pytania]=linia;      break;
            case 5: odp_b[numer_pytania]=linia;      break;
            case 6: odp_c[numer_pytania]=linia;      break;
            case 7: odp_d[numer_pytania]=linia;      break;
            case 8: poprawna[numer_pytania]=linia;   break;
        }

        if (nr_linii==8)
        {
            nr_linii=2;
            numer_pytania++;
        }

        nr_linii++;
    }

    plik.close();

    for (int i=0; i<=4; i++)
    {
        cout<<endl<<tresc[i]<<endl;
        cout<<"A. "<<odp_a[i]<<endl;
        cout<<"B. "<<odp_b[i]<<endl;
        cout<<"C. "<<odp_c[i]<<endl;
        cout<<"D. "<<odp_d[i]<<endl;

        cout<<"Odpowiedz: ";
        cin>>odpowiedz;

        transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower);

        if (odpowiedz==poprawna[i])
        {
            cout<<"Swietnie! Zdobywasz punkt"<<endl;
            punkty++;
        }
        else cout<<"Zle! Poprawna odpowiedz to: "<<poprawna[i]<<endl;
    }

    cout<<"\n\nPodsumowanie punktow: "<<punkty<<"/5\n\n";

    return 0;
}
