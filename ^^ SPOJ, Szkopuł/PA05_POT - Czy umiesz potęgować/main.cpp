#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    int a, b;
    int wynik;

    int tablica[10][4] =
    {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {6, 2, 4, 8},
        {1, 3, 9, 7},
        {6, 4, 6, 4},
        {5, 5, 5, 5},
        {6, 6, 6, 6},
        {1, 7, 9, 3},
        {6, 8, 4, 2},
        {1, 9, 1, 9}
    };

    cin>>n;

    for (int i=0; i<n; i++)
    {
        cin>>a>>b;
        wynik = tablica[a%10][b%4];

        cout<<wynik<<endl;
    }

    return 0;
}
