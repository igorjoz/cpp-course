#include <iostream>

using namespace std;
int katy, sumakatow, boki;

int main()
{

    cout << "Witaj w programie, ktory odpowie Ci o jakiej figurze geometrycznej myslisz\nTa wersja programu rozpoznaje: kwadrat, prostokat, trojkat i kolo.\n\n";
    cout<<"Czy figura o ktorej myslisz ma jakies katy?\nWpisz 0 jesli to nieprawda lub 1 jesli to prawda: ";
    cin>>katy;

    {
    if (katy==0) cout<<"\nFigura o ktorej myslisz to kolo\n";

    else
    cout<<"\nCzy suma stopni katow figury, o ktorej myslisz wynosi 180?\nWpisz 0 jesli to nieprawda lub 1 jesli to prawda: ";
    cin>>sumakatow;
    if (sumakatow==1) cout<<"Figura o ktorej myslisz to trojkat\n";

    else
    cout<<"\nCzy boki tej figury maja jednakowa dlugosc?\nWpisz 0 jesli to nieprawda lub 1 jesli to prawda: ";
    cin>>boki;
    if (boki==0) cout<<"Figura o ktorej myslisz to prostokat";
    if (boki==1) cout<<"\nFigura o ktorej myslisz to kwadrat (ktory rowniez jest prostokatem)\n\n";
    }

    return 0;
}
