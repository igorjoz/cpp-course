#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int const maks = 999;
    int n, *l;

    ifstream plik;
    plik.open("dane.txt");
    if (plik.good())
    {
        plik>>n;
        l = new int [n];

        for (int i=0; i<n; i++)
        {
            plik>>l[i];
        }

        // 1. zad.
        cout<<"Zad. 1.: Znajdz najmniejsza mozliwa sume:\n";
        int najm[3];
        najm[0] = l[0];
        najm[1] = l[0];
        najm[2] = l[0];
        for (int i=1; i<n; i++)
        {
            if (l[i] < najm[0])
                najm[0] = l[i];
        }
        for (int i=1; i<n; i++)
        {
            if (l[i] < najm[1] && l[i] != najm[0])
                najm[1] = l[i];
        }
        for (int i=1; i<n; i++)
        {
            if ((l[i] < najm[2]) && (l[i] != najm[0]) && (l[i] != najm[1]))
                najm[2] = l[i];
        }
        cout<<"Najmniejsza suma w calym zbiorze: "<<najm[0] + najm[1] + najm[2]<<"\nNajmniejsze liczby w calym zbiorze: "<<najm[0]<<", "<<najm[1]<<", "<<najm[2];

        // 2. zad.
        cout<<"\n\nZad. 2.:\nKolejne trojki, ktore tworza ciag malejacy:\n";
        for (int i=2; i<n; i++)
        {
            if ((l[i-2]>l[i-1]) && (l[i-1]>l[i]))
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 3. zad.
        cout<<"\n\nZad. 3.:\nTrojki kolejnych liczb, gdzie liczba w srodku jest podzielna przez liczbe po jej lewej i prawej:\n";
        for (int i=2; i<n; i++)
        {
            if ((l[i-1]%l[i-2] == 0) && (l[i-1]%l[i]) == 0)
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 4. zad.
        cout<<"\n\nZad. 4.:\nTrojki kolejnych liczb, ktore tworza ciag geometryczny:\n";
        for (int i=2; i<n; i++)
        {
            if ((float)l[i-2]/l[i-1] == (float)l[i-1]/l[i])
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 5. zad.
        cout<<"\n\nZad. 5.:\nTrojki kolejnych liczb, ktore tworza ciag arytmetyczny:\n";
        for (int i=2; i<n; i++)
        {
            if (l[i-2]-l[i-1] == l[i-1]-l[i])
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 6. zad.
        cout<<"\n\nZad. 6.:\nTrojki kolejnych liczb, gdzie trzeci element jest podzielny przez sume dwoch pierwszych:\n";
        for (int i=2; i<n; i++)
        {
            if (l[i]%(l[i-2]+l[i-1]) == 0)
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 7. zad.
        cout<<"\n\nZad. 7.:\nTrojki kolejnych liczb, gdzie wszystkie trzy elementy sa podzielne przez te sama liczbe rozna od 1 (w nawiasach jest podana pierwsza znaleziona liczba, ktora spelnia warunek):\n";
        for (int i=2; i<n; i++)
        {
            for (int j=2; j<maks; j++)
            {
                if ((l[i-2]%j == 0) && (l[i-1]%j == 0) && (l[i]%j == 0))
                {
                    cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<" ("<<j<<");  ";
                    j=maks;
                }
            }
        }

        // 8. zad.
        cout<<"\n\nZad. 8.:\nTrojki kolejnych liczb, gdzie suma dowolnych dwoch elementow jest rowna trzeciemu elementowi:\n";
        for (int i=2; i<n; i++)
        {
            if ((l[i-2]+l[i-1] == l[i]) || (l[i-2]+l[i] == l[i-1]) || (l[i-1]+l[i] == l[i-2]))
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 9. zad.
        bool wzgl_p;
        cout<<"\n\nZad. 9.:\nTrojki kolejnych liczb, gdzie wszystkie trzy elementy sa wzgledem siebie pierwsze:\n";
        for (int i=2; i<n; i++)
        {
            wzgl_p = true;
            for (int j=2; j<maks; j++)
            {
                if ((l[i-2]%j == 0) && (l[i-1]%j == 0) && (l[i]%j == 0))
                {
                    wzgl_p = false;
                }
                if (!wzgl_p)
                    j = maks;
            }
            if (wzgl_p)
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 10. zad.
        cout<<"\n\nZad. 10.:\nTrojki kolejnych liczb, gdzie dowolny element jest podzielny przez sume pozostalych dwoch:\n";
        for (int i=2; i<n; i++)
        {
            if (((l[i-2]%(l[i-1]+l[i]))==0) || ((l[i-1]%(l[i-2]+l[i]))==0) || ((l[i]%(l[i-2]+l[i-1]))==0))
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 11. zad.
        cout<<"\n\nZad. 11.:\nTrojki kolejnych liczb, ktore sa liczbami pitagorejskimi:\n";
        for (int i=2; i<n; i++)
        {
            if ((l[i-2]*l[i-2]+l[i-1]*l[i-1] == l[i]*l[i]) || (l[i-2]*l[i-2]+l[i]*l[i] == l[i-1]*l[i-1]) || (l[i-1]*l[i-1]+l[i]*l[i] == l[i-2]*l[i-2]))
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 12. zad.
        cout<<"\n\nZad. 12.:\nTrojki kolejnych liczb, ktorych suma = 6k+1, k nalezy do naturlanych; (suma - 1 = 6k):\n";
        for (int i=2; i<n; i++)
        {
            if ((l[i-2]+l[i-1]+l[i]-1) % 6 == 0)
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 13. zad.
        cout<<"\n\nZad. 13.: Znajdz najwieksza mozliwa sume:\n";
        int najw[3];
        najw[0] = l[0];
        najw[1] = l[0];
        najw[2] = l[0];
        for (int i=1; i<n; i++)
        {
            if (l[i] > najm[0])
                najm[0] = l[i];
        }
        for (int i=1; i<n; i++)
        {
            if (l[i] > najm[1] && l[i] != najm[0])
                najm[1] = l[i];
        }
        for (int i=1; i<n; i++)
        {
            if ((l[i] > najm[2]) && (l[i] != najm[0]) && (l[i] != najm[1]))
                najm[2] = l[i];
        }
        cout<<"Najwieksza suma w calym zbiorze: "<<najm[0] + najm[1] + najm[2]<<"\nNajwieksze liczby w calym zbiorze: "<<najm[0]<<", "<<najm[1]<<", "<<najm[2];

        // 14. zad.
        cout<<"\n\nZad. 14.:\nTrojki kolejnych liczb, ktore sa kolejno: parzysta, nieparzysta, parzysta:\n";
        for (int i=2; i<n; i++)
        {
            if ((l[i-2]%2 == 0) && (l[i-1]%2 == 1) && (l[i]%2 == 0))
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 15. zad.
        cout<<"\n\nZad. 15.:\nTrojki kolejnych liczb, gdzie trzecia liczba jest najwieksza i nie dzieli sie przez dwie pierwsze; zalozenie: w przypadku typu 3, 5, 5 liczba trzecia nie jest uznawana za najwieksza:\n";
        for (int i=2; i<n; i++)
        {
            if ((l[i]>l[i-2]) && (l[i]>l[i-1]) && (l[i]%l[i-2] != 0) && (l[i]%l[i-1] != 0))
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 16. zad.
        cout<<"\n\nZad. 16.:\nTrojki kolejnych liczb, gdzie trzecia liczba jest odlegloscia na osi liczbowej liczby pierwszej od drugiej:\n";
        for (int i=2; i<n; i++)
        {
            if (l[i] == abs(l[i-2]-l[i-1]))
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 17. zad.
        cout<<"\n\nZad. 17.:\nTrojki kolejnych liczb, gdzie trzy elementy NIE sa wzgledem siebie pierwsze:\n";
        for (int i=2; i<n; i++)
        {
            wzgl_p = true;
            for (int j=2; j<maks; j++)
            {
                if ((l[i-2]%j == 0) && (l[i-1]%j == 0) && (l[i]%j == 0))
                {
                    wzgl_p = false;
                }
                if (!wzgl_p)
                    j = maks;
            }
            if (!wzgl_p)
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 18. zad.
        cout<<"\n\nZad. 18.:\nTrojki kolejnych liczb, ktore tworza ciag Fibonacciego:\n";
        int const f = 16;
        int fib[f];
        fib[0] = 1;
        fib[1] = 1;
        for (int i=2; i<f; i++)
        {
            fib[i] = fib[i-2] + fib[i-1];
        }

        for (int i=2; i<n; i++)
        {
            for (int j=2; j<f; j++)
            {
                if ((l[i-2] == fib[j-2]) && (l[i-1] == fib[j-1]) && (l[i] == fib[j]))
                {
                    cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
                    j=f;
                }
            }
        }

        // 19. zad.
        cout<<"\n\nZad. 19.:\nTrojki kolejnych liczb, ktorych suma kwadratow jest liczba nieparzysta:\n";
        for (int i=2; i<n; i++)
        {
            if ((l[i-2]*l[i-2]+l[i-1]*l[i-1]+l[i]*l[i]) % 2 == 1)
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 20. zad.
        cout<<"\n\nZad. 20.:\nTrojki kolejnych liczb, ktorych iloczyn jest podzielny przez ich sume:\n";
        for (int i=2; i<n; i++)
        {
            if ((l[i-2]*l[i-1]*l[i]) % (l[i-2]+l[i-1]+l[i]) == 0)
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 21. zad.
        cout<<"\n\nZad. 21.:\nTrojki kolejnych liczb, ktorych suma >=40 i suma <=60:\n";
        for (int i=2; i<n; i++)
        {
            if ((l[i-2]+l[i-1]+l[i]) >= 40 && (l[i-2]+l[i-1]+l[i]) <= 60)
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 22. zad.
        cout<<"\n\nZad. 22.:\nTrojki kolejnych liczb, ktorych suma ma jako przedostatnia cyfre 7 (w nawiasie jest suma tych liczb):\n";
        for (int i=2; i<n; i++)
        {
            if (((((l[i-2]+l[i-1]+l[i]) % 100) - ((l[i-2]+l[i-1]+l[i]) % 10))/10) == 7)
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<" ("<<(l[i-2]+l[i-1]+l[i])<<")"<<";  ";
            }
        }

        // 23. zad.
        cout<<"\n\nZad. 23.:\nTrojki kolejnych liczb, ktore sa uporzadkowane malejaco i nie roznia sie od siebie wiecej niz o 10:\n";
        for (int i=2; i<n; i++)
        {
            if ((l[i-2]>l[i-1]) && (l[i-1]>l[i]) && (abs((l[i-2]-l[i-1]))<=10) && (abs((l[i-1]-l[i]))<=10))
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 24. zad.
        cout<<"\n\nZad. 24.:\nTrojki kolejnych liczb, ktorych ostatnie cyfry sa rozne i naleza do zbioru {1,2,3}:\n";
        int c1, c2, c3;
        for (int i=2; i<n; i++)
        {
            c1 = (l[i-2]%10);
            c2 = (l[i-1]%10);
            c3 = (l[i]%10);
            if (c1!=c2 && c1!=c3 && c2!=c3 && (c1==1 || c1==2 || c1==3) && (c2==1 || c2==2 || c2==3) && (c3==1 || c3==2 || c3==3))
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }

        // 25. zad.
        cout<<"\n\nZad. 25.:\nTrojki kolejnych liczb, ktorych ostatnie cyfry tworza ciag rosnacy:\n";
        for (int i=2; i<n; i++)
        {
            c1 = (l[i-2]%10);
            c2 = (l[i-1]%10);
            c3 = (l[i]%10);
            if (c1<c2 && c2<c3)
            {
                cout<<l[i-2]<<", "<<l[i-1]<<", "<<l[i]<<";  ";
            }
        }
    }
    else
    {
        cout<<"Problem z plikiem";
    }
    plik.close();

    cout<<endl;
    return 0;
}
