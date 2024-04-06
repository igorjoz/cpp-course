#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int a, b, c;
float z, x, v;

int main()
{
    srand((unsigned)time(NULL));

    a=rand()%1000;
    b=rand()%100;
    c=rand()%10;

    cout <<a<<endl<<b<<endl<<c;

    return 0;
}
