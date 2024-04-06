#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int const num = 1000;

    fstream plik;

    plik.open("liczby.txt", ios::in);
    if (plik.good())
    {
        int liczby[num];
        int n_min=1000, n_max=0, naj_sum;
        int powtorzenia[num+1], naj_powtorzenia[2];
        naj_powtorzenia[0]=0;
        int suma_dwucyfrowe=0;
        int cyf1[num], cyf10[num], cyf100[num], suma_cyfr=1; // 1, bo cyfra tysiecy w jedynej liczbie 1000

        // b - wyzerowanie
        for (int i=0; i<num+1; i++)
        {
            powtorzenia[i] = 0;
        }

        for (int i=0; i<num; i++)
        {
            plik>>liczby[i];

            // a
            if (liczby[i] < n_min) n_min = liczby[i];
            if (liczby[i] > n_max) n_max = liczby[i];

            // b
            powtorzenia[liczby[i]]++;

            if (powtorzenia[liczby[i]] > naj_powtorzenia[0])
            {
                naj_powtorzenia[0] = powtorzenia[liczby[i]];
                naj_powtorzenia[1] = liczby[i];
            }

            // c
            if (liczby[i] >= 10 && liczby[i] < 100) suma_dwucyfrowe+=liczby[i];

            // e
            cyf1[i] = liczby[i]%10;
            cyf10[i] = ((liczby[i]%100) - cyf1[i])/10;
            cyf100[i] = ((liczby[i]%1000) - cyf1[i] - cyf10[i]*10)/100;

            suma_cyfr += cyf1[i];
            suma_cyfr += cyf10[i];
            suma_cyfr += cyf100[i];
        }
        // a
        naj_sum = n_min + n_max;

        // d
        int licznik = 1, naj_ciag = 0; // 1, bo trzeba uwzglednic liczbe startowa
        int ile_ciagi=0, naj_ile_ciagi=0;
        for (int i=1; i<num; i++)
        {
            if (liczby[i] > liczby[i-1])
            {
                licznik++;
            }
            else
            {
                licznik = 1;
            }

            if (licznik > naj_ciag)
            {
                naj_ciag = licznik;
                ile_ciagi = 0;
            }

            if (licznik == naj_ciag) ile_ciagi++;
            if (ile_ciagi > naj_ile_ciagi) naj_ile_ciagi = ile_ciagi;
        }


        // Wyniki
        cout<<n_max<<" "<<n_min<<" "<<naj_sum<<endl;
        cout<<naj_powtorzenia[0]<<" "<<naj_powtorzenia[1]<<endl;
        cout<<suma_dwucyfrowe<<endl;
        cout<<naj_ciag<<" "<<naj_ile_ciagi<<endl;
        cout<<suma_cyfr;
    }
    else
    {
        cout<<"Problem z plikiem";
    }

    return 0;
}
