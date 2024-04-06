#include <iostream>
using namespace std;
int main()
{
int const n = 10;
int wiersze, kolumny;
cout << "Program wyswietla tabliczke mnozenia dla liczb od 1 do 100."<< endl;
cout << endl;
for (wiersze = 1; wiersze <= n; wiersze++)
{
for (kolumny = 1; kolumny <= n; kolumny++)
{
cout << wiersze*kolumny << '\t';
}
cout << endl;
}
return 0;
}
