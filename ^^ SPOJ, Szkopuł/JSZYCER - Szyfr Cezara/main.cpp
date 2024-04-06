#include <iostream>

using namespace std;

int main()
{
    string linia;

    while (getline(cin,linia))
    {
        for (int i=0; i<linia.length(); i++)
        {
            if (linia[i] >= 'A' && linia[i] <= 'W') linia[i] = linia[i] + 3;
            else if (linia[i] >= 'X' && linia[i] <= 'Z') linia[i] = linia[i] - 26 + 3;

        }
        cout<<linia<<endl;
    }
    return 0;
}
