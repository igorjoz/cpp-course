#include <iostream>

using namespace std;

// Program sprawdzajacy poprawnosc numeru PESEL

int main()
{
    int ilosc;

    cin>>ilosc;
// =====================================================================
    double pesel[ilosc];
    string tak_nie[ilosc];

    int cyfry[11][ilosc];
    int cyfry_po_modyfikacji[11][ilosc];

// =====================================================================

    int suma[ilosc];
    // Zerowanie wartosci sumy
    for (int i=0; i<ilosc; i++)
    {
        suma[i]=0;
    }

// =====================================================================

    for (int i=0; i<ilosc; i++)
    {
        cin>>pesel[i];

        double dzielenie=10000000000;

        for (int k=0; k<11; k++)
        {
            cyfry[k][i]=pesel[i]/dzielenie;

            //cout<<endl<<cyfry[k][i];

            pesel[i]=pesel[i]-(cyfry[k][i]*dzielenie);

            dzielenie=dzielenie/10;

            //cout<<endl;
            if (k==0 || k==4 || k==8 || k==10) cyfry_po_modyfikacji[k][i]=cyfry[k][i];
            if (k==1 || k==5 || k==9) cyfry_po_modyfikacji[k][i]=cyfry[k][i]*3;
            if (k==2 || k==6) cyfry_po_modyfikacji[k][i]=cyfry[k][i]*7;
            if (k==3 || k==7) cyfry_po_modyfikacji[k][i]=cyfry[k][i]*9;

            suma[i]+=cyfry_po_modyfikacji[k][i];
            //cout<<endl<<endl<<suma[i];
        }

        while (suma[i]>10)
        {
            int pomocnicza=0;
            pomocnicza=suma[i]/10;

            suma[i]=suma[i]-(pomocnicza*10);
        }

        if (suma[i]==0) tak_nie[i]="D";
        if (suma[i]!=0) tak_nie[i]="N";
    }

// =====================================================================

    for (int i=0; i<ilosc; i++)
    {
        cout<<tak_nie[i]<<endl;
    }

    return 0;
}
