#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, dlugosc;
    string *wyrazy;

    cin>>n;
    wyrazy = new string [n];

    for (int i=0; i<n; i++)
    {
        cin>>wyrazy[i];
        dlugosc = wyrazy[i].size();
        wyrazy[i] = wyrazy[i].erase(dlugosc/2, dlugosc/2);
        cout<<wyrazy[i]<<endl;
    }
    return 0;
}
