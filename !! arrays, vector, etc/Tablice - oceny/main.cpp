#include <iostream>

using namespace std;

float ocena[5], srednia, suma;
int i;

int main()
{

    for (i=0; i<=4; i++)
    {
        cout<<"Podaj "<<i+1<<". ocene: ";
        cin>>ocena[i];
        cout<<"\n";
        suma+=ocena[i];
    }


    //if (ocena[0]<1 || ocena[1]<1 || ocena[2]<1 || ocena[3]<1 || ocena[4]<1 || ocena[0]<1)
    //{
    //   cout<<"Takie oceny nie istnieja!";
    //}


    srednia=suma/5;

    cout<<"Twoja srednia wynosi: "<<srednia<<"\n\n";

    return 0;
}
