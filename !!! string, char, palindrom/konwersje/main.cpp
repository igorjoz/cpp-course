#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "1337";
    string str2 = "1.337";
    string str3 = "13.37";

    int liczba = stoi(str);
    float liczba2 = stof(str2);
    double liczba3 = stod(str3);

    cout<<liczba<<"\t";
    cout<<liczba2<<"\t";
    cout<<liczba3<<"\t";
}
