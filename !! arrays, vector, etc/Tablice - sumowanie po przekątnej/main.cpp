#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stddef.h>

using namespace std;

int main()
{
    int const w_tab=3;

    int w, k, suma1=0, suma2=0;
    int tab[w_tab][w_tab];

    srand((unsigned)time(NULL));

    for (w=0; w<w_tab; w++)
    {
        for (k=0; k<w_tab; k++)
        {
            tab[w][k]=rand()%10;
            cout<<tab[w][k]<<"\t";
        }
        cout<<"\n\n";
    }

    // Pierwsza przekatna
    for (int i=0; i<w_tab; i++)
    {
        suma1+=tab[i][i];
    }
    cout<<"Suma liczb po 1. przekatnej to: "<<suma1<<endl;

    // Druga przekatna
    int p=w_tab-1;
    for (int i=0; i<w_tab; i++)
    {
        suma2+=tab[i][p];
        p-=1;
    }
    cout<<"Suma liczb po 2. przekatnej to: "<<suma2<<endl<<endl;

    // Wiersze
    for (int i=0; i<w_tab; i++)
    {
        int temp1=0;
        int temp2=0;
        for (int j=0; j<w_tab; j++)
        {
            temp1+=tab[i][j];
            temp2+=tab[j][i];
        }
        cout<<i<<". wiersz: "<<temp1<<endl;
        cout<<i<<". kolumna: "<<temp2<<endl;
    }

    cout<<endl;
    return 0;
}
