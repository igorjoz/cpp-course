#include <iostream>
#include <string>

using namespace std;

int main()
{
    string wyraz;

    cout<<"Podaj wyraz: ";
    cin>>wyraz;

    int dlugosc = wyraz.length();

    for (int i=0; i<dlugosc; i++)
    {
        for (int j=1; j<dlugosc-i; j++)
        {
            if (wyraz[j] < wyraz[j-1])
            {
                char temp = wyraz[j];
                wyraz[j] = wyraz[j-1];
                wyraz[j-1] = temp;
            }
        }
    }

    cout<<endl<<wyraz;

    return 0;
}
