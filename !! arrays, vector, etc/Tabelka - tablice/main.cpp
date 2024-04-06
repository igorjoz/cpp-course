#include <iostream>

using namespace std;

string przedmiot[3];
float oceny[3][3];
float suma[3], srednia[3];
int i, p, m, in, jp;
float il_ocen[3];

int main()
{
    przedmiot[0]="Matematyka";
    przedmiot[1]="Informatyka";
    przedmiot[2]="Jezyk polski";

    oceny[0][0]=3;
    oceny[0][1]=4;
    oceny[0][2]=5;

    oceny[1][0]=5;
    oceny[1][1]=5;
    oceny[1][2]=5;

    oceny[2][0]=2;
    oceny[2][1]=3.75;
    oceny[2][2]=6;

    cout<<"Witaj w eDzienniku drogi Uczniu!\n\n";
    cout<<"Tabela ocen:\n";
    for (i=0; i<=2; i++)
    {
        cout<<przedmiot[p]<<": ";

        if (i==0)
        {
        for (m=0; m<=2; m++)
        {
            cout<<oceny[0][m]<<"; ";
            suma[0]+=oceny[0][m];
        }
            il_ocen[0]=m;
            srednia[0]=suma[0]/il_ocen[0];
            cout<<"\nTwoja srednia z "<<przedmiot[p]<<" wynosi: "<<srednia[0]<<"\n";
        }

        if (i==1)
        {
        for (in=0; in<=2; in++)
        {
            cout<<oceny[1][in]<<"; ";
            suma[1]+=oceny[1][in];
        }
        il_ocen[1]=in;
        srednia[1]=suma[1]/il_ocen[1];
        cout<<"\nTwoja srednia z "<<przedmiot[p]<<" wynosi: "<<srednia[1]<<"\n";
        }

        if (i==2)
        {
        for (jp=0; jp<=2; jp++)
        {
            cout<<oceny[2][jp]<<"; ";
            suma[2]+=oceny[2][jp];
        }
        il_ocen[2]=jp;
        srednia[2]=suma[2]/il_ocen[2];
        cout<<"\nTwoja srednia z "<<przedmiot[p]<<" wynosi: "<<srednia[2]<<"\n";
        }

        p++;
    }

    return 0;
}
