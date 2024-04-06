#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string linia;
    bool znacznik;

    while (getline (cin,linia))
    {
        for (int i=0; i<linia.length(); i++)
        {
            if (linia[i] == '>') znacznik = false;
            else if (znacznik == true) linia[i] = toupper(linia[i]);
            else if (linia[i] == '<') znacznik = true;
        }
        cout<<linia<<endl;
    }
    return 0;
}
