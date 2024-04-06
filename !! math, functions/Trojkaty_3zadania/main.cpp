#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int const N = 500;

    ifstream input;
    input.open("dane_trojkaty.txt");

    ofstream output;
    output.open("wyniki.txt");

    if (input.good())
    {
        int num[N];
        int num2[N]; // 2.

        for (int i=0; i<N; i++)
        {
            input>>num[i];
            num2[i] = num[i]; // 2.
        }

        // 1.
        output<<"80.1.:\t";
        for (int i=2; i<N; i++)
        {
            if ((num[i-2]*num[i-2] + num[i-1]*num[i-1] == num[i]*num[i]) || (num[i-2]*num[i-2] + num[i]*num[i] == num[i-1]*num[i-1]) || (num[i]*num[i] + num[i-1]*num[i-1] == num[i-2]*num[i-2]))
            {
                cout<<num[i-2]<<", "<<num[i-1]<<", "<<num[i]<<"; ";
                output<<num[i-2]<<", "<<num[i-1]<<", "<<num[i]<<"; ";
            }
        }
        cout<<endl;

        // 2.
        // Sortowanie babelkowe malejace
        for (int i=0; i<N; i++)
        {
            for (int k=1; k<N-i; k++)
            {
                if (num2[k-1] < num2[k])
                {
                    int temp = num2[k-1];
                    num2[k-1] = num2[k];
                    num2[k] = temp;
                }
            }
        }

        bool znaleziono = false;
        int j = 2;
        while (!znaleziono)
        {
            if ((num2[j] + num2[j-1] > num2[j-2]) && (num2[j] + num2[j-2] > num2[j-1]) && (num2[j-2] + num2[j-1] > num2[j]))
            {
                znaleziono = true;
                cout<<num2[j-2]+num2[j-1]+num2[j]<<"; "<<num2[j-2]<<" "<<num2[j-1]<<" "<<num2[j]<<endl;
                output<<endl<<"80.2.:\t"<<num2[j-2]+num2[j-1]+num2[j]<<endl;
            }
            else
            {
                j++;
            }
        }

        // 3.
        int licznik=0;

        for (int i=0; i<N; i++)
        {
            for (int k=i+1; k<N; k++)
            {
                for (int w=k+1; w<N; w++)
                {
                    if ((num[i] + num[k] > num[w]) && (num[i] + num[w] > num[k]) && (num[k] + num[w] > num[i]))
                    {
                        licznik++;
                    }
                }
            }
        }
        cout<<licznik;
        output<<"80.3.:\t"<<licznik;

        output.close();
    }
    else
    {
        cout<<"Problem z plikiem";
    }

    input.close();

    return 0;
}
