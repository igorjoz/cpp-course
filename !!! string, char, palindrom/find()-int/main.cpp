#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    int * it = find(a, a + 8, 4);
    cout<<"element przed 4 to "<<*( it - 1 )<<endl;

    return 0;
}
