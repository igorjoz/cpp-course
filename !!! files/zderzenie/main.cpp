#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    long double m1, m2, v1, v2, v3;
    string gdzie = "";

    fstream plik;
    plik.open("dane.txt", ios::out);

    if (plik.good())
    {
        // Losowanie liczb
        srand((unsigned)time(NULL));
        int l1 = rand()%18+2;
        int l2 = rand()%98+2;
        int l3 = rand()%9899+101;
        int l4 = rand()%98+2;
        plik<<l1<<" "<<l2<<" "<<l3<<" "<<l4;
    }
    else
    {
        cout<<"Problem z plikiem";
    }
    plik.close();

    plik.open("dane.txt", ios::in);
    if (plik.good())
    {
        plik>>m1>>v1>>m2>>v2;
        //cout<<m1<<"g "<<v1<<"km/h "<<m2<<"g "<<v2<<"km/h"<<endl;

        m1 = m1/1000;
        m2 = m2/1000;

        v1 = v1/3.6;
        v2 = v2/3.6;
        //cout<<m1<<"kg "<<v1<<"m/s "<<m2<<"kg "<<v2<<"m/s"<<endl;

        v3 = (m1*v1-m2*v2)/(m1+m2);

        if (v3<0) gdzie = " LEWO";
        if (v3>0) gdzie = " PRAWO";

        v3 = abs(v3);

        cout<<setprecision(10)<<v3<<gdzie;
    }
    else
    {
        cout<<"Problem z plikiem";
    }
    plik.close();

    return 0;
}
