#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

float a, b, wynik;
char wybor;

int main()

{
    cout<<"Program wykonujacy proste dzialania matematyczne\n\n";

    for(;;)
    {

    cout<<"Podaj liczbe a: ";
    cin>>a;
    cout<<"Podaj liczbe b: ";
    cin>>b;

    cout<<"\n\nMENU GLOWNE\n";
    cout<<"--------------------";
    cout<<"\nWybierz co chcialbys zrobic:\n";
    cout<<"1: Dodawanie\n";
    cout<<"2: Odejmowanie\n";
    cout<<"3: Mnozenie\n";
    cout<<"4: Dzielenie\n";
    cout<<"5: Wyjscie z programu\n";
    wybor=getch();

    cout<<"\n";

    switch(wybor)
    {

       case '1':
       wynik=a+b;
       cout<<"Suma = "<<wynik;
       break;

       case '2':
        wynik=a-b;
        cout<<"Roznica = "<<wynik;
        break;

        case '3':
        wynik=a*b;
        cout<<"Iloczyn = "<<wynik;
        break;

        case '4':
        if(b==0) cout<<"Nie da sie dzielic przez 0!";
        else
        {
        wynik=a/b;
        cout<<"Iloraz = "<<wynik;
        }
        break;

        case '5':
            exit(0);

        default:
        cout<<"\nTakiej opcji nie ma w menu";
        break;

    }
    getchar();getchar();
    system("cls");
    }

    cout<<"\n\n";

    return 0;
}
