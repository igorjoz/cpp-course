#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stack>

using namespace std;

int main()
{
    int const w = 3;
    int tab[w][w];

    srand((unsigned)time(NULL));
    for (int i=0; i<w; i++)
    {
        for (int k=0; k<w; k++)
        {
            tab[i][k] = rand()%5+1;
            cout<<tab[i][k]<<"\t";
        }
        cout<<endl<<endl;
    }

    int pom[w][w];

    // Wyzerowanie tablicy pomocniczej
    for (int y=0; y<w; y++)
    {
        for (int x=0; x<w; x++)
        {
            pom[y][x]=0;
        }
    }

    for (int y=0; y<w; y++)
    {
        for(int x=0; x<w; x++)
        {
            if(x<w-1)
            {
                int nowa = pom[y][x] + tab[y][x+1];
                if(nowa > pom[y][x+1])
                {
                    pom[y][x+1] = nowa;
                }
            }

            if(y < w-1)
            {
                int nowa = pom[y][x] + tab[y+1][x];
                if(nowa > pom[y+1][x])
                {
                    pom[y+1][x] = nowa;
                }
            }
        }
    }
    cout<<pom[w-1][w-1]<<endl;

    return 0;
}
