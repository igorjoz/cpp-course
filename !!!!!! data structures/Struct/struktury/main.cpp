#include <iostream>
#include <cstdlib>

using namespace std;

struct sdane
{
    int x;
    float y;
    char c;
};

void wyswietl(sdane dane)
{
    cout<<"x = "<<dane.x<<endl;
    cout<<"y = "<<dane.y<<endl;
    cout<<"c = "<<dane.c<<endl;
}

int main()
{
    sdane dane;
    dane.x = 10;
    dane.y = 3.14;
    dane.c = 'a';

    wyswietl(dane);

    return 0;
}
