#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

unsigned int a;

int main()
{
    cout<<sizeof(a)<<endl;
    a = pow(2, 32)-1;
    cout<<setprecision(30);
    cout<<a;
    return 0;
}
