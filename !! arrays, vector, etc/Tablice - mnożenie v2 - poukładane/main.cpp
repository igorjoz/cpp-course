#include <iostream>

using namespace std;

int liczby[11][11];

int k, i, o;

int a=1, b=0;

int c=1, d=0;

int main()
{
    for (k=0; k<=10; k++)
    {
        liczby[k][0]=b;
        cout<<liczby[k][0]<<"\t";
        b++;
    }

    for (i=1; i<=10; i++)
    {
        liczby[0][i]=a;
        cout<<"\n"<<liczby[0][i];
        a++;
        c=1;
        d++;

        for (o=1; o<=10; o++)
        {
        liczby[c][d]=liczby[c][0]*liczby[0][d];

        //if (liczby[c][d]<10) cout<<"   ";
        //if (liczby[c][d]<100 && liczby[c][d]>=10) cout<<"  ";
        //if (liczby[c][c]==100) cout<<" ";

        cout<<'\t'<<liczby[c][d];
        c++;
        }
    }

    cout<<"\n\n";
    return 0;
}
