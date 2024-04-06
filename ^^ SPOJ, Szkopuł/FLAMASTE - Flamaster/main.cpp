#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;

    for (int i=0; i<n; i++)
    {
        string napis;
        cin>>napis;

        int licznik = 1;
        int dlugosc = napis.length();

        for (int k=0; k<dlugosc; k++)
        {
            if (napis[k] == napis[k+1])
            {
                licznik++;
            }
            else
            {
                if (licznik == 1)
                {
                    cout<<napis[k];
                }
                else if (licznik == 2)
                {
                    cout<<napis[k]<<napis[k];
                }
                else
                {
                    cout<<napis[k]<<licznik;
                }

                licznik = 1;
            }
        }
        cout<<endl;
    }

    return 0;
}
